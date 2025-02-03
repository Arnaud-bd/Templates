#include "BrickBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

#include <iostream>
BrickBehaviour::BrickBehaviour()
{

}

void BrickBehaviour::Update(float _deltaTime)
{
}

void BrickBehaviour::Awake()
{
    Collider* c = Add<Collider>();
    //c->Init ?
    c->Awake();

    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\element_red_rectangle.png");
    s->Awake();
}

void BrickBehaviour::Start()
{
    Scene* scene = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene(); 

    std::vector<Transform2D*> transforms = scene->GetAll<Transform2D>(); 
    std::vector<Render*> renders = scene->GetAll<Render>(); 

    Transform2D* BrickTransform = nullptr;

    for (int i = 0; i < transforms.size(); ++i)
    {
        if (transforms[i]->GetID() == this->GetID())
        { 
            BrickTransform = transforms[i]; 
        }
    }

    if (BrickTransform)
    {
        for (int i = 0; i < renders.size(); ++i)
        {
            if (renders[i]->GetID() == this->GetID())
            {
                renders[i]->move(BrickTransform->m_Position); 
                break;
            }
        }
    }
}
