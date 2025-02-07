#pragma once
#include "../Components/Transform2D.h"
#include "../GameComponents/ButtonBehaviour.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"


class FFButtonBehaviour : public ButtonBehaviour
{
public:
	TextRender* m_text;

	FFButtonBehaviour();
	~FFButtonBehaviour();

	void Awake() override;
	void Start() override;

	void OnCollideEnter(Collider* _other);
};
