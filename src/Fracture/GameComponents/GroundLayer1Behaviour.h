#pragma once
#include "../Components/Behaviour.h"

class GroundLayer1Behaviour : public Behaviour
{
public:
	GroundLayer1Behaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};