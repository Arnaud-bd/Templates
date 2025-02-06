#include "GameManager.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"

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

void GameManager::IncreaseScore(int _score)
{
    m_Score += _score;
}

int GameManager::GetScore()
{
    return m_Score;
}

sf::RenderWindow* GameManager::GetWindow()
{
    return &m_Window;
}

int GameManager::Loop()
{
    m_Window.create(sf::VideoMode(1000,1000), "Fracture", sf::Style::Close);
    m_Window.setPosition(sf::Vector2i(366, 0));

    m_SceneManager = new SceneManager();
    m_GameState = GAMESTATE::START;

    m_SceneManager->SetCurrentScene(m_GameState);

	sf::Clock clock;
    bool isPress = false;

    while (m_Window.isOpen())
    {
        std::cout << m_GameState;

        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        if (m_SceneManager->GetCurrentSceneState() != m_GameState)
        {
            m_SceneManager->SetCurrentSceneState(m_GameState);
            m_SceneManager->SetCurrentScene(m_GameState);
        }

        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window.close();
        }

        if (isPress == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            isPress = true;
            if (m_GameState < 2)
            {
                m_GameState = m_GameState + 1;
            }
            else 
            {
                m_GameState = 0;
            }
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            isPress = false;
        }

        m_SceneManager->GetCurrentScene()->Update(deltaTime);
        m_SceneManager->GetCurrentScene()->Physic();
        m_SceneManager->GetCurrentScene()->Drawing(&m_Window);
    }

    delete m_SceneManager;  
    return 0;
}

