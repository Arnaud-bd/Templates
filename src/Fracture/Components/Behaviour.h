#pragma once
#include "Component.hpp"

class Collider;

class Behaviour : public Component
{
public:

	Behaviour();
	virtual ~Behaviour() = default;

	virtual void Update(float _deltaTime) = 0;
	virtual void OnCollideEnter(Collider* _other) = 0;
};

