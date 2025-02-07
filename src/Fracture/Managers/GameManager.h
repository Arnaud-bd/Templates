#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include <map>

class GameManager
{
	static GameManager* m_Instance;
	sf::RenderWindow m_Window;
	SceneManager* m_SceneManager;

	int m_Score;

public:

	int m_GameState;

	enum GAMESTATE
	{
		START,
		LEVEL1,
		LEVEL2, 
		WIN,
		LOOSE,
	};

	static GameManager* GetInstance();
	SceneManager* GetSceneManager();
	int Loop();
	void IncreaseScore(int _score);
	int GetScore();
	sf::RenderWindow* GetWindow();

};

