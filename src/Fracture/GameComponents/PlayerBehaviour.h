#pragma once
#include "../Components/Transform2D.h"
#include "../Components/Behaviour.h"

class PlayerBehaviour : public Behaviour
{
public:
	PlayerBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollide() override;
};

