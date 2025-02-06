#include "GroundLayer2Behaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

GroundLayer2Behaviour::GroundLayer2Behaviour()
{
}

void GroundLayer2Behaviour::Update(float _deltaTime)
{

}

void GroundLayer2Behaviour::Awake()
{
    SpriteRender* groundLayer2 = Add<SpriteRender>();
    groundLayer2->Init("..\\..\\..\\res\\Sprite\\groundLayer2.png");
    groundLayer2->Awake();
}

void GroundLayer2Behaviour::Start()
{

}

void GroundLayer2Behaviour::OnCollideEnter(Collider* _other)
{

}
