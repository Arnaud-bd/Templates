#pragma once
#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Transform2D : public Component, public sf::Transformable
{
public:
	Transform2D();

	void Init(sf::Vector2f _position, sf::Vector2f _scale, float _rotation, int _ID);
	void Awake() override;
	void Start() override;

};

