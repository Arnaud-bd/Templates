#include "MenuScene.h"
#include "../GameComponents/TreeBehaviour.h"
#include "../GameComponents/SunBehaviour.h"
#include "../GameComponents/CastleBehaviour.h"
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
#include "../GameComponents/StartGameBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Render.h"
#include "../Components/Collider.h"

void MenuScene::Init()
{
	Transform2D* sunTransform = CreateEntity({ 75.f, 50.f }, { 1.f , 1.f }, 0.f);
	SunBehaviour* sunBehaviour = sunTransform->Add<SunBehaviour>();

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

	Transform2D* castleTransform = CreateEntity({ 1400, 450.f }, { 1.f , 1.f }, 0.f);
	CastleBehaviour* castleBehaviour = castleTransform->Add<CastleBehaviour>();

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

	Transform2D* startGameButton = CreateEntity({ 960, 400 }, { 1,1 }, 0); 
	StartGameBehaviour* buttonBehaviour = startGameButton->Add<StartGameBehaviour>();
	buttonBehaviour->m_text->ChangeText("P l a y");

	/*Transform2D* UIButton2 = CreateEntity({ 960, 600 }, { 1,1 }, 0);
	ButtonBehaviour* buttonBehaviour2 = UIButton2->Add<ButtonBehaviour>();
	buttonBehaviour2->m_text->ChangeText("F F");

	Transform2D* UIButton3 = CreateEntity({ 960, 800 }, { 1,1 }, 0);
	ButtonBehaviour* buttonBehaviour3 = UIButton3->Add<ButtonBehaviour>();
	buttonBehaviour3->m_text->ChangeText("S K I L L   I S S U E");*/

	Transform2D* titre = CreateEntity({ 950, 100 }, { 1.5f , 1.5f }, 0);
	SpriteRender* Titre = titre->Add<SpriteRender>();
	Titre->Init("../../../res/sprite/SUPER_SMASH _BRICKS.png");

	Transform2D* perso = CreateEntity({ 500, 900 }, { 1 , 1 }, 0);
	SpriteRender* Perso = perso->Add<SpriteRender>();
	Perso->Init("../../../res/sprite/persocool.png");
}
