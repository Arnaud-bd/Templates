#include "PlayerBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

PlayerBehaviour::PlayerBehaviour()
{
}

void PlayerBehaviour::Update(float _deltaTime)
{
    sf::RenderWindow* window = GameManager::GetInstance()->GetWindow();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_transform->getPosition().x < window->getSize().x)
    {
        m_transform->setPosition(m_transform->getPosition().x + 550 * 1 * _deltaTime, m_transform->getPosition().y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_transform->getPosition().x > 0.f)
    {
        m_transform->setPosition(m_transform->getPosition().x + 550 * -1 * _deltaTime, m_transform->getPosition().y);
    }
}

void PlayerBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\paddleBlu.png");
    s->Start();
    Collider* c = Add<Collider>();
    c->Start();
    c->AddHitbox({   0,0 }, 30);

}

void PlayerBehaviour::Start()
{
    m_transform = Get<Transform2D>();
}

void PlayerBehaviour::OnCollideEnter(Collider* _other)
{

}
