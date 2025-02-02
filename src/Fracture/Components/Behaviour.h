#pragma once
#include "Component.hpp"

class Behaviour : public Component
{
public:

	virtual void Update(float _deltaTime) = 0;
	//Elle doit permettre à ses enfants de pouvoir intéragir facilement avec les autres components de l'entité ??

};

