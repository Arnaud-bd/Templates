#pragma once
#include "../Components/Behaviour.h"

class CastleBehaviour : public Behaviour
{
public:
	CastleBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};


