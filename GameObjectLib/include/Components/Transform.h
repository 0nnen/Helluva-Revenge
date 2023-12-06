#pragma once

#include <iostream>
#include "Maths/Vector2.h"
class Transform final
{
public: 
	// M�thode pour r�cup�rer et d�finir la position
	inline Maths::Vector2f GetPosition() const { return position; }
	inline void SetPosition(const float& _x, const float& _y) { position = Maths::Vector2f(_x, _y); }
	inline void SetPosition(const Maths::Vector2f& _position) { position = _position; }

	// M�thode pour r�cup�rer et d�finir la rotation en utilisant un angle
	inline float GetRotation() const { return rotation; }
	inline void SetRotation(float angle) { rotation = angle; }

	// M�thode pour r�cup�rer et d�finir l'�chelle
	inline Maths::Vector2f GetScale() const { return scale; }
	inline void SetScale(const float& _scaleX, const float& _scaleY) { scale = Maths::Vector2f(_scaleX, _scaleY); }
	inline void SetScale(const Maths::Vector2f& _scale) { scale = _scale; }

	// M�thode pour afficher les propri�t�s du Transform
	void Display();

private:
	Maths::Vector2f position = Maths::Vector2f::Zero;
	Maths::Vector2f scale = Maths::Vector2f::One;
	float rotation = 0.f;
};

