#include "TextRender.h"

TextRender::TextRender()
{
    todraw = &m_text;
} 

//Initialise le text
void TextRender::Init() 
{
    if (!m_font.loadFromFile("../../../res/GoodMatcha.otf"))
    {
    }
    m_text.setFont(m_font);
    m_text.setCharacterSize(35); 
    m_text.setFillColor(sf::Color(199,0,33,255));
    m_text.setOutlineColor(sf::Color::White);
    m_text.setOutlineThickness(3);
}

//Change le texte à afficher
void TextRender::ChangeText(const std::string& _text)
{
    m_text.setString(_text); 
    m_text.setOrigin(m_text.getGlobalBounds().getSize().x / 2, m_text.getGlobalBounds().getSize().y / 2);
}




