#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Render :  public Component, public sf::Drawable
{
public:
    sf::Drawable* todraw;
    Transform2D* mTransform;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void Start();
    void Awake();

};
