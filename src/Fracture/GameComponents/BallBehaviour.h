#pragma once
#include "../Components/Transform2D.h"
#include "../Components/Behaviour.h"

class BallBehaviour : public Behaviour
{
	sf::Vector2f m_Direction;
	sf::Vector2f m_PreviousPosition;

public:
	BallBehaviour();

	void Update(float _deltaTime) override;
	void Awake() override;
	void Start() override;
	void OnCollide() override;
};