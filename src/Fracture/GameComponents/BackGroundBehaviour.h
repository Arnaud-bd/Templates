#pragma once
#include "../Components/Behaviour.h"

class BackGroundBehaviour : public Behaviour
{
public:
	BackGroundBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollide() override;
};

