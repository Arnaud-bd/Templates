#include "CastleBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

CastleBehaviour::CastleBehaviour()
{
}

void CastleBehaviour::Update(float _deltaTime)
{

}

void CastleBehaviour::Awake()
{
    SpriteRender* cloud = Add<SpriteRender>();
    cloud->Init("..\\..\\..\\res\\Sprite\\castleSmall.png");
    cloud->Awake();
}

void CastleBehaviour::Start()
{
}

void CastleBehaviour::OnCollideEnter(Collider* _other)
{

}
