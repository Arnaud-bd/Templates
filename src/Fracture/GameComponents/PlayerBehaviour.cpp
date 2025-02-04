#include "PlayerBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

PlayerBehaviour::PlayerBehaviour()
{
}

void PlayerBehaviour::Update(float _deltaTime)
{
    Transform2D* playerTransform = Get<Transform2D>();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerTransform->m_Position.x < 800)
    {
        playerTransform->m_Position.x += 500 * 1 * _deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerTransform->m_Position.x > 100)
    {
        playerTransform->m_Position.x += 500 * -1 * _deltaTime;
    }
}

void PlayerBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\paddleBlu.png", { 900, 900 }, { 1,1 });
    s->Awake();
    Collider* c = Add<Collider>();

    c->AddHitbox({ -54,0 }, 20);
    c->AddHitbox({ -36,0 }, 20);
    c->AddHitbox({ -18,0 }, 20);
    c->AddHitbox({ 0,0 }, 20);
    c->AddHitbox({ 18,0 }, 20);
    c->AddHitbox({ 36,0 }, 20);
    c->AddHitbox({ 54,0 }, 20);

    c->Awake();
}

void PlayerBehaviour::Start()
{
}

void PlayerBehaviour::OnCollide()
{

}
