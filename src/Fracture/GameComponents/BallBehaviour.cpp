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

    for (int i = 0; i < transforms.size(); ++i)
    {
        if (transforms[i]->GetID() == this->GetID())
        {
            playerTransform = transforms[i];
            std::cout << " X : " << m_Direction.x << " Y : " << m_Direction.y << std::endl;
            transforms[i]->m_Position.x += m_Direction.x * 500.f * _deltaTime;
            transforms[i]->m_Position.y += m_Direction.y * 500.f * _deltaTime;

            if (transforms[i]->m_Position.x <= 0.f)
            {
                transforms[i]->m_Position.x = 0.f;
                m_Direction.x = -m_Direction.x;
            }

            if (transforms[i]->m_Position.x >= 1166.f)
            {
                transforms[i]->m_Position.x = 1166.f;
                m_Direction.x = -m_Direction.x;
            }

            if (transforms[i]->m_Position.y <= 0.f)
            {
                transforms[i]->m_Position.y = 0.f;
                m_Direction.y = -m_Direction.y;
            }

            if (transforms[i]->m_Position.y >= 978.f)
            {
                transforms[i]->m_Position.y = 978.f;
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

                if (colliders[i]->IsCollide(*colliders[j])) {
                    std::cout << "Collision détectée !" << std::endl;

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
                    return;
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
