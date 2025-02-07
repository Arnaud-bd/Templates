#include "GameManager.h"
#include "SFML/Audio.hpp"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"
#include "../GameComponents/BallBehaviour.h"
#include "../GameComponents/PlayerBehaviour.h"

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

void GameManager::LooseALife()
{
    m_Lifes--;
    std::vector<BallBehaviour*> balls = m_SceneManager->GetCurrentScene()->GetAll<BallBehaviour>();
    for (int i = 0; i < balls.size(); ++i)
    {
        balls[i]->Reset();
    }

    std::vector<PlayerBehaviour*> players = m_SceneManager->GetCurrentScene()->GetAll<PlayerBehaviour>();
    for (int i = 0; i < players.size(); ++i)
    {
        players[i]->Reset();
    }
}

int GameManager::Loop()
{
    m_Window.create(sf::VideoMode(1000,1000), "Fracture", sf::Style::Close);
    m_Window.setPosition(sf::Vector2i(366, 0));

    sf::Music music;
    if (!music.openFromFile("../../../res/PawsontheBeat.mp3"))
    {
    }
    music.play();
    music.setLoop(true); 
    music.setVolume(25);
        
    m_SceneManager = new SceneManager();
    m_GameState = GAMESTATE::START;
    m_SceneManager->SetCurrentScene(m_GameState);

	sf::Clock clock;

    while (m_Window.isOpen())
    {
        if (m_Lifes == 0)
        {
            m_GameState = GAMESTATE::LOOSE;
            exit(1);
        }

        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window.close();
        }

        if (m_SceneManager->GetCurrentSceneState() != m_GameState)
        {
            m_SceneManager->SetCurrentSceneState(m_GameState);
            m_SceneManager->SetCurrentScene(m_GameState);
        }

        m_SceneManager->GetCurrentScene()->Update(deltaTime);
        m_SceneManager->GetCurrentScene()->Physic();
        m_SceneManager->GetCurrentScene()->Drawing(&m_Window);
    }

    delete m_SceneManager;  
    return 0;
}

