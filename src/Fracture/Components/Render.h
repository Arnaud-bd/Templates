#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteRender.h"
#include "Component.hpp"

class Render : public sf::Drawable, public Component
{
public:
    SpriteRender* m_render;

    Render(SpriteRender* spriteRender);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void Start();
    void Awake();
};
