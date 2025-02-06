#include "CloudLayer2Behaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

CloudLayer2Behaviour::CloudLayer2Behaviour()
{
}

void CloudLayer2Behaviour::Update(float _deltaTime)
{

}

void CloudLayer2Behaviour::Awake()
{
    SpriteRender* cloudLayer2 = Add<SpriteRender>();
    cloudLayer2->Init("..\\..\\..\\res\\Sprite\\cloudLayer2.png");
    cloudLayer2->Awake();
}

void CloudLayer2Behaviour::Start()
{
}

void CloudLayer2Behaviour::OnCollideEnter(Collider* _other)
{

}
