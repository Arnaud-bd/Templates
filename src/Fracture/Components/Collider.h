#pragma once
#include "SFML/Graphics.hpp"
#include "../Components/Component.hpp"

class Collider : public Component
{
	std::vector<sf::CircleShape> m_Hitboxs;

public:
	Collider();

	bool IsCollide(Collider _other);

	bool OnTriggerEnter(Collider _other);
	bool OnTriggerExit(Collider _other);
	bool OnTriggerStay(Collider _other);

	void Awake() override;
	void Start() override;
};

 