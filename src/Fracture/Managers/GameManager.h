#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class GameManager
{
	static GameManager* mInstance;
	sf::RenderWindow mWindow; //?
	SceneManager* mSceneManager;

public:
	static GameManager* GetInstance();
};

