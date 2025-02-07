#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Render.h"
#include <string>

class TextRender : public Render
{
    sf::Font m_font;
    sf::Text m_text;

public:
    TextRender();

    void Init();
    void ChangeText(const std::string& _text);
    void ChangeOrigin(float _x, float _y);
};