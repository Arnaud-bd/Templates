#include "GameManager.h"

GameManager* GameManager::m_Instance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new GameManager();
	}

	return m_Instance;
}

SceneManager* GameManager::GetSceneManager()
{
	return m_SceneManager;
}

int GameManager::Loop()
{

	sf::RenderWindow mWindow;

	// création de la fenêtre
	mWindow.create(sf::VideoMode(1188, 1000), "Poop Them Up", sf::Style::Close);
	mWindow.setPosition(sf::Vector2i(366, 0));

	while (true)
	{

	}

	return 0;
}
