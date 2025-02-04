#include "BallBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../GameComponents/BrickBehaviour.h"
#include <iostream>

BallBehaviour::BallBehaviour()
{

}

void BallBehaviour::Update(float _deltaTime)
{
    Transform2D* playerTransform = Get<Transform2D>();
    Render* render = Get<Render>();

    std::cout << " X : " << m_Direction.x << " Y : " << m_Direction.y << std::endl;
    playerTransform->m_Position.x += m_Direction.x * 500.f * _deltaTime;
    playerTransform->m_Position.y += m_Direction.y * 500.f * _deltaTime;

    if (playerTransform->m_Position.x <= 0.f)
    {
        playerTransform->m_Position.x = 0.f;
        m_Direction.x = -m_Direction.x;
    }
}


void BallBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\ballBlue.png", {500, 500}, {1,1});
    s->Awake();
    Collider* c = Add<Collider>();
    c->AddHitbox({0,0}, 11);
    c->Awake();
}

void BallBehaviour::Start()
{
    m_Direction.x =  1.f;
    m_Direction.y = -1.f;
}

void BallBehaviour::OnCollide()
{
    if (m_Direction.x > 0 && m_Direction.y > 0)
    {
        m_Direction.y = -m_Direction.y;
    }

    else if (m_Direction.x > 0 && m_Direction.y < 0)
    {
        m_Direction.y = -m_Direction.y;
    }

    else if (m_Direction.x < 0 && m_Direction.y < 0)
    {
        m_Direction.y = -m_Direction.y;
    }

    else if (m_Direction.x < 0 && m_Direction.y > 0)
    {
        m_Direction.y = -m_Direction.y;
    }
}
