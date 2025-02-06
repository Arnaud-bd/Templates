#include "Collider.h"
#include "../Components/Transform2D.h"
#include "../Components/SpriteRender.h"

Collider::Collider()
{
}

void Collider::AddHitbox(sf::Vector2f _position, float _radius)
{
    sf::CircleShape* c = new sf::CircleShape();
    c->setRadius(_radius);
    c->setOrigin(c->getOrigin().x + _radius, c->getOrigin().y + _radius);

    c->setPosition(m_transform->getPosition().x + _position.x, m_transform->getPosition().y + _position.y);

    m_Hitboxs.push_back(c);
    m_HitboxsRelative.push_back(_position);
}

bool Collider::IsCollide(Collider _other)
{
    for (int i = 0; i < m_Hitboxs.size(); i++)
    {
        for (int j = 0; j < _other.m_Hitboxs.size(); j++)
        {
            sf::Vector2f distanceVector = _other.m_Hitboxs[j]->getPosition() - m_Hitboxs[i]->getPosition();

            float distance = sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));

            if (distance <= m_Hitboxs[i]->getRadius() + _other.m_Hitboxs[j]->getRadius())
                return true;
        }
    }
    return false;
}

void Collider::OnCollideEnter(Collider* _other)
{

}

bool Collider::OnTriggerEnter(Collider _other)
{
    return false;
}

bool Collider::OnTriggerExit(Collider _other)
{
    return false;
}

bool Collider::OnTriggerStay(Collider _other)
{
    return false;
}

void Collider::Update(float _deltaTime)
{
    for (int j = 0; j < m_Hitboxs.size(); ++j)
    {
        m_Hitboxs[j]->setPosition(m_transform->getPosition() + m_HitboxsRelative[j]);
    }
}

void Collider::Awake()
{
}

void Collider::Start()
{
    m_transform = Get<Transform2D>();
}
