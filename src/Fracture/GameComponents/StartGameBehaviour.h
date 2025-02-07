#pragma once
#include "../Components/Transform2D.h"
#include "../GameComponents/ButtonBehaviour.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"


class StartGameBehaviour : public ButtonBehaviour
{
public:
	TextRender* m_text;

	StartGameBehaviour();
	~StartGameBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;

	void OnCollideEnter(Collider* _other);
};
