#include <SFML/Graphics.hpp>
#include <iostream>
#include "Render.h"

class SpriteRender : public Render
{
public:

    sf::Sprite sprite;
    sf::Texture texture;

    SpriteRender();

    void Init(const std::string& texturePath);

};