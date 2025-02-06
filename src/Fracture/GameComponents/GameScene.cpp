#include "GameScene.h"
#include "../GameComponents/BackGroundBehaviour.h"
#include "../GameComponents/PlayerBehaviour.h"
#include "../GameComponents/BrickBehaviour.h"
#include "../GameComponents/BallBehaviour.h"
#include "../GameComponents/ScoreBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Render.h"
#include "../Components/Collider.h"

void GameScene::Init()
{
	Transform2D* backGround = CreateEntity({ 500, 594 }, { 1,1 }, 0);
	BackGroundBehaviour* backGroundBehaviour = backGround->Add<BackGroundBehaviour>();

	Transform2D* gameobject = CreateEntity({ 100, 800 }, { 1,1 }, 0);
	PlayerBehaviour* playerBehaviour = gameobject->Add<PlayerBehaviour>();

	Transform2D* ball = CreateEntity({ 500, 500 }, { 1,1 }, 0);
	BallBehaviour* ballBehaviour = ball->Add<BallBehaviour>();

	Transform2D* UIScore = CreateEntity({ 100, 100 }, { 1,1 }, 0);
	ScoreBehaviour* scoreBehaviour = UIScore->Add<ScoreBehaviour>();

	const int rows = 10;
	const int cols = 10;
	const float brickWidth = 50.0f;
	const float brickHeight = 20.0f;
	const float gap = 20.0f;

	const float startX = 200.0f;
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
