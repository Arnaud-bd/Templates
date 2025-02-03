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

    for (auto& transform : transforms)
    {
        if (transform->GetID() == this->GetID())
        {
            playerTransform = transform;
            std::cout << " X : " << transform->m_Position.x << " Y : " << transform->m_Position.y << std::endl;
            transform->m_Position.x += 10 * _deltaTime;
            transform->m_Position.y += 10 * _deltaTime;
            break;
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


void PlayerBehaviour::Awake()
{
    Collider* c = Add<Collider>();
    //c->Init ?
    c->Awake();
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\paddleBlu.png");
    s->Awake();
}

void PlayerBehaviour::Start()
{
}
