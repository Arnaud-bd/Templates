#pragma once
#include "../Components/Transform2D.h"
#include "../Components/Behaviour.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"


class ButtonBehaviour : public Behaviour
{
	Transform2D* m_transform;
	SpriteRender* m_sprite;

public:
	TextRender* m_text;

	ButtonBehaviour();
	~ButtonBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;

	void OnCollideEnter(Collider* _other);
};
