#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Transform2D : public Component
{
public:
	sf::Vector2f m_Position;
	float m_Scale;
	float m_Rotation;

	Transform2D();

	void Init(sf::Vector2f _position, float _scale, float _rotation, int _ID);
	void Awake() override;
	void Start() override;

};

