#include "CloudLayer1Behaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

CloudLayer1Behaviour::CloudLayer1Behaviour()
{
}

void CloudLayer1Behaviour::Update(float _deltaTime)
{

}

void CloudLayer1Behaviour::Awake()
{
    SpriteRender* cloudLayer1 = Add<SpriteRender>();
    cloudLayer1->Init("..\\..\\..\\res\\Sprite\\cloudLayer1.png");
    cloudLayer1->Awake();
}

void CloudLayer1Behaviour::Start()
{
}

void CloudLayer1Behaviour::OnCollideEnter(Collider* _other)
{

}
