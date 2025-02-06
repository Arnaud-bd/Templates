#include "CloudBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

CloudBehaviour::CloudBehaviour()
{
}

void CloudBehaviour::Update(float _deltaTime)
{

}

void CloudBehaviour::Awake()
{
    SpriteRender* cloud = Add<SpriteRender>();
    cloud->Init("..\\..\\..\\res\\Sprite\\cloud.png");
    cloud->Awake();
}

void CloudBehaviour::Start()
{
}

void CloudBehaviour::OnCollideEnter(Collider* _other)
{

}
