#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Render : public sf::Drawable, public Component
{
public:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

    //Sert a rien...
    void Start();
    void Awake();
};
