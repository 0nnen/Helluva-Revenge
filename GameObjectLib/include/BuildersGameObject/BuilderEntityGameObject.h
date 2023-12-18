#pragma once
#include "GameObject.h"
#include "Components/ComponentsGame/Weapon.h"
class BuilderEntityGameObject
{
public:
	static GameObject* CreateMapGameObject(const std::string& _name, const std::string& _jsonFile, const std::string& _tilesetName);

	static GameObject* CreateBulletGameObject(const std::string& _name, sf::Texture* _textureBullet, GameObject* _player, const float& _scalex, const float& _scaley, const float& _damage, const float& _speed, const Maths::Vector2f& _direction, const float& _rotate,const Maths::Vector2f& _position);
	static GameObject* CreateWeaponGameObject(const std::string& _name, GameObject* _player, const Weapon::TypeWeapon& _typeWeapon, const float& _positionX, const float& _positionY, const float& _damage, const float& _range, const float& _attackSpeed);
	static GameObject* CreateCharacterGameObject(const std::string& _name, const float& _x, const float& _y, sf::Texture* texture, const float& scalex, const float& scaley);

	static GameObject* CreatePlatformCollisionGameObject(const std::string& _name, const float& _positionX, const float& _positionY, const float& scalex, const float& scaley);
	static GameObject* CreatePlatformTriangleCollisionGameObject(const std::string& _name, const float& _base, const float& _height, const float& _widthPos, const float& _heightPos, const float& _rotation);

	static GameObject* CreatePlateformGameObject(const std::string& _name, const float& _positionX, const float& _positionY, const float& scalex, const float& scaley);
	static GameObject* CreateEnemyAGameObject(const std::string& name, float _x, float _y, float scalex, float scaley, sf::Texture* _texture);

	static GameObject* CreateHadesGameObject(const std::string& name, float _x, float _y, float scalex, float scaley, sf::Texture* _texture);
	static GameObject* CreateProtectionBallGameObject(const std::string& name, float _x, float _y, float scalex, float scaley, sf::Texture* _texture, const int& _number, GameObject* _hades);
	static GameObject* CreateProtectionGameObject(const std::string& name, float _x, float _y, float scalex, float scaley, sf::Texture* _texture);
	static GameObject* CreateFireBallEnemy(const std::string& _name, sf::Texture* _textureBullet, GameObject* _enemy, const float& _scalex, const float& _scaley, const float& _damage, const float& _speed, const Maths::Vector2f& _position);
	static GameObject* CreateProtectionBallAstralGameObject(const std::string& name, float _x, float _y, float scalex, float scaley, sf::Texture* _texture, const int& _number, GameObject* _hades);
};

