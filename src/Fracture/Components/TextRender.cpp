#include "TextRender.h"


TextRender::TextRender()
{
    m_font = new sf::Font();
    m_text = new sf::Text();
    todraw = m_text;
} 

void TextRender::Init() 
{
    if (!m_font->loadFromFile("../../../res/GoodMatcha.otf"))
    {
        std::cout << "pouet" << std::endl;
    }

    m_text->setFont(*m_font);
    m_text->setString("BOUH");
    m_text->setCharacterSize(24); 
    m_text->setFillColor(sf::Color::White);
}

void TextRender::ChangeText(const std::string& _text)
{
    m_text->setString(_text); 
}




