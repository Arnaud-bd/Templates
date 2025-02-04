#include "Transform2D.h"

Transform2D::Transform2D()
{
}

void Transform2D::Init(sf::Vector2f _position, float _scale, float _rotation, int _ID) //Pas besoin de tout ça, on fait hériter le transform2D de sf::Transformable
{
	m_Position = _position;
	m_Scale = _scale;
	m_Rotation = _rotation;
	SetID(_ID);
}

void Transform2D::Awake()
{

}

void Transform2D::Start()
{
}
