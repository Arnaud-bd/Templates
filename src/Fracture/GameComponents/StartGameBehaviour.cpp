#include "StartGameBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"
#include <iostream>

StartGameBehaviour::StartGameBehaviour()
{
    m_transform = nullptr;
}

StartGameBehaviour::~StartGameBehaviour()
{
}

void StartGameBehaviour::Update(float _deltaTime)
{
}

void StartGameBehaviour::Awake()
{
    m_sprite = Add<SpriteRender>();
    m_sprite->Init("..\\..\\..\\res\\Sprite\\button_rectangle_depth_flat.png");
    m_sprite->Awake();
    m_sprite->Start();

    m_text = Add<TextRender>();
    m_text->Init();
    m_text->Awake();
    m_text->Start();
}

void StartGameBehaviour::Start()
{
    m_transform = Get<Transform2D>();
    m_setting = 1;
}

void StartGameBehaviour::OnCollideEnter(Collider* _other)
{
}
