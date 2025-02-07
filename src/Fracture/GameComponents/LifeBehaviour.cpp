#include "LifeBehaviour.h"

LifeBehaviour::LifeBehaviour()
{
}

void LifeBehaviour::Update(float _deltaTime)
{
	t->ChangeText(std::to_string(GameManager::GetInstance()->GetLife()));
}

void LifeBehaviour::Awake()
{
	t = Add<TextRender>();
	t->Init();
}

void LifeBehaviour::Start()
{
}

void LifeBehaviour::OnCollideEnter(Collider* _other)
{
}
