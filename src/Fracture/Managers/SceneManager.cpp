#include "SceneManager.h"
#include "GameManager.h"
#include "../GameComponents/GameScene1.h"
#include "../GameComponents/MenuScene.h"
#include "../GameComponents/WinScene.h"
#include "../GameComponents/LoseScene.h"
#include "../Components/Component.hpp"

SceneManager::SceneManager()
{
	Scene* s = new GameScene1();
	AddScene(s);
	m_ScenesList[GameManager::GAMESTATE::LEVEL1] = s;

	Scene* s1 = new MenuScene();
	AddScene(s1);
	m_ScenesList[GameManager::GAMESTATE::START] = s1;

	Scene* s2 = new LoseScene();
	AddScene(s2); 
	m_ScenesList[GameManager::GAMESTATE::LOOSE] = s2;

	Scene* s3 = new WinScene();
	AddScene(s3); 
	m_ScenesList[GameManager::GAMESTATE::WIN] = s3;

	m_CurrentScene = GameManager::GAMESTATE::START; 
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

//Défini la scène actuelle
Scene* SceneManager::SetCurrentScene(int i)
{
	m_ScenesList[m_CurrentScene]->RemoveAllComponent();
	m_ScenesList[m_CurrentScene] = m_ScenesList.find(i)->second; 
	m_ScenesList[m_CurrentScene]->Init();
	std::vector<Component*> vect = m_ScenesList[m_CurrentScene]->GetAll<Component>();
	for (int i = 0; i < vect.size(); i++)
	{
		vect[i]->Start();
	}
	return m_ScenesList[m_CurrentScene];
}

void SceneManager::AddScene(Scene* _Scene)
{
	m_ScenesList[m_ScenesList.size()] = _Scene; 
}
