#pragma once
#include "../Components/Behaviour.h"

class TreeBehaviour : public Behaviour
{
public:
	TreeBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};

