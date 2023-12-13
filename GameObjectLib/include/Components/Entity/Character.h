#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Components/Entity.h"

class Character: public Entity
{
public:
	enum Direction { Left, Right };
	Character();
	Character(int _hp, int _damage,const float& _speed, const float& _attackSpeed, const float& _range);
	void Update(const float& _delta);
	void SetDirection(Direction _newDirection);
	Direction GetDirection() const { return direction; }
	bool GetIsCenter() const{ return direction; }
	void SetCenterCamera(const bool& _state) { centerCameraOnPlayer = _state; }

	private:
		Direction direction;
		bool directionCharacter;
		sf::CircleShape shape;
		std::vector<sf::CircleShape> bullets;
		std::vector<float> angles;
		bool centerCameraOnPlayer = true;
		
};

