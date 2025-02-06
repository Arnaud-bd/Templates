#pragma once
#include "../Components/Behaviour.h"

class GroundLayer2Behaviour : public Behaviour
{
public:
	GroundLayer2Behaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};