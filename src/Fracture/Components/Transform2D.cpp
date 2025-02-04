#include "Transform2D.h"

Transform2D::Transform2D()
{
}

void Transform2D::Init(sf::Vector2f _position, sf::Vector2f _scale, float _rotation, int _ID)
{
	setPosition(_position);
	setRotation(_rotation);
	setScale(_scale);
	SetID(_ID);
}

void Transform2D::Awake()
{

}

void Transform2D::Start()
{
}
