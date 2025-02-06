#include "TreeBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

TreeBehaviour::TreeBehaviour()
{
}

void TreeBehaviour::Update(float _deltaTime)
{

}

void TreeBehaviour::Awake()
{
    SpriteRender* tree = Add<SpriteRender>();
    tree->Init("..\\..\\..\\res\\Sprite\\tree.png");
    tree->Awake();
}

void TreeBehaviour::Start()
{
}

void TreeBehaviour::OnCollideEnter(Collider* _other)
{

}
