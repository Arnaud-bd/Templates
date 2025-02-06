#include "BushBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

BushBehaviour::BushBehaviour()
{
}

void BushBehaviour::Update(float _deltaTime)
{

}

void BushBehaviour::Awake()
{
    SpriteRender* bush = Add<SpriteRender>();
    bush->Init("..\\..\\..\\res\\Sprite\\bush.png");
    bush->Awake();
}

void BushBehaviour::Start()
{
}

void BushBehaviour::OnCollideEnter(Collider* _other)
{

}
