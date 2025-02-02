#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Transform2D : public Component
{
	sf::Vector2f m_Position;
	float m_Scale;
	float m_Rotation;

public:
	Transform2D(sf::Vector2f _position, float _scale, float _rotation);
};

