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
    m_text.setString("BOUH");
    m_text.setCharacterSize(24); 
    m_text.setFillColor(sf::Color::White);
}

//Change le texte à afficher
void TextRender::ChangeText(const std::string& _text)
{
    m_text.setString(_text); 
}




