#include "TextRender.h"


TextRender::TextRender()
{
    m_font = new sf::Font();
    m_text = new sf::Text();
} 

void TextRender::Init() 
{
    if (!m_font->loadFromFile("../../../res/GoodMatcha.otf"))
    {
    }
    m_text = std::string&("100");
    m_text->setFont(*m_font);
    m_text->setCharacterSize(24); 
    m_text->setFillColor(sf::Color::White); 

    todraw = m_text; 
}

void TextRender::ChangeText(const std::string& _text)
{
    m_text->setString(_text); 
}




