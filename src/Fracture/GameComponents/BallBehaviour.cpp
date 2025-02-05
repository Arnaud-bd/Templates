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
    sf::RenderWindow* window = GameManager::GetInstance()->GetWindow();

    float x = Transform->getPosition().x + m_Direction.x * 500.f * _deltaTime;
    float y = Transform->getPosition().y + m_Direction.y * 500.f * _deltaTime;

    Transform->setPosition(x, y);

    if (Transform->getPosition().x <= 0.f)
    {
        Transform->setPosition(0.f, Transform->getPosition().y);
        m_Direction.x = -m_Direction.x;
    }

    if (Transform->getPosition().x >= window->getSize().x)
    {
        Transform->setPosition(window->getSize().x, Transform->getPosition().y);
        m_Direction.x = -m_Direction.x;
    }

    if (Transform->getPosition().y <= 0.f)
    {
        Transform->setPosition(Transform->getPosition().x, 0.f);
        m_Direction.y = -m_Direction.y;
    }

    if (Transform->getPosition().y >= window->getSize().y)
    {
        Transform->setPosition(Transform->getPosition().x, window->getSize().y);
        m_Direction.y = -m_Direction.y;
    }
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
        return;
    }

    if (m_Direction.x > 0 && m_Direction.y < 0)
    {
        m_Direction.y = -m_Direction.y;
        return;
    }

    if (m_Direction.x < 0 && m_Direction.y < 0)
    {
        m_Direction.y = -m_Direction.y;
        return;
    }

    if (m_Direction.x < 0 && m_Direction.y > 0)
    {
        m_Direction.y = -m_Direction.y;
        return;
    }
}
