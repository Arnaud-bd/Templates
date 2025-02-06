#include "SceneManager.h"
#include "GameManager.h"
#include "../GameComponents/GameScene.h"
#include "../Components/Component.hpp"

SceneManager::SceneManager()
{
	for (int i = 0; i < GameManager::GAMESTATE::LOOSE; ++i)
	{
		Scene* s = new GameScene();
		AddScene(s);
		m_ScenesList[i] = s;
	}
}

void SceneManager::LoadScene()
{
	m_ScenesList[m_CurrentScene]->Init();
	std::vector<Component*> vect = m_ScenesList[m_CurrentScene]->GetAll<Component>();
	for (int i = 0; i < vect.size(); i++)
	{
		vect[i]->Start();
	}
}

Scene* SceneManager::GetCurrentScene()
{
	return m_ScenesList[m_CurrentScene];
}

int SceneManager::GetCurrentSceneState()
{
	return m_CurrentScene;
}

void SceneManager::SetCurrentSceneState(int i)
{
	 m_CurrentScene = i;
}

Scene* SceneManager::SetCurrentScene(int i)
{
	return m_ScenesList[m_CurrentScene] = m_ScenesList.find(i)->second;
}

void SceneManager::AddScene(Scene* _Scene)
{
	m_ScenesList[m_ScenesList.size()] = _Scene; 
}
