#include "BallBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

BallBehaviour::BallBehaviour()
{

}

void BallBehaviour::Update(float _deltaTime)
{
    Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene();

    std::vector<Transform2D*> transforms = scene->GetAll<Transform2D>();
    std::vector<Render*> renders = scene->GetAll<Render>();
    std::vector<Collider*> colliders = scene->GetAll<Collider>();

    Transform2D* playerTransform = nullptr;

    for (auto& transform : transforms)
    {
        if (transform->GetID() == this->GetID())
        {
            playerTransform = transform;
            std::cout << " X : " << transform->m_Position.x << " Y : " << transform->m_Position.y << std::endl;
            transform->m_Position.x += m_Direction.x * 500.f * _deltaTime;
            transform->m_Position.y += m_Direction.y * 500.f * _deltaTime;

            if (transform->m_Position.x <= 0.f)
            {
                transform->m_Position.x = 0.f;
                m_Direction.x = -m_Direction.x;
            }

            if (transform->m_Position.x >= 1166.f)
            {
                transform->m_Position.x = 1166.f;
                m_Direction.x = -m_Direction.x;
            }

            if (transform->m_Position.y <= 0.f)
            {
                transform->m_Position.y = 0.f;
                m_Direction.y = -m_Direction.y;
            }

            if (transform->m_Position.y >= 978.f)
            {
                transform->m_Position.y = 978.f;
                m_Direction.y = -m_Direction.y;
            }

            break;
        }
    }

    for (int i = 0; i < colliders.size(); ++i)
    {
        if (colliders[i]->GetID() == this->GetID())
        {
            for (int j = 0; j < colliders.size(); ++j)
            {
                if (i == j)
                {
                    continue;
                }

                if (colliders[i]->IsCollide(*colliders[j]))
                {
                    std::cout << "coucou" << std::endl;
                    /*colliders[j].isDead = true;*/
                }
            }
        }
    }

    if (playerTransform)
    {
        for (auto& render : renders)
        {
            if (render->GetID() == this->GetID())
            {
                render->move(playerTransform->m_Position);
                break;
            }
        }
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
