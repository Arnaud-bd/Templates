#include "HillsBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

HillsBehaviour::HillsBehaviour()
{
}

void HillsBehaviour::Update(float _deltaTime)
{

}

void HillsBehaviour::Awake()
{
    SpriteRender* hills = Add<SpriteRender>();
    hills->Init("..\\..\\..\\res\\Sprite\\hills.png");
    hills->Awake();
}

void HillsBehaviour::Start()
{
}

void HillsBehaviour::OnCollideEnter(Collider* _other)
{

}
