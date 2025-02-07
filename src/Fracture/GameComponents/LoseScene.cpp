#include "LoseScene.h"
#include "../GameComponents/TreeBehaviour.h"
#include "../GameComponents/BushBehaviour.h"
#include "../GameComponents/CloudBehaviour.h"
#include "../GameComponents/CloudLayer1Behaviour.h"
#include "../GameComponents/CloudLayer2Behaviour.h"
#include "../GameComponents/HillsBehaviour.h"
#include "../GameComponents/Groundlayer1Behaviour.h"
#include "../GameComponents/Groundlayer2Behaviour.h"
#include "../GameComponents/PlayerBehaviour.h"
#include "../GameComponents/BrickBehaviour.h"
#include "../GameComponents/BallBehaviour.h"
#include "../GameComponents/ScoreBehaviour.h"
#include "../GameComponents/ButtonBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Render.h"
#include "../Components/Collider.h"

void LoseScene::Init()
{
	Transform2D* cLTransform = CreateEntity({ 512, 400 }, { 1 , 1 }, 0);
	CloudLayer1Behaviour* cloudLayer1Behaviour = cLTransform->Add<CloudLayer1Behaviour>();

	Transform2D* cLTransform2 = CreateEntity({ 1536, 400 }, { 1 , 1 }, 0);
	CloudLayer1Behaviour* cloudLayer1Behaviour2 = cLTransform2->Add<CloudLayer1Behaviour>();

	Transform2D* cL2Transform = CreateEntity({ 512, 500 }, { 1 , 1 }, 0);
	CloudLayer1Behaviour* cloudLayer2Behaviour = cL2Transform->Add<CloudLayer1Behaviour>();

	Transform2D* cL2Transform2 = CreateEntity({ 1536, 500 }, { 1 , 1 }, 0);
	CloudLayer1Behaviour* cloudLayer2Behaviour2 = cL2Transform2->Add<CloudLayer1Behaviour>();

	Transform2D* cloud1Transform = CreateEntity({ 200, 150 }, { 0.6f,0.6f }, 0);
	CloudBehaviour* cloud1Behaviour = cloud1Transform->Add<CloudBehaviour>();

	Transform2D* cloud2Transform = CreateEntity({ 1720, 150 }, { 0.6f,0.6f }, 0);
	CloudBehaviour* cloud2Behaviour = cloud2Transform->Add<CloudBehaviour>();

	Transform2D* gLTransform = CreateEntity({ 512, 650 }, { 1 , 1 }, 0);
	GroundLayer1Behaviour* groundLayer1Behaviour = gLTransform->Add<GroundLayer1Behaviour>();

	Transform2D* gLTransform2 = CreateEntity({ 1536, 650 }, { 1 , 1 }, 0);
	GroundLayer1Behaviour* groundLayer1Behaviour2 = gLTransform2->Add<GroundLayer1Behaviour>();

	Transform2D* bush2Transform = CreateEntity({ 1350, 610 }, { 2,2 }, 0);
	BushBehaviour* bush2Behaviour = bush2Transform->Add<BushBehaviour>();

	Transform2D* tree1Transform = CreateEntity({ 550, 600 }, { 0.6f, 0.6f }, 350.f);
	TreeBehaviour* tree1Behaviour = tree1Transform->Add<TreeBehaviour>();

	Transform2D* hillsTransform = CreateEntity({ 512, 750 }, { 1 , 1 }, 0);
	HillsBehaviour* hillsBehaviour = hillsTransform->Add<HillsBehaviour>();

	Transform2D* hillsTransform2 = CreateEntity({ 1536, 750 }, { 1 , 1 }, 0);
	HillsBehaviour* hillsBehaviour2 = hillsTransform2->Add<HillsBehaviour>();

	Transform2D* tree2Transform = CreateEntity({ 1820, 810 }, { 0.8f , 0.8f }, 5.f);
	TreeBehaviour* tree2Behaviour = tree2Transform->Add<TreeBehaviour>();

	Transform2D* bush1Transform = CreateEntity({ 150, 750 }, { 2,2 }, 0);
	BushBehaviour* bush1Behaviour = bush1Transform->Add<BushBehaviour>();

	Transform2D* gL2Transform = CreateEntity({ 512, 950 }, { 1 , 2 }, 0);
	GroundLayer2Behaviour* groundLayer2Behaviour = gL2Transform->Add<GroundLayer2Behaviour>();

	Transform2D* gL2Transform2 = CreateEntity({ 1536, 950 }, { 1 , 2 }, 0);
	GroundLayer2Behaviour* groundLayer2Behaviour2 = gL2Transform2->Add<GroundLayer2Behaviour>();

	Transform2D* bush3Transform = CreateEntity({ 1800, 1010 }, { 2.5 , 2.5 }, 0);
	BushBehaviour* bush3Behaviour = bush3Transform->Add<BushBehaviour>();

	Transform2D* tree3Transform = CreateEntity({ 15, 1085 }, { 1.5f , 1.5f }, 0);
	TreeBehaviour* tree3Behaviour = tree3Transform->Add<TreeBehaviour>();
}
