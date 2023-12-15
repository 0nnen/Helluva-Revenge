#include "Components/Entity/Enemy/EnemyA.h"
#include "Managers/SceneManager.h"
#include "Scenes/ScenesGame/SceneGameWorld.h"
#include "BuildersGameObject/BuilderEntityGameObject.h"

float EnemyA::cooldown;
float EnemyA::fireRate;
GameObject* EnemyA::bulletEnemy;

EnemyA::EnemyA() : Entity()
{
	directionEnemy = false;
	direction = Direction::Right;
	cooldown = 0.f;
	fireRate = 150.f;
}

void EnemyA::Update(const float& _delta) 
{
	Entity::Update(_delta);

	if (SceneGameWorld::GetFlip())
	{
		
		SetDirection(Left);
		directionEnemy = true;
	}
	if (!SceneGameWorld::GetFlip())
	{
		
		SetDirection(Right);
		directionEnemy = false;
	}
	

}


void EnemyA::Attack(float _x, float _y)
{
	GameObject* enemy = SceneManager::GetActiveGameScene()->GetEnemy();
	if(cooldown <= 0)
	{
		cooldown = fireRate;
		bulletEnemy = BuilderEntityGameObject::CreateFireBallEnemy("fireBallEnemy", AssetManager::GetAsset("FireBallEnemy"), enemy, 2.f, 1.f, 15.f, 15.f, Maths::Vector2f(_x, _y));
	}
	cooldown--;
}