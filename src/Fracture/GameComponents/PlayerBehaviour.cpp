#include "PlayerBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

PlayerBehaviour::PlayerBehaviour()
{
}

void PlayerBehaviour::Update(float _deltaTime)
{
    
}

void PlayerBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\paddleBlu.png", { 900, 900 }, { 1,1 });
    s->Awake();
    Collider* c = Add<Collider>();

    c->AddHitbox({ -54,0 }, 20);
    c->AddHitbox({ -36,0 }, 20);
    c->AddHitbox({ -18,0 }, 20);
    c->AddHitbox({ 0,0 }, 20);
    c->AddHitbox({ 18,0 }, 20);
    c->AddHitbox({ 36,0 }, 20);
    c->AddHitbox({ 54,0 }, 20);

    c->Awake();
}

void PlayerBehaviour::Start()
{
}

void PlayerBehaviour::OnCollide()
{

}
