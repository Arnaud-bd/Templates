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
	m_transform = Get<Transform2D>();
	SpriteRender* s = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->Add<SpriteRender>();
	//Est-ce que on crée aussi un Render ou le SpriteRender crée lui même son parent ?
}

void PlayerBehaviour::Start()
{
}
