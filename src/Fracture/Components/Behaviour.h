#pragma once
#include "Component.hpp"

class Behaviour : public Component
{
public:

	virtual void Update() = 0;
};

