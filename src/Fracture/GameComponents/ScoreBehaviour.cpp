#include "ScoreBehaviour.h"
#include "../Managers/GameManager.h"

ScoreBehaviour::ScoreBehaviour()
{
}

void ScoreBehaviour::Update(float _deltaTime)
{
    //Transform2D* Transform = Get<Transform2D>(); 
    t->ChangeText(std::to_string(GameManager::GetInstance()->GetScore()));
}

void ScoreBehaviour::Awake()
{
    t = Add<TextRender>();
    t->Init(); 
}

void ScoreBehaviour::Start()
{
}

void ScoreBehaviour::OnCollide()
{
}
