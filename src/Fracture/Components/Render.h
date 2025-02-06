#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Render :  public Component, public sf::Drawable
{
protected:

    sf::Drawable* todraw;
    Transform2D* mTransform;

public:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void Start();
    void Awake();

};
