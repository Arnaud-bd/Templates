#include "Collider.h"
#include "../Components/SpriteRender.h"

Collider::Collider()
{
}

void Collider::AddHitbox(sf::Vector2f _position, float _radius)
{
    sf::CircleShape* c = new sf::CircleShape();
    c->setRadius(_radius);
    c->setOrigin(c->getOrigin().x + _radius, c->getOrigin().y + _radius);
    std::vector<SpriteRender*> Sprites = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->GetAll<SpriteRender>();

    for (int i = 0; i < Sprites.size(); ++i)
    {
        if (Sprites[i]->GetID() == this->GetID())
        {
            c->setPosition(Sprites[i]->getPosition().x + _position.x, Sprites[i]->getPosition().y + _position.y);
        }
    }

    m_Hitboxs.push_back(c);
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

void Collider::Update()
{
    std::vector<Transform2D*> transforms = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->GetAll<Transform2D>();

    for (int i = 0; i < transforms.size(); ++i)
    {
        if (transforms[i]->GetID() == this->GetID())
        {
            for (int j = 0; j < m_Hitboxs.size(); ++j)
            {
                m_Hitboxs[j]->setPosition(transforms[i].m_position);
            }
        }
    }
}

void Collider::Awake()
{
}

void Collider::Start()
{
}
