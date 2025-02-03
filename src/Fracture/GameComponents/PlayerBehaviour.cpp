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
	Collider* c = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->Add<Collider>();
	//Ici init les colliders
	SpriteRender* s = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->Add<SpriteRender>();
	s->Init("..\\..\\..\\res\\Sprite\\paddleBlu.png");
}

void PlayerBehaviour::Start()
{
}
