#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class GameManager
{
	static GameManager* m_Instance;
	sf::RenderWindow m_Window;
	SceneManager* m_SceneManager;
	enum GAMESTATE 
	{
		START,
		PLAY,
		WIN,
		LOOSE,
	};
	int m_Score;
	int m_NbBalls;
	int m_Lifes;

public:
	static GameManager* GetInstance();
	SceneManager* GetSceneManager();
	int Loop();
	void IncreaseScore(int _score);
	int GetScore();

};

