#include "BackGroundBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include <iostream>

BackGroundBehaviour::BackGroundBehaviour()
{
}

void BackGroundBehaviour::Update(float _deltaTime)
{
}

void BackGroundBehaviour::Awake()
{
    SpriteRender* groundLayer1 = Add<SpriteRender>();
    groundLayer1->Init("..\\..\\..\\res\\Sprite\\groundLayer1.png", {900, 900}, { 1, 1});
    groundLayer1->Awake();

    SpriteRender* groundLayer2 = Add<SpriteRender>();
    groundLayer2->Init("..\\..\\..\\res\\Sprite\\groundLayer2.png", { 700, 700 }, { 1,1 });
    groundLayer2->Awake();

    SpriteRender* hills = Add<SpriteRender>();
    hills->Init("..\\..\\..\\res\\Sprite\\hills.png", { 800, 800 }, { 1,1 });
    hills->Awake();

    SpriteRender* cloudLayer1 = Add<SpriteRender>();
    cloudLayer1->Init("..\\..\\..\\res\\Sprite\\cloudLayer1.png", { 900, 900}, { 1,1 });
    cloudLayer1->Awake();

    SpriteRender* cloudLayer2 = Add<SpriteRender>();
    cloudLayer2->Init("..\\..\\..\\res\\Sprite\\cloudLayer2.png", { 1000, 1000 }, { 1,1 });
    cloudLayer2->Awake();

    SpriteRender* bush1 = Add<SpriteRender>();
    bush1->Init("..\\..\\..\\res\\Sprite\\bush.png", { 540, 984}, { 1,1 });
    bush1->Awake();

    SpriteRender* bush2 = Add<SpriteRender>();
    bush2->Init("..\\..\\..\\res\\Sprite\\bush.png", { 220, 1000}, { 1,1 });
    bush2->Awake();

    SpriteRender* tree1 = Add<SpriteRender>();
    tree1->Init("..\\..\\..\\res\\Sprite\\tree.png", { 364, 963}, { 1,1 });
    tree1->Awake();

    SpriteRender* tree2 = Add<SpriteRender>();
    tree2->Init("..\\..\\..\\res\\Sprite\\tree.png", { 563, 400 }, { 1,1 });
    tree2->Awake();

    SpriteRender* cloud1 = Add<SpriteRender>();
    cloud1->Init("..\\..\\..\\res\\Sprite\\cloud.png", { 841, 410}, { 1,1 });
    cloud1->Awake();

    SpriteRender* cloud2 = Add<SpriteRender>();
    cloud2->Init("..\\..\\..\\res\\Sprite\\cloud.png", { 1750, 740 }, { 1,1 });
    cloud2->Awake();
}

void BackGroundBehaviour::Start()
{
}
