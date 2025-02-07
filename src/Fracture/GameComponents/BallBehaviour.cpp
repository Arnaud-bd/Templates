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

    float x = m_transform->getPosition().x + m_Direction.x * 450.f * _deltaTime;
    float y = m_transform->getPosition().y + m_Direction.y * 450.f * _deltaTime;

    m_transform->setPosition(x, y);

    if (m_transform->getPosition().x <= 16.5f)
    {
        m_transform->setPosition(16.5f, m_transform->getPosition().y);
        m_Direction.x = -m_Direction.x;
    }

    if (m_transform->getPosition().x >= window->getSize().x - 16.5f)
    {
        m_transform->setPosition(window->getSize().x - 16.5f, m_transform->getPosition().y);
        m_Direction.x = -m_Direction.x;
    }

    if (m_transform->getPosition().y <= 16.5f)
    {
        m_transform->setPosition(m_transform->getPosition().x, 16.5f);
        m_Direction.y = -m_Direction.y;
    }

    if (m_transform->getPosition().y >= window->getSize().y - 16.5f)
    {
        GameManager::GetInstance()->LooseALife();
    }
}

//Initialise les component liés
void BallBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\ballBlue.png");
    s->Awake();
    s->Start();
    Collider* c = Add<Collider>();
    c->Start();
    c->AddHitbox({ 0,0 }, 16.5f);
}

void BallBehaviour::Start()
{
    m_Direction.x =  1.f;
    m_Direction.y = -1.f;
    m_transform = Get<Transform2D>();
}

//Sert à effectuer les actions après une collision
void BallBehaviour::OnCollideEnter(Collider* _other)
{
    sf::Vector2f currentPosition = m_transform->getPosition();
    sf::Vector2f delta = currentPosition - m_PreviousPosition;

    sf::Vector2f normal = _other->GetCollisionNormal(currentPosition);

    float dot = m_Direction.x * normal.x + m_Direction.y * normal.y;
    m_Direction.x -= 2 * dot * normal.x;
    m_Direction.y -= 2 * dot * normal.y;
    
}

void BallBehaviour::Reset()
{
    m_transform->setPosition(860.f, 920.f);
    m_Direction.x = 1.f;
    m_Direction.y = -1.f;
}
