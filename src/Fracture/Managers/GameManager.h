#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "../GameComponents/Scene.hpp"

class GameManager
{
	static GameManager* m_Instance;
	sf::RenderWindow m_Window; //?
	SceneManager* m_SceneManager;

public:
	static GameManager* GetInstance();
	SceneManager* GetSceneManager();
	int Loop();

};

