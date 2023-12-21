#pragma once

#include "Scenes/SceneGameAbstract.h"

class ScenesTest : public SceneGameAbstract 
{
public:
	ScenesTest(const std::string& _newName);
	~ScenesTest();

	void Awake() override;
	void Preload() override;

	void Collinding();

	void Create() override;
	void Delete() override;
	void Physics(const float& _delta) override;
	void Update(const float& _delta) override;
	void Render(sf::RenderWindow* _window) override;

private:
	GameObject* tileMap = nullptr;
};

