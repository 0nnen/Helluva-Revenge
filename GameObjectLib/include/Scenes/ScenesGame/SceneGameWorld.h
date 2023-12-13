#pragma once

#include "Scenes/SceneGameAbstract.h"
#include "Managers/SceneManager.h"
#include "Managers/AssetManager.h"
#include <Managers/WindowManager.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>


class SceneGameWorld : public SceneGameAbstract
{
public:
	SceneGameWorld(const std::string& _newName);

	void Preload() override;
	void Create() override;
	void Delete() override;

	void CreatePlatformCollision();

	void Render(sf::RenderWindow* _window) override;
	void Update(const float& _delta) override;

private:
	sf::VertexArray triangle;
	GameObject* backButton = nullptr;
	GameObject* creditsButton = nullptr;

	std::vector<GameObject*> platformCarreCollision;
	std::vector<GameObject*> platformTriangleCollision;
	GameObject* plateform = nullptr;

};