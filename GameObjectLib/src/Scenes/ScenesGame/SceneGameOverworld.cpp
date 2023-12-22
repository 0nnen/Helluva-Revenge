#include "Scenes/ScenesGame/SceneGameOverworld.h"
#include "Components/Entity/Character.h"
#include "BuilderGameObject.h"
#include "Managers/CameraManager.h"
#include "Managers/AssetManager.h"
#include "Managers/WindowManager.h"
#include "Managers/SceneManager.h"

#include "BuildersGameObject/BuilderEntityGameObject.h"
#include "BuildersGameObject/BuilderShapeGameObject.h"

#include "Components/RigidBody2D.h"
#include "TileMap/TileMap.h"

SceneGameOverworld::SceneGameOverworld(const std::string& _newName) : SceneGameAbstract(_newName) {
}

SceneGameOverworld::~SceneGameOverworld() {}

void SceneGameOverworld::Awake()
{
	SceneGameAbstract::Awake();
}

void SceneGameOverworld::Delete()
{
	SceneGameAbstract::Delete();
}

void SceneGameOverworld::Preload()
{
	SceneGameAbstract::Preload();
	AssetManager::AddAsset("BackgroundSceneGame1", "Assets/Graphics/Backgrounds/SceneGame/backgroundSky.jpg");
}

void SceneGameOverworld::Create()
{
	CameraManager::DefaultZoom();
	SceneGameAbstract::Create();
	backgrounds.push_back(BuilderGameObject::CreateBackgroundGameObject("BackgroundSceneGame1", 0, 0, 7.0f, 3.0f, AssetManager::GetAsset("BackgroundSceneGame1"), 0, 0.f));
	tileMap = BuilderEntityGameObject::CreateMapGameObject("OverWorld", "Assets/Graphics/Maps/WorldMap/WorldMap.json", "Assets/Graphics/Maps/WorldMap/worldMapBackground.png", 89);

	CreatePlayer(500,1400);
	CameraManager::SetZoom(1.75f);
}

void SceneGameOverworld::Collinding()
{
	if (player && tileMap)
	{

		RigidBody2D* rigidBody2DPlayer = player->GetComponent<RigidBody2D>();
		Character* character = player->GetComponent<Character>();
		std::vector<SquareCollider*> squareColliders = player->GetComponentsByType<SquareCollider>();
		SquareCollider* squareCollider = squareColliders[0];
		SquareCollider* squareColliderGround = squareColliders[1];
		SquareCollider* detectedSquare = nullptr;
		if (!squareColliderGround->GetActiveCollider())
		{
			if (detectedSquare = tileMap->GetComponent<TileMap>()->CheckCollisionAbove(*squareCollider))
			{
				character->SetOnFloor(true);
				rigidBody2DPlayer->SetIsGravity(false);
				const float distanceY = std::abs(squareCollider->GetCenterY() - detectedSquare->GetCenterY());
				const float height = squareCollider->GetHeightCollider() / 2.f + detectedSquare->GetHeightCollider() / 2.f;
				const float difference = height - distanceY;
				player->SetPosition(player->GetPosition() - Maths::Vector2f(0.f, difference));
				squareColliderGround->SetActiveCollider(true);
				squareCollider->SetActiveCollider(false);
			}
			else
			{
				character->SetOnFloor(false);
				rigidBody2DPlayer->SetIsGravity(true);
			}
		}
		else if (squareColliderGround->GetActiveCollider())
		{
			detectedSquare = tileMap->GetComponent<TileMap>()->CheckCollisionAbove(*squareColliderGround);
			if (!detectedSquare)
			{
				squareColliderGround->SetActiveCollider(false);
				squareCollider->SetActiveCollider(true);
				rigidBody2DPlayer->SetIsGravity(true);
				character->SetOnFloor(false);


			}
		}
		if (detectedSquare = tileMap->GetComponent<TileMap>()->CheckCollisionBelow(*squareCollider))
		{
			const float distanceY = std::abs(squareCollider->GetCenterY() - detectedSquare->GetCenterY());
			const float height = squareCollider->GetHeightCollider() / 2 + detectedSquare->GetHeightCollider() / 2;
			const float difference = height - distanceY;
			player->SetPosition(player->GetPosition() + Maths::Vector2f(0, difference));
			rigidBody2DPlayer->SetVelocity(Maths::Vector2f(rigidBody2DPlayer->GetVelocity().x, 0));
		}
		if (detectedSquare = tileMap->GetComponent<TileMap>()->CheckCollisionLeft(*squareCollider))
		{
			const float distanceX = std::abs(squareCollider->GetCenterX() - detectedSquare->GetCenterX());
			const float width = squareCollider->GetWidthCollider() / 2 + detectedSquare->GetWidthCollider() / 2;
			const float difference = width - distanceX;
			player->SetPosition(player->GetPosition() - Maths::Vector2f(difference, 0));
			rigidBody2DPlayer->SetVelocity(Maths::Vector2f(0, rigidBody2DPlayer->GetVelocity().y));

		}
		if (detectedSquare = tileMap->GetComponent<TileMap>()->CheckCollisionRight(*squareCollider))
		{
			const float distanceX = std::abs(squareCollider->GetCenterX() - detectedSquare->GetCenterX());
			const float width = squareCollider->GetWidthCollider() / 2 + detectedSquare->GetWidthCollider() / 2;
			const float difference = width - distanceX;
			player->SetPosition(player->GetPosition() + Maths::Vector2f(difference, 0));
			rigidBody2DPlayer->SetVelocity(Maths::Vector2f(0, rigidBody2DPlayer->GetVelocity().y));
		}
	}
}


void SceneGameOverworld::Physics(const float& _delta)
{
	SceneGameAbstract::Physics(_delta);
	this->Collinding();
}

void SceneGameOverworld::Update(const float& _delta)
{
	SceneGameAbstract::Update(_delta);
	if (!isPause)
	{
		if (player->GetPosition().y >= 1600.f)
		{
			Character* character = player->GetComponent<Character>();
			if (character->GetIsCenter())
			{
				character->SetCenterCamera(false);
			}
		}
		if (player->GetPosition().y >= 9000.f)
		{
			player->SetPosition(Maths::Vector2f(500.f, 1400.f));
			Character* character = player->GetComponent<Character>();
			if (!character->GetIsCenter())
			{
				character->SetCenterCamera(true);
			}
		}
		if (player->GetPosition().x >= 210.f * 32.f)
		{

			player->GetComponent<RigidBody2D>()->SetVelocity(Maths::Vector2f::Zero);

			this->Pause(true);
			SceneManager::RunScene("SceneGameBossRoom");
		}
	}

}

void SceneGameOverworld::Render(sf::RenderWindow* _window)
{
	SceneGameAbstract::Render(_window);
}
