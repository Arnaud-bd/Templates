#include "ReturnToMenuBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"
#include <iostream>

ReturnToMenuBehaviour::ReturnToMenuBehaviour()
{
    m_transform = nullptr;
}

ReturnToMenuBehaviour::~ReturnToMenuBehaviour()
{
}

void ReturnToMenuBehaviour::Awake()
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

void ReturnToMenuBehaviour::Start()
{
    m_transform = Get<Transform2D>();
    m_setting = GameManager::GAMESTATE::START;
}

void ReturnToMenuBehaviour::OnCollideEnter(Collider* _other)
{
}
