#pragma once
#include "SFML/Graphics.hpp"
#include "../Components/Behaviour.h"

class Collider : public Behaviour 
{
	std::vector<sf::CircleShape*> m_Hitboxs;
	std::vector<sf::Vector2f> m_HitboxsRelative;
	Transform2D* m_transform;
	bool m_IsTrigger;

public:
	Collider();
	virtual ~Collider();

	void AddHitbox(sf::Vector2f _position, float radius);

	bool IsCollide(Collider* _other);
	void OnCollideEnter(Collider* _other);

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;

	sf::Vector2f GetCollisionNormal(const sf::Vector2f& impactPoint) const;
};

