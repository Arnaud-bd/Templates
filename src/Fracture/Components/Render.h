#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Render : public sf::Drawable, public Component, public sf::Transformable
{
public:

    sf::Transform* transform;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
    virtual void move(const sf::Vector2f& newPosition);
    //Sert a rien...
    void Start();
    void Awake();

};
