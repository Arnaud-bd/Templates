#pragma once
#include "../Components/Behaviour.h"

class BushBehaviour : public Behaviour
{
	Transform2D* m_Transform;
	int m_ScaleSens = 1;

public:
	BushBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};

