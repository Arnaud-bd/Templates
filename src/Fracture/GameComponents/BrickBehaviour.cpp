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

    c->AddHitbox({ -16,0 }, 14);
    c->AddHitbox({ 0,0 }, 14);
    c->AddHitbox({ 16,0 }, 14);

    c->Awake();

    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\element_red_rectangle.png", {300,300}, {1,1});
    s->Awake();
}

void BrickBehaviour::Start()
{

    Transform2D* transform = Get<Transform2D>(); 
    Render* renders = Get<Render>(); 


   renders->move(transform->m_Position);

}
