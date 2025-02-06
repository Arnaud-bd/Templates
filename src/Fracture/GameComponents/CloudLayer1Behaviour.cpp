#include "CloudLayer1Behaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

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
