#include "Render.h"

void Render::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_render)
    {
        m_render->draw(target, states);
    }
}

void Render::Start()
{
}

void Render::Awake()
{
}

Render::Render(SpriteRender* spriteRender) : m_render(spriteRender)
{

}
