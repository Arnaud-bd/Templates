#pragma once
#include "SFML/Graphics.hpp"
#include "../Components/Component.hpp"

class Collider : public Component
{
	std::vector<sf::CircleShape*> m_Hitboxs;
	std::vector<sf::Vector2f> m_HitboxsRelative;
	bool m_IsTrigger;

public:
	Collider();

	void AddHitbox(sf::Vector2f _position, float radius);

	bool IsCollide(Collider _other);

	bool OnTriggerEnter(Collider _other);

	bool OnTriggerExit(Collider _other);

	bool OnTriggerStay(Collider _other);

	void Update();
	void Awake() override;
	void Start() override;
};

