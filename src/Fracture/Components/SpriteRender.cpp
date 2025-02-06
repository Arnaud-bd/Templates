#include "SpriteRender.h"

SpriteRender::SpriteRender() : Render()
{
}

sf::Sprite* SpriteRender::GetSprite()
{
    return &sprite;
}

void SpriteRender::Init(const std::string& texturePath) 
{
    if (!texture.loadFromFile(texturePath))
    {
        std::cerr << "Erreur de chargement de la texture : " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    todraw = &sprite;
}