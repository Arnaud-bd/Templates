#include "PlayerBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

PlayerBehaviour::PlayerBehaviour()
{
}

void PlayerBehaviour::Update(float _deltaTime)
{
    Transform2D* Transform = Get<Transform2D>();
    sf::RenderWindow* window = GameManager::GetInstance()->GetWindow();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Transform->getPosition().x < window->getSize().x)
    {
        Transform->setPosition(Transform->getPosition().x + 500 * 1 * _deltaTime, Transform->getPosition().y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Transform->getPosition().x > 0.f)
    {
        Transform->setPosition(Transform->getPosition().x + 500 * -1 * _deltaTime, Transform->getPosition().y);
    }
}

void PlayerBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\paddleBlu.png");
    s->Awake();
    Collider* c = Add<Collider>();

    c->AddHitbox({ -54,0 }, 20);
    c->AddHitbox({ -36,0 }, 20);
    c->AddHitbox({ -18,0 }, 20);
    c->AddHitbox({   0,0 }, 20);
    c->AddHitbox({  18,0 }, 20);
    c->AddHitbox({  36,0 }, 20);
    c->AddHitbox({  54,0 }, 20);

    c->Awake();
}

void PlayerBehaviour::Start()
{
}

void PlayerBehaviour::OnCollide()
{

}
