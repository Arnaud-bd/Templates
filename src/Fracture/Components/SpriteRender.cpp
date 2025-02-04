#include "SpriteRender.h"

SpriteRender::SpriteRender() : Render()
{
}

void SpriteRender::Init(const std::string& texturePath, sf::Vector2f _Position, sf::Vector2f _scale)
{
    if (!texture.loadFromFile(texturePath))
    {
        std::cerr << "Erreur de chargement de la texture : " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(_Position);
    sprite.setScale(_scale);
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