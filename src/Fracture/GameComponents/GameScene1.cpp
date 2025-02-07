#include "GameScene1.h"
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

void GameScene1::Init()
{

	Transform2D* cLTransform = CreateEntity({ 512.f, 400.f }, { 1.f , 1.f }, 0.f);
	CloudLayer1Behaviour* cloudLayer1Behaviour = cLTransform->Add<CloudLayer1Behaviour>();

	Transform2D* cLTransform2 = CreateEntity({ 1536.f, 400.f }, { 1.f , 1.f }, 0.f);
	CloudLayer1Behaviour* cloudLayer1Behaviour2 = cLTransform2->Add<CloudLayer1Behaviour>();

	Transform2D* cL2Transform = CreateEntity({ 512.f, 500.f }, { 1.f , 1.f }, 0.f);
	CloudLayer1Behaviour* cloudLayer2Behaviour = cL2Transform->Add<CloudLayer1Behaviour>();

	Transform2D* cL2Transform2 = CreateEntity({ 1536.f, 500.f }, { 1.f , 1.f }, 0.f);
	CloudLayer1Behaviour* cloudLayer2Behaviour2 = cL2Transform2->Add<CloudLayer1Behaviour>();

	Transform2D* cloud1Transform = CreateEntity({ 200.f, 150.f }, { 0.6f , 0.6f }, 0.f);
	CloudBehaviour* cloud1Behaviour = cloud1Transform->Add<CloudBehaviour>();

	Transform2D* cloud2Transform = CreateEntity({ 1620.f, 150.f }, { 0.6f , 0.6f }, 0.f);
	CloudBehaviour* cloud2Behaviour = cloud2Transform->Add<CloudBehaviour>();

	Transform2D* gLTransform = CreateEntity({ 512.f, 650.f }, { 1.f , 1.f }, 0.f);
	GroundLayer1Behaviour* groundLayer1Behaviour = gLTransform->Add<GroundLayer1Behaviour>();

	Transform2D* gLTransform2 = CreateEntity({ 1536.f, 650.f }, { 1.f , 1.f }, 0.f);
	GroundLayer1Behaviour* groundLayer1Behaviour2 = gLTransform2->Add<GroundLayer1Behaviour>();

	Transform2D* bush2Transform = CreateEntity({ 1350.f, 610.f }, { 2.f,2.f }, 0.f);
	BushBehaviour* bush2Behaviour = bush2Transform->Add<BushBehaviour>();

	Transform2D* tree1Transform = CreateEntity({ 550.f, 600.f }, { 0.6f, 0.6f }, 350.f);
	TreeBehaviour* tree1Behaviour = tree1Transform->Add<TreeBehaviour>();

	Transform2D* hillsTransform = CreateEntity({ 512.f, 750.f }, { 1.f , 1.f }, 0.f);
	HillsBehaviour* hillsBehaviour = hillsTransform->Add<HillsBehaviour>();

	Transform2D* hillsTransform2 = CreateEntity({ 1536.f, 750.f }, { 1.f , 1.f }, 0.f);
	HillsBehaviour* hillsBehaviour2 = hillsTransform2->Add<HillsBehaviour>();

	Transform2D* tree2Transform = CreateEntity({ 1820.f, 810.f }, { 0.8f , 0.8f }, 5.f);
	TreeBehaviour* tree2Behaviour = tree2Transform->Add<TreeBehaviour>();

	Transform2D* bush1Transform = CreateEntity({ 150.f, 750.f }, { 2.f,2.f }, 0.f);
	BushBehaviour* bush1Behaviour = bush1Transform->Add<BushBehaviour>();

	Transform2D* gL2Transform = CreateEntity({ 512.f, 950.f }, { 1.f , 2.f }, 0.f);
	GroundLayer2Behaviour* groundLayer2Behaviour = gL2Transform->Add<GroundLayer2Behaviour>();

	Transform2D* gL2Transform2 = CreateEntity({ 1536.f, 950.f }, { 1.f , 2.f }, 0.f);
	GroundLayer2Behaviour* groundLayer2Behaviour2 = gL2Transform2->Add<GroundLayer2Behaviour>();

	Transform2D* bush3Transform = CreateEntity({ 1800.f, 1010.f }, { 2.5f , 2.5f }, 0.f);
	BushBehaviour* bush3Behaviour = bush3Transform->Add<BushBehaviour>();

	Transform2D* tree3Transform = CreateEntity({ 15.f, 1085.f}, { 1.5f , 1.5f }, 0.f);
	TreeBehaviour* tree3Behaviour = tree3Transform->Add<TreeBehaviour>();

	Transform2D* gameobject = CreateEntity({ 860.f, 950.f }, { 1.5f , 1.5f }, 0.f);
	PlayerBehaviour* playerBehaviour = gameobject->Add<PlayerBehaviour>();

	Transform2D* ball = CreateEntity({ 860.f, 920.f }, { 1.5f , 1.5f }, 0.f);
	BallBehaviour* ballBehaviour = ball->Add<BallBehaviour>();

	Transform2D* UIScore = CreateEntity({ 100.f, 100.f }, { 1.f,1.f }, 0.f);
	ScoreBehaviour* scoreBehaviour = UIScore->Add<ScoreBehaviour>();

	/*Transform2D* UIButton = CreateEntity({ 500, 500 }, { 1,1 }, 0);
	ButtonBehaviour* buttonBehaviour = UIButton->Add<ButtonBehaviour>(); */

	const int rows = 8;
	const int cols = 15;
	const float brickWidth = 90.0f;
	const float brickHeight = 40.0f;
	const float gap = 15.0f;

	const float startX = 225.0f;
	const float startY = 500.0f;

	for (int row = 0; row < rows; ++row)
	{
		float y = startY - row * (brickHeight + gap);

		for (int col = 0; col < cols; ++col)
		{
			float x = startX + col * (brickWidth + gap);
			Transform2D* gameobject = CreateEntity({ x, y }, { 1.5f , 1.5f }, 0.f);
			BrickBehaviour* brickBehaviour = gameobject->Add<BrickBehaviour>();
		}
	}
}
