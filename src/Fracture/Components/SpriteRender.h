#include <SFML/Graphics.hpp>
#include <iostream>
#include "Render.h"

class SpriteRender : public Render
{
public:

    sf::Sprite sprite;
    sf::Texture texture;

    SpriteRender();

    void Init(const std::string& texturePath, sf::Vector2f _Position, sf::Vector2f _scale);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void move(const sf::Vector2f& newPosition);
};
