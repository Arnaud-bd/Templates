#include "TextRender.h"
TextRender::TextRender()
{
    todraw = &m_text;
} 

void TextRender::Init() 
{
    if (!m_font.loadFromFile("../../../res/GoodMatcha.otf"))
    {
    }
    m_text.setFont(m_font);
    m_text.setCharacterSize(24); 
    m_text.setFillColor(sf::Color::White);

}

void TextRender::ChangeText(const std::string& _text)
{
    m_text.setString(_text); 
    m_text.setOrigin(m_text.getGlobalBounds().getSize().x / 2, m_text.getGlobalBounds().getSize().y / 2);
}




