#pragma once
#include "../GameComponents/Scene.hpp"
class SceneManager
{
	std::vector<Scene*> m_ScenesList;
	Scene* m_CurrentScene;

public:

	Scene* GetCurrentScene();
	void SetCurrentScene(Scene* CurrentScene);
};

