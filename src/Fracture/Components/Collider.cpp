#include "Collider.h"
#include "../Components/Transform2D.h"
#include "../Components/SpriteRender.h"

Collider::Collider()
{

}

Collider::~Collider()
{
    for (int i = 0; i < m_Hitboxs.size(); ++i) {
        delete m_Hitboxs[i];
    }
}

//Ajoute une hitbox au vecteur
void Collider::AddHitbox(sf::Vector2f _position, float _radius)
{
    sf::CircleShape* c = new sf::CircleShape();
    c->setRadius(_radius);
    c->setOrigin(c->getOrigin().x + _radius, c->getOrigin().y + _radius);

    c->setPosition(m_transform->getPosition().x + _position.x, m_transform->getPosition().y + _position.y);

    m_Hitboxs.push_back(c);
    m_HitboxsRelative.push_back(_position);
}

//Vérifie si il y a collision entre deux hitboxs
bool Collider::IsCollide(Collider* _other)
{
    for (int i = 0; i < m_Hitboxs.size(); i++)
    {
        for (int j = 0; j < _other->m_Hitboxs.size(); j++)
        {
            sf::Vector2f distanceVector = _other->m_Hitboxs[j]->getPosition() - m_Hitboxs[i]->getPosition();

            float distance = sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));

            if (distance <= m_Hitboxs[i]->getRadius() + _other->m_Hitboxs[j]->getRadius())
                return true;
        }
    }
    return false;
}

void Collider::OnCollideEnter(Collider* _other)
{

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

sf::Vector2f Collider::GetCollisionNormal(const sf::Vector2f& impactPoint) const
{
    sf::Vector2f center = m_transform->getPosition();
    sf::Vector2f normal = impactPoint - center;

    float length = std::sqrt(normal.x * normal.x + normal.y * normal.y);
    if (length != 0)
        normal /= length;
    else
        normal = sf::Vector2f(0, -1); // Valeur par défaut si problème

    return normal;
}
