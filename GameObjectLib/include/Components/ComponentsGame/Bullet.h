#pragma once

#include "Component.h"
#include "Components/Animation.h"

class Bullet : public Component
{
public:
	void Update(const float& _delta) override;
	inline void SetDamage(const float& _damage) { damage = _damage; }
	inline float GetDamage() const { return damage; }

	inline void SetReductionFactor(const float& _reductionFactor) { reductionFactor = _reductionFactor; }
	inline float GetReductionFactor() const { return reductionFactor; }

	inline void SetSpeed(const float& _speed) { speed = _speed; }
	inline float GetSpeed() const { return speed; }

	inline void SetInitialPosition(const Maths::Vector2f& _initialPosition) { initialPosition = _initialPosition; }

	float GetDamageReduced() const;
	float GetDamageReduced(Maths::Vector2f& _currentPosition) const;

	void AddAnimation(const std::string& _name, Animation* animation);
	Animation* GetAnimation(const std::string& _name);
	Animation* GetAndSetAnimation(const std::string& _name);
	inline Animation* GetActualAnimation() const { return actualAnimation; }
	inline void SetActualAnimation(Animation* animation) { actualAnimation = animation; }

private:
	float damage = 20.f;
	float reductionFactor = 0.01f;
	float speed = 330.f;
	Maths::Vector2f initialPosition = Maths::Vector2f::Zero;
	std::map<std::string, Animation*> animations;
	Animation* actualAnimation = nullptr;
};

