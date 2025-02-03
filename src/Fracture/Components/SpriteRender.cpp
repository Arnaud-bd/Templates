#include "SpriteRender.h"

SpriteRender::SpriteRender() : Render()
{
}

void SpriteRender::Init(const std::string& texturePath)
{
    if (!texture.loadFromFile(texturePath))
    {
        std::cerr << "Erreur de chargement de la texture : " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
}

void SpriteRender::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform = getTransform();
    target.draw(sprite, states);
}

void SpriteRender::move(const sf::Vector2f& newPosition)
{
    sprite.setPosition(newPosition);
}