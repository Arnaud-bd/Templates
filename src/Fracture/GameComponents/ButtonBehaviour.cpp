#include "ButtonBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/TextRender.h"
#include <iostream>

ButtonBehaviour::ButtonBehaviour()
{
    m_transform = nullptr;
}

ButtonBehaviour::~ButtonBehaviour()
{
}

void ButtonBehaviour::Update(float _deltaTime)
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
                inst->m_GameState = m_setting;
            }
        }
    }
}

void ButtonBehaviour::Awake()
{  
}

void ButtonBehaviour::Start()
{ 
    m_transform = Get<Transform2D>();
}

void ButtonBehaviour::OnCollideEnter(Collider* _other)
{
}
