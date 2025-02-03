#include "SceneManager.h"


Scene* SceneManager::GetCurrentScene()
{
	return m_ScenesList[0];
}

void SceneManager::SetCurrentScene(Scene* CurrentScene)
{
	m_ScenesList.push_back(CurrentScene);
	m_CurrentScene = CurrentScene;
}
