#include "Scenes/SceneGameAbstract.h"

#include "Managers/SceneManager.h"
#include "Managers/AssetManager.h"
#include "Managers/WindowManager.h"

#include "Components/UIElements/Button.h"
#include "Components/Shapes/Carre.h"
#include "Components/SpriteRenderer.h"
#include "Components/HealthPointBar.h"

#include "BuilderGameObject.h"
#include "BuildersGameObject/BuilderEntityGameObject.h"
#include <Scenes/SceneGameWorld.h>


SceneGameAbstract::SceneGameAbstract(const std::string& _newName) : Scene(_newName)
{
	this->Awake();
	srand(time(nullptr));
	isPause = true;
}


SceneGameAbstract::~SceneGameAbstract() 
{
	this->Delete();
}

void SceneGameAbstract::Create() 
{
	Scene::Create();
	this->CreatePauseMenuButtons();
}

void SceneGameAbstract::Preload()
{
	Scene::Preload();

	AssetManager::AddAsset("BackgroundAbstract", "../Assets/bgMenu.png");
	AssetManager::AddAsset("idleCharacter", "../Assets/Character/Idle/Character_Idle_48x48.png");
	AssetManager::AddAsset("Character", "../Assets/Character/Idle/images/Idle_01.png");
	AssetManager::AddAsset("jumpCharacter", "../Assets/Character/Jump/Character_Jump_48x48.png");
	AssetManager::AddAsset("runCharacter", "../Assets/Character/Run/Character_Run_48x48.png");
	AssetManager::AddAsset("shootArm", "../Assets/Character/Shoot/Arm/Character_Shoot_Idle_Arm_48x48.png");
	AssetManager::AddAsset("shootBody", "../Assets/Character/Shoot/Body/Character_Shoot_Idle_Body_48x48.png");
	AssetManager::AddAsset("bullet", "../Assets/bullet.png");
}


void SceneGameAbstract::Delete() 
{
	Scene::Delete();
}

void SceneGameAbstract::CreateBackground()
{
	GameObject* background1 = BuilderGameObject::CreateBackgroundGameObject("Background1", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, 1.0f, 1.0f, AssetManager::GetAsset("BackgroundAbstract"));
};

void SceneGameAbstract::CreatePauseMenuButtons() 
{
	pausePlayButton = BuilderGameObject::CreateButtonGameObject("Continue", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 4.0, 25);
	pauseMenuPrincipalButton = BuilderGameObject::CreateButtonGameObject("Menu Principal", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2.5, 15);
	//pauseOptionsButton = BuilderGameObject::CreateButtonGameObject("Options", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 1.8, 50);
	pauseQuitButton = BuilderGameObject::CreateButtonGameObject("Quit", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 1.8, 40);
	this->ManageDefaultButtonsPause(false);
}


void SceneGameAbstract::CreateChartacter()
{
	player = BuilderEntityGameObject::CreateCharacterGameObject("Player", 100, 600, AssetManager::GetAsset("Character"), 7.f, 7.f);
}

void SceneGameAbstract::CreateSceneBackgroundOption() {
	backgroundAlpha1.backgroundAlpha.setSize(sf::Vector2f(WindowManager::GetFloatWindowWidth(), WindowManager::GetFloatWindowHeight()));
	backgroundAlpha1.backgroundAlpha.setOrigin(sf::Vector2f(WindowManager::GetFloatWindowWidth() / 2, WindowManager::GetFloatWindowHeight() / 2));
	backgroundAlpha1.backgroundAlpha.setFillColor(sf::Color(0, 0, 0, 112));	
	backgroundAlpha1.backgroundAlpha.setPosition(WindowManager::GetFloatWindowWidth() / 2, WindowManager::GetFloatWindowHeight() / 2);
	backgroundAlpha2.backgroundAlpha.setSize(sf::Vector2f(WindowManager::GetFloatWindowWidth(), WindowManager::GetFloatWindowHeight()));
	backgroundAlpha2.backgroundAlpha.setOrigin(sf::Vector2f(WindowManager::GetFloatWindowWidth() / 2, WindowManager::GetFloatWindowHeight() / 2));
	backgroundAlpha2.backgroundAlpha.setFillColor(sf::Color::Transparent);
	backgroundAlpha2.backgroundAlpha.setPosition(WindowManager::GetFloatWindowWidth() / 2, WindowManager::GetFloatWindowHeight() / 2);

}

void SceneGameAbstract::Pause()
{
	isPause = !isPause;
	this->pausePlayButton->SetActive(!isPause);
	this->pausePlayButton->SetVisible(!isPause);
	this->pauseMenuPrincipalButton->SetActive(!isPause);
	this->pauseMenuPrincipalButton->SetVisible(!isPause);
	this->pauseQuitButton->SetActive(!isPause);
	this->pauseQuitButton->SetVisible(!isPause);
}

void SceneGameAbstract::Awake() 
{
	Scene::Awake();
}

void SceneGameAbstract::ManageDefaultButtonsPause(bool _state)
{
	this->pauseMenuPrincipalButton->SetVisible(_state);
	this->pauseMenuPrincipalButton->SetActive(_state);
	this->pausePlayButton->SetVisible(_state);
	this->pausePlayButton->SetActive(_state);
	//this->pauseOptionsButton->SetActive(_state);
	this->pauseQuitButton->SetVisible(_state);
	this->pauseQuitButton->SetActive(_state);
}

//void SceneGameAbstract::ManagePause()
//{
//	this->ManageSceneGameButtonsPause(!isPause);
//	for (GameObject* enemy : this->enemies)
//	{
//		enemy->SetActive(isPause);
//	}
//}

void SceneGameAbstract::Update(const float& _delta)
{
	//this->ManagePause();
	if (isPause)
	{
		Scene::Update(_delta);
	}
	else
	{
		if (pausePlayButton->GetComponent<Button>()->IsClicked())
		{
			//this->ManagePause();
			isPause = true;
			this->ManageDefaultButtonsPause(false);
		}
		else if (pauseMenuPrincipalButton->GetComponent<Button>()->IsClicked()) 
		{
			//this->ManagePause();
			isPause = true;
			SceneManager::RunScene("SceneMainMenu");
		}
		//else if (pauseOptionsButton->GetComponent<Button>()->IsClicked()) 
		//{
		//	std::cout << "Options" << std::endl;
		//}
		else if (pauseQuitButton->GetComponent<Button>()->IsClicked()) 
		{
			WindowManager::GetWindow()->close();
		}

	}
}

void SceneGameAbstract::Render(sf::RenderWindow* _window) 
{
	Scene::Render(_window);
}
