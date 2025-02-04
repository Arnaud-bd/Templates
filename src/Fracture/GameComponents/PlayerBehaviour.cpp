#include "PlayerBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

PlayerBehaviour::PlayerBehaviour()
{
}

void PlayerBehaviour::Update(float _deltaTime)
{
    Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();

    std::vector<Transform2D*> transforms = scene->GetAll<Transform2D>();
    std::vector<Render*> renders = scene->GetAll<Render>(); 

    Transform2D* playerTransform = nullptr;

    for (int i = 0; i < transforms.size(); ++i)
    {
        if (transforms[i]->GetID() == this->GetID())
        {
            playerTransform = transforms[i];
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && transforms[i]->m_Position.x < 800)
            {
                transforms[i]->m_Position.x += 500 * 1 * _deltaTime;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && transforms[i]->m_Position.x > 100)
            {
                transforms[i]->m_Position.x += 500 * -1 * _deltaTime;
            }
            break;
        }
    }

    if (playerTransform)
    {
        for (int i = 0; i < renders.size(); ++i)
        {
            if (renders[i]->GetID() == this->GetID())
            {
                renders[i]->move(playerTransform->m_Position);
                break;
            }
        }
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
    c->AddHitbox({ 0,0 }, 20);
    c->AddHitbox({ 18,0 }, 20);
    c->AddHitbox({ 36,0 }, 20);
    c->AddHitbox({ 54,0 }, 20);

    c->Awake();
}

void PlayerBehaviour::Start()
{
}
