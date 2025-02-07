#pragma once
#include "../Components/Transform2D.h"
#include "../Components/Behaviour.h"
#include "../Components/TextRender.h"
#include <string>
class LifeBehaviour : public Behaviour
{
	TextRender* t;

public:
	LifeBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollideEnter(Collider* _other) override;
};
