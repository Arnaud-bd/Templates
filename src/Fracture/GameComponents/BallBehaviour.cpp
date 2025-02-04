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
    
    Transform2D* Transform = Get<Transform2D>();

    float x = Transform->getPosition().x + m_Direction.x * 500.f * _deltaTime;
    float y = Transform->getPosition().y + m_Direction.y * 500.f * _deltaTime;

    Transform->setPosition(x, y);
    
}

void BallBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\ballBlue.png");
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
