#pragma once
#include "../Components/Behaviour.h"

class BushBehaviour : public Behaviour
{
public:
	BushBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};

