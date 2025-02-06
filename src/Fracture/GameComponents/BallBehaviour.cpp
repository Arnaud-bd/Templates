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
    m_PreviousPosition = m_transform->getPosition();
    sf::RenderWindow* window = GameManager::GetInstance()->GetWindow();

    float x = m_transform->getPosition().x + m_Direction.x * 500.f * _deltaTime;
    float y = m_transform->getPosition().y + m_Direction.y * 500.f * _deltaTime;

    m_transform->setPosition(x, y);

    if (m_transform->getPosition().x <= 0.f)
    {
        m_transform->setPosition(0.f, m_transform->getPosition().y);
        m_Direction.x = -m_Direction.x;
    }

    if (m_transform->getPosition().x >= window->getSize().x)
    {
        m_transform->setPosition(window->getSize().x, m_transform->getPosition().y);
        m_Direction.x = -m_Direction.x;
    }

    if (m_transform->getPosition().y <= 0.f)
    {
        m_transform->setPosition(m_transform->getPosition().x, 0.f);
        m_Direction.y = -m_Direction.y;
    }

    if (m_transform->getPosition().y >= window->getSize().y)
    {
        m_transform->setPosition(m_transform->getPosition().x, window->getSize().y);
        m_Direction.y = -m_Direction.y;
    }
}

void BallBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\ballBlue.png");
    s->Awake();
    s->Start();
    Collider* c = Add<Collider>();
    c->Start();
    c->AddHitbox({ 0,0 }, 11);
}

void BallBehaviour::Start()
{
    m_Direction.x =  1.f;
    m_Direction.y = -1.f;
    m_transform = Get<Transform2D>();
}

void BallBehaviour::OnCollideEnter(Collider* _other)
{
    sf::Vector2f currentPosition = m_transform->getPosition();
    sf::Vector2f delta = currentPosition - m_PreviousPosition;

    if (std::abs(delta.x) > std::abs(delta.y))
    {
        m_Direction.x = -m_Direction.x;
        return;
    }
    else
    {
        m_Direction.y = -m_Direction.y;
        return;
    }
}
