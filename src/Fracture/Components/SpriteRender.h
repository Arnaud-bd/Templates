#include <SFML/Graphics.hpp>
#include <iostream>
#include "Render.h"

class SpriteRender : public Render
{
public:

    sf::Sprite sprite;
    sf::Texture texture;

    SpriteRender(const std::string& texturePath);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
