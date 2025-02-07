#pragma once
#include "../Components/Behaviour.h"

class TreeBehaviour : public Behaviour
{
	Transform2D* m_Transform;
	int m_RotationSens = 1;
	float m_OriginalRotation;

public:
	TreeBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};

