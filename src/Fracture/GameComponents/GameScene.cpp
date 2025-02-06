#include "GameScene.h"
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

void GameScene::Init()
{

	Transform2D* cLTransform = CreateEntity({ 960, 500 }, { 1.875f , 1 }, 0);
	CloudLayer1Behaviour* cloudLayer1Behaviour = cLTransform->Add<CloudLayer1Behaviour>();

	Transform2D* cLTransform2 = CreateEntity({ 960, 500 }, { 1.875f , 1 }, 0);
	CloudLayer1Behaviour* cloudLayer1Behaviour2 = cLTransform2->Add<CloudLayer1Behaviour>();

	Transform2D* cL2Transform = CreateEntity({ 960, 600 }, { 1.875f , 1 }, 0);
	CloudLayer1Behaviour* cloudLayer2Behaviour = cL2Transform->Add<CloudLayer1Behaviour>();

	Transform2D* cL2Transform2 = CreateEntity({ 960, 600 }, { 1.875f , 1 }, 0);
	CloudLayer1Behaviour* cloudLayer2Behaviour2 = cL2Transform2->Add<CloudLayer1Behaviour>();

	Transform2D* hillsTransform = CreateEntity({ 960, 700 }, { 1.875f , 1 }, 0);
	HillsBehaviour* hillsBehaviour = hillsTransform->Add<HillsBehaviour>();

	Transform2D* hillsTransform2 = CreateEntity({ 960, 700 }, { 1.875f , 1 }, 0);
	HillsBehaviour* hillsBehaviour2 = hillsTransform2->Add<HillsBehaviour>();

	Transform2D* gLTransform = CreateEntity({ 960, 800 }, { 1.875f , 1 }, 0);
	GroundLayer1Behaviour* groundLayer1Behaviour = gLTransform->Add<GroundLayer1Behaviour>();

	Transform2D* gLTransform2 = CreateEntity({ 960, 800 }, { 1.875f , 1 }, 0);
	GroundLayer1Behaviour* groundLayer1Behaviour2 = gLTransform2->Add<GroundLayer1Behaviour>();

	Transform2D* tree1Transform = CreateEntity({ 100, 950 }, { 1,1 }, 0);
	TreeBehaviour* tree1Behaviour = tree1Transform->Add<TreeBehaviour>();

	Transform2D* tree2Transform = CreateEntity({ 1820, 950 }, { 1,1 }, 0);
	TreeBehaviour* tree2Behaviour = tree2Transform->Add<TreeBehaviour>();

	Transform2D* gL2Transform = CreateEntity({ 960, 1000 }, { 1.875f , 1 }, 0);
	GroundLayer2Behaviour* groundLayer2Behaviour = gL2Transform->Add<GroundLayer2Behaviour>();

	Transform2D* gL2Transform2 = CreateEntity({ 960, 1000 }, { 1.875f , 1 }, 0);
	GroundLayer2Behaviour* groundLayer2Behaviour2 = gL2Transform2->Add<GroundLayer2Behaviour>();

	Transform2D* bush1Transform = CreateEntity({ 200, 950 }, { 1,1 }, 0);
	BushBehaviour* bush1Behaviour = bush1Transform->Add<BushBehaviour>();

	Transform2D* bush2Transform = CreateEntity({ 1720, 950 }, { 1,1 }, 0);
	BushBehaviour* bush2Behaviour = bush2Transform->Add<BushBehaviour>();

	Transform2D* cloud1Transform = CreateEntity({ 200, 150}, { 1,1 }, 0);
	CloudBehaviour* cloud1Behaviour = cloud1Transform->Add<CloudBehaviour>();

	Transform2D* cloud2Transform = CreateEntity({ 1720, 150 }, { 1,1 }, 0);
	CloudBehaviour* cloud2Behaviour = cloud2Transform->Add<CloudBehaviour>();


	Transform2D* gameobject = CreateEntity({ 100, 1000 }, { 1,1 }, 0);
	PlayerBehaviour* playerBehaviour = gameobject->Add<PlayerBehaviour>();

	Transform2D* ball = CreateEntity({ 500, 500 }, { 1,1 }, 0);
	BallBehaviour* ballBehaviour = ball->Add<BallBehaviour>();

	Transform2D* UIScore = CreateEntity({ 100, 100 }, { 1,1 }, 0);
	ScoreBehaviour* scoreBehaviour = UIScore->Add<ScoreBehaviour>();

	Transform2D* UIButton = CreateEntity({ 500, 500 }, { 1,1 }, 0);
	ButtonBehaviour* buttonBehaviour = UIButton->Add<ButtonBehaviour>(); 

	const int rows = 10;
	const int cols = 20;
	const float brickWidth = 50.0f;
	const float brickHeight = 20.0f;
	const float gap = 20.0f;

	const float startX = 250.0f;
	const float startY = 500.0f;

	for (int row = 0; row < rows; ++row)
	{
		float y = startY - row * (brickHeight + gap);

		for (int col = 0; col < cols; ++col)
		{
			float x = startX + col * (brickWidth + gap);
			Transform2D* gameobject = CreateEntity({ x, y }, { 1, 1 }, 0);
			BrickBehaviour* brickBehaviour = gameobject->Add<BrickBehaviour>();
		}
	}
}
