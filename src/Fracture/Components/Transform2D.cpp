#include "Transform2D.h"

Transform2D::Transform2D(sf::Vector2f _position, float _scale, float _rotation)
{
	m_Position = _position;
	m_Scale = _scale;
	m_Rotation = _rotation;
}
