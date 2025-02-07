#include "FFButtonBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"
#include <iostream>

FFButtonBehaviour::FFButtonBehaviour()
{
    m_transform = nullptr;
}

FFButtonBehaviour::~FFButtonBehaviour()
{
}

void FFButtonBehaviour::Awake()
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

void FFButtonBehaviour::Start()
{
    m_transform = Get<Transform2D>();
    m_setting = GameManager::GAMESTATE::CREDITS;
}

void FFButtonBehaviour::OnCollideEnter(Collider* _other)
{
}
