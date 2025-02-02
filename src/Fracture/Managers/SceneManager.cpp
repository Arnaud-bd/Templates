#include "SceneManager.h"


Scene* SceneManager::GetCurrentScene()
{
	return m_CurrentScene;
}

void SceneManager::SetCurrentScene(Scene* CurrentScene)
{
	m_CurrentScene = CurrentScene;
}
