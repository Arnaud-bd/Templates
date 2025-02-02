#include "GameManager.h"
#include "../Components/Render.h"

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

    m_SceneManager = new SceneManager();
    Scene* s = new Scene();
    m_SceneManager->SetCurrentScene(s);

    SpriteRender* spren = new SpriteRender("D:\\---DEV---\\lyo-t1-amstrad-p7-05\\res\\Sprite\\ballBlue.png");
    Render* re = new Render(spren);
    s->Add(re);
    while (mWindow.isOpen())
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow.close();
        }

        m_SceneManager->GetCurrentScene()->Update();
        m_SceneManager->GetCurrentScene()->Drawing(&mWindow);
    }

    delete m_SceneManager;  
    delete s;  

    return 0;
}