#include "SunBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

SunBehaviour::SunBehaviour()
{
}

void SunBehaviour::Update(float _deltaTime)
{

}

void SunBehaviour::Awake()
{
    SpriteRender* cloud = Add<SpriteRender>();
    cloud->Init("..\\..\\..\\res\\Sprite\\sun.png");
    cloud->Awake();
}

void SunBehaviour::Start()
{
}

void SunBehaviour::OnCollideEnter(Collider* _other)
{

}
