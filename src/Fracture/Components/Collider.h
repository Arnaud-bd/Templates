#pragma once
#include "SFML/Graphics.hpp"
#include "../Components/Component.hpp"

class Collider : public Component
{
	std::vector<sf::CircleShape> m_Hitboxs;
	bool m_IsTrigger;

public:
	Collider();

	void Awake() override;
	void Start() override;
};

