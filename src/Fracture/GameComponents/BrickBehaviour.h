#pragma once
#include "../Components/Transform2D.h"
#include "../Components/Behaviour.h"

class BrickBehaviour : public Behaviour
{
public:
	BrickBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
};

