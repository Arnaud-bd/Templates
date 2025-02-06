#pragma once
#include "../GameComponents/Scene.hpp"

class SceneManager
{
	int m_CurrentScene;
	std::map<int, Scene*> m_ScenesList;

public:
	SceneManager();

	void LoadScene();

	Scene* GetCurrentScene();
	int GetCurrentSceneState();
	void SetCurrentSceneState(int i);
	Scene* SetCurrentScene(int i);
	void AddScene(Scene* _Scene);
};

