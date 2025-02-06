#pragma once
#include "Component.hpp"
#include "../Components/Collider.h"

class Behaviour : public Component
{
public:
	Behaviour();

	virtual void Update(float _deltaTime) = 0;
	virtual void OnCollideEnter(Collider* _other) = 0;
};

