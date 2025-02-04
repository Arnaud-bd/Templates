#include "GameManager.h"
#include "../Components/SpriteRender.h"

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
    m_Window.create(sf::VideoMode(), "Fracture", sf::Style::Fullscreen);
    m_Window.setPosition(sf::Vector2i(366, 0));

    m_SceneManager = new SceneManager();
    Scene* s = new Scene();
    m_SceneManager->SetCurrentScene(s);
    s->Init();

	sf::Clock clock;

    std::vector<Component*> vect = m_SceneManager->GetCurrentScene()->GetAll<Component>();
    for (int i = 0; i < vect.size(); i++)
    {
        vect[i]->Start();
    }

    while (m_Window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window.close();
        }

        m_SceneManager->GetCurrentScene()->Update(deltaTime);
        m_SceneManager->GetCurrentScene()->Physic();
        m_SceneManager->GetCurrentScene()->Drawing(&m_Window);
    }

    delete s;
    delete m_SceneManager;  
    return 0;
}