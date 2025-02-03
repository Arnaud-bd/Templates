#include "PlayerBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

PlayerBehaviour::PlayerBehaviour()
{
	
}

void PlayerBehaviour::Update(float _deltaTime)
{

}

void PlayerBehaviour::Awake()
{
    Collider* c = Add<Collider>();
    //c->Init ?
    c->Awake();
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\paddleBlu.png");
    s->Awake();
}

void PlayerBehaviour::Start()
{
}
