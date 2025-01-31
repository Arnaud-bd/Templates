#pragma once
#include "../GameComponents/Scene.hpp"
class SceneManager
{
	Scene* m_CurrentScene;

public:

	Scene* GetCurrentScene();
};

