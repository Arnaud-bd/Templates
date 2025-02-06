#pragma once
#include "../Components/Behaviour.h"

class CloudLayer1Behaviour : public Behaviour
{
public:
	CloudLayer1Behaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};