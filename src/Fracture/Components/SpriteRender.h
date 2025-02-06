#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Render.h"

class SpriteRender : public Render
{
    sf::Sprite sprite;
    sf::Texture texture;

public:
    SpriteRender();

    void Init(const std::string& texturePath);

};