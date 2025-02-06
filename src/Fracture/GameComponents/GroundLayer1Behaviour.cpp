#include "GroundLayer1Behaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

GroundLayer1Behaviour::GroundLayer1Behaviour()
{
}

void GroundLayer1Behaviour::Update(float _deltaTime)
{

}

void GroundLayer1Behaviour::Awake()
{
    SpriteRender* groundLayer1 = Add<SpriteRender>();
    groundLayer1->Init("..\\..\\..\\res\\Sprite\\groundLayer1.png");
    groundLayer1->Awake();
}

void GroundLayer1Behaviour::Start()
{
}

void GroundLayer1Behaviour::OnCollideEnter(Collider* _other)
{

}
