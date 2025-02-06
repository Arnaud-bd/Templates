#pragma once
#include "../Components/Behaviour.h"

class HillsBehaviour : public Behaviour
{
public:
	HillsBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};