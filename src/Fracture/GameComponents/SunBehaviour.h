#pragma once
#include "../Components/Behaviour.h"

class SunBehaviour : public Behaviour
{
public:
	SunBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};


