#pragma once
#include "../Components/Behaviour.h"

class CloudLayer2Behaviour : public Behaviour
{
public:
	CloudLayer2Behaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};