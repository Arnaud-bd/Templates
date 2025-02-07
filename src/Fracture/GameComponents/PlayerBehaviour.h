#pragma once
#include "../Components/Transform2D.h"
#include "../Components/Behaviour.h"

class PlayerBehaviour : public Behaviour
{
	Transform2D* m_transform;
	int m_Lifes = 3;

public:
	PlayerBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
	void Reset();
	int GetLife();
	void LooseLife();
};

