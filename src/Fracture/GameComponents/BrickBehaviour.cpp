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

BrickBehaviour::~BrickBehaviour()
{
}

void BrickBehaviour::Awake()
{
    Collider* c = Add<Collider>();
    c->Start();
    c->AddHitbox({ -24,0 }, 22);
    c->AddHitbox({ 0,0 }, 22);
    c->AddHitbox({ 24,0 }, 22);
    

    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\element_red_rectangle.png");
    s->Start();
}

void BrickBehaviour::Start()
{
}

//Sert à effectuer les actions après une collision
void BrickBehaviour::OnCollideEnter(Collider* _other)
{
    std::vector<Component*> sameID = GetAll<Component>();
    for (int i = 0; i < sameID.size(); ++i)
    {
        sameID[i]->ToDestroy();
    }
    GameManager::GetInstance()->IncreaseScore(150);
}
