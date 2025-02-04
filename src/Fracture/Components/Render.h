#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Render :  public Component, public sf::Drawable
{
public:
    sf::Drawable* todraw;
    sf::Transform* transform;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

    void Start();
    void Awake();

};
