#include "ExitBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"
#include <iostream>

ExitBehaviour::ExitBehaviour()
{
    m_transform = nullptr;
}

ExitBehaviour::~ExitBehaviour()
{
}

void ExitBehaviour::Awake()
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

void ExitBehaviour::Start()
{
    m_transform = Get<Transform2D>();
    m_setting = GameManager::GAMESTATE::EXIT;
}

void ExitBehaviour::OnCollideEnter(Collider* _other)
{
}
