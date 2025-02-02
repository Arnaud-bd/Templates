#include <SFML/Graphics.hpp>
#include <iostream>

class SpriteRender : public sf::Drawable 
{
public:
    sf::Sprite sprite;
    sf::Texture texture;

    SpriteRender(const std::string& texturePath);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
