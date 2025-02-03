#pragma once
#include "Component.hpp"

class Behaviour : public Component
{
public:
	Behaviour();

	virtual void Update(float _deltaTime) = 0;
};

