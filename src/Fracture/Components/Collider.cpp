
#include "Collider.h"

Collider::Collider()
{
}

bool Collider::IsCollide(Collider _other)
{
    for (int i = 0; i < m_Hitboxs.size(); i++)
    {
        for (int j = 0; j < _other.m_Hitboxs.size(); j++)
        {
            sf::Vector2f distanceVector = _other.m_Hitboxs[j].getPosition() - m_Hitboxs[i].getPosition(); 

            float distance = sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));

            if (distance <= m_Hitboxs[i].getRadius() + _other.m_Hitboxs[j].getRadius())
                return true;
        }
    }
    return false;
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

void Collider::Awake()
{
}

void Collider::Start()
{
}
