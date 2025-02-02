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
	mWindow.create(sf::VideoMode(1188, 1000), "Fracture", sf::Style::Close);
	mWindow.setPosition(sf::Vector2i(366, 0));

	m_SceneManager = new SceneManager;
	Scene* s = new Scene;
	m_SceneManager->SetCurrentScene(s);

	sf::Clock clock;

	while (true)
	{
		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();

		m_SceneManager->GetCurrentScene()->Update(deltaTime);
		//m_SceneManager->GetCurrentScene()->draw(); 
	}

	return 0;
}
