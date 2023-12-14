#include "Scenes/ScenesGame/SceneGameWorld.h"
#include "BuilderGameObject.h"

#include "BuildersGameObject/BuilderEntityGameObject.h"
#include "Components/Entity/Character.h"
#include "Components/Entity/Enemy/EnemyA.h"


SceneGameWorld::SceneGameWorld(const std::string& _newName) : SceneGameAbstract(_newName) {}

void SceneGameWorld::Preload()
{
	SceneGameAbstract::Preload();
	AssetManager::AddAsset("BackgroundMapBackgroundWorld", "../Assets/Graphics/Maps/worldMapBackground.png");
	AssetManager::AddAsset("BackgroundMapWorld", "../Assets/Graphics/Maps/worldMap1.png");
	AssetManager::AddAsset("idleEnemyA", "../Assets/Enemy/Hell-Beast-Files/PNG/with-stroke/hell-beast-idle.png");
	AssetManager::AddAsset("shootEnemyA", "../Assets/Enemy/Hell-Beast-Files/PNG/with-stroke/hell-beast-breath.png");
	AssetManager::AddAsset("shootEnemyA", "../Assets/Enemy/Hell-Beast-Files/PNG/with-stroke/hell-beast-breath.png");
	AssetManager::AddAsset("FireBallEnemy", "../Assets/Enemy/Hell-Beast-Files/PNG/fire-ball.png");
}

void SceneGameWorld::Create()
{
	SceneGameAbstract::Create();
	CreatePlayer();
	CreateEnemy();
	//GameObject* backgroundWorldMap = BuilderGameObject::CreateBackgroundGameObject("BackgroundMapWorld1", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, AssetManager::GetAsset("BackgroundMapBackgroundWorld"));
	//GameObject* backgroundWorldMap2 = BuilderGameObject::CreateBackgroundGameObject("BackgroundMapWorld2", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, AssetManager::GetAsset("BackgroundMapWorld"));
	plateform = BuilderEntityGameObject::CreatePlateformGameObject("plateform", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 1.2, 5, 2);
	this->CreatePlatformCollision();
}

void SceneGameWorld::CreatePlatformCollision()
{
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform1", 10, 782, 1.4f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform2", 215, 834, 0.15f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform3", 235, 910, 0.70f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform4", 166, 870, 0.1f, 1.1f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform5", 320, 885, 0.15f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform6", 345, 858, 0.15f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform7", 370, 831, 0.15f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform8", 510, 806, 1.3f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform9", 842, 935, 0.76f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform10", 1050, 860, 0.50f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform11", 1304, 870, 1.27f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform12", 1497, 950, 0.65f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform13", 1742, 870, 1.8f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform14", 754, 744, 0.64f, 0.96f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform15", 907, 744, 0.63f, 1.95f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform16", 1125, 655, 0.88f, 1.47f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform16", 1010, 680, 0.27f, 0.47f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform17", 1187, 900, 0.1f, 1.25f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform18", 1421, 910, 0.1f, 1.30f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform19", 1571, 910, 0.1f, 1.30f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform20", 1725, 757, 0.13f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform21", 1778, 705, 0.13f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform22", 1675, 807, 0.38f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform23", 1868, 693, 0.50f, 1.0f));

	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle1", 7.9f, 7.9f, 1045, 608, 90));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle2", 7.7f, 7.7f, 1360, 715, 90));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle3", 7.7f, 7.7f, 1310, 853, 180));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle4", 7.7f, 7.7f, 1312, 700, 180));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle5", 7.7f, 7.7f, 1157, 905, 180));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle6", 7.7f, 7.7f, 1192, 940, 180));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle7", 7.7f, 7.7f, 785, 940, 180));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle8", 7.7f, 7.7f, 737, 895, 180));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle9", 7.5f, 7.5f, 692, 850, 180));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle10", 7.9f, 7.9f, 214, 833, 180));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle11", 7.7f, 7.7f, 965, 879, 90));
	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle12", 7.7f, 7.7f, 1006, 840, 90));
}

void SceneGameWorld::CreateEnemy()
{
	enemy = BuilderEntityGameObject::CreateEnemyAGameObject("EnemyA", WindowManager::GetWindowWidth() / 2, 40.f, 7.f, 7.f, AssetManager::GetAsset("idleEnemyA"));
}

void SceneGameWorld::CreateRengeEnemy()
{
	//rengePosition = BuilderEntityGameObject::CreatePlateformGameObject("RengePosition", enemy->GetPosition().GetX(), enemy->GetPosition().GetY(), 8.f, 5.f);
	rengeProjectil = BuilderEntityGameObject::CreatePlateformGameObject("RengeProjectil", enemy->GetPosition().GetX(), enemy->GetPosition().GetY(), 4.f, 5.f);
}

void SceneGameWorld::Delete()
{
	Scene::Delete();
}

void SceneGameWorld::Render(sf::RenderWindow* _window)
{
	Scene::Render(_window);
	_window->draw(isPause ? backgroundAlpha2.backgroundAlpha : backgroundAlpha1.backgroundAlpha);
}

void SceneGameWorld::CollisionRenge(const float& _delta) {
	EnemyA* enemyA = enemy->GetComponent<EnemyA>();
	RigidBody2D* rigidBody2D = enemy->GetComponent<RigidBody2D>();
	if (player && rengePosition)
	{
		if (RigidBody2D::IsLeft(*(player->GetComponent<RigidBody2D>()), *(rengePosition->GetComponent<RigidBody2D>())))
		{
			if (rigidBody2D->GetVelocity().GetX() > -enemyA->GetMaxSpeed()) rigidBody2D->AddForces(Maths::Vector2f::Right * _delta * enemyA->GetSpeed());
		}
		else if (!RigidBody2D::IsRight(*(player->GetComponent<RigidBody2D>()), *(rengePosition->GetComponent<RigidBody2D>())))
		{
			if (rigidBody2D->GetVelocity().GetX() > -enemyA->GetMaxSpeed()) rigidBody2D->AddForces(Maths::Vector2f::Left * _delta * enemyA->GetSpeed());
		}
	}


	else if (player && rengeProjectil)
	{
		if (RigidBody2D::IsLeft(*(player->GetComponent<RigidBody2D>()), *(rengeProjectil->GetComponent<RigidBody2D>())))
		{
			bulletEnemy = BuilderEntityGameObject::CreateFireBallEnemy("fireBallEnemy", AssetManager::GetAsset("FireBallEnemy"), enemy, 2.f, 1.f, 15.f, 2.f, Maths::Vector2f(100.f, -20.f));
			if (!enemyA->GetAnimation("shoot")->GetIsPlaying()) {
				if (enemyA->GetActualAnimation()) enemyA->GetActualAnimation()->Stop();
				if (enemyA->GetAndSetAnimation("idle")) enemyA->GetAndSetAnimation("idle")->Stop();
				enemyA->GetAndSetAnimation("shoot")->Play();
			}
		}
		/*else if (!RigidBody2D::IsRight(*(player->GetComponent<RigidBody2D>()), *(rengePosition->GetComponent<RigidBody2D>())))
		{
			if (!enemyA->GetAnimation("shoot")->GetIsPlaying())
			{
				if (enemyA->GetActualAnimation()) enemyA->GetActualAnimation()->Stop();
				if (enemyA->GetAndSetAnimation("idle")) enemyA->GetAndSetAnimation("idle")->Stop();
				enemyA->GetAndSetAnimation("shoot")->Play();
			}
		}*/
		/*else
		{
			enemyA->GetAndSetAnimation("idle")->Play();
		}*/
	}
}

void SceneGameWorld::Collision(GameObject* _entity)
{
	if (_entity && plateform)
	{
		if (RigidBody2D::IsColliding(*(_entity->GetComponent<RigidBody2D>()), *(plateform->GetComponent<RigidBody2D>())))
		{
			_entity->GetComponent<RigidBody2D>()->SetIsGravity(false);
			_entity->GetComponent<Entity>()->SetOnFloor(true);
			firstCollide = false;
		}
		else if (!RigidBody2D::IsColliding(*(_entity->GetComponent<RigidBody2D>()), *(plateform->GetComponent<RigidBody2D>())))
		{
			firstCollide = true;
			_entity->GetComponent<RigidBody2D>()->SetIsGravity(true);
			_entity->GetComponent<Entity>()->SetOnFloor(false);
		}
	}
}

//void SceneGameWorld::ClearBullet() 
//{
//	bulletEnemy.clear();
//}

void SceneGameWorld::Update(const float& _delta)
{
	SceneGameAbstract::Update(_delta);
	CreateRengeEnemy();
	Collision(player);
	Collision(enemy);
	CollisionRenge(_delta);
	
}