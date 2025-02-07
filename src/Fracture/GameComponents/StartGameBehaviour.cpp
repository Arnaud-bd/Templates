#include "StartGameBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"
#include <iostream>

StartGameBehaviour::StartGameBehaviour()
{
    m_transform = nullptr;
}

StartGameBehaviour::~StartGameBehaviour()
{
}

void StartGameBehaviour::Update(float _deltaTime)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        GameManager* inst = GameManager::GetInstance();
        sf::Vector2i globalPosition = sf::Mouse::getPosition();
        sf::Vector2f mousePos = static_cast<sf::Vector2f>(globalPosition);

        if (m_sprite->mTransform)
        {
            sf::Vector2f position = m_sprite->mTransform->getPosition();
            sf::Vector2u size = m_sprite->GetSprite()->getTexture()->getSize();

            sf::FloatRect bounds(position.x, position.y, size.x * 1.5, size.y * 1.5);

            if (bounds.contains(mousePos))
            {
                inst->m_GameState = inst->GameManager::GAMESTATE::LEVEL1;
            }
        }
    }
}

void StartGameBehaviour::Awake()
{
    m_sprite = Add<SpriteRender>();
    m_sprite->Init("..\\..\\..\\res\\Sprite\\button_rectangle_depth_flat.png");
    m_sprite->Awake();
    m_sprite->Start();

    m_text = Add<TextRender>();
    m_text->Init();
    m_text->Awake();
    m_text->Start();
}

void StartGameBehaviour::Start()
{
    m_transform = Get<Transform2D>();
    m_setting = 1;
}

void StartGameBehaviour::OnCollideEnter(Collider* _other)
{
}
