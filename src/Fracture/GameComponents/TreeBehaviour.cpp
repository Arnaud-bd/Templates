#include "TreeBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

TreeBehaviour::TreeBehaviour()
{
}

void TreeBehaviour::Update(float _deltaTime)
{
    float currentRotation = m_Transform->getRotation();
    if (currentRotation >= 5.f && currentRotation <= 100.f)
    {
        m_RotationSens = -1.f;
    }
    else if (currentRotation <= 355.f && currentRotation >= 100.f)
    {
        m_RotationSens = 1.f;
    }

    m_Transform->setRotation(currentRotation + 1.f * m_RotationSens * _deltaTime);
}

void TreeBehaviour::Awake()
{
    SpriteRender* tree = Add<SpriteRender>();
    tree->Init("..\\..\\..\\res\\Sprite\\tree.png");
    tree->Awake();
}

void TreeBehaviour::Start()
{
    m_Transform = Get<Transform2D>();
    m_Transform->setOrigin(0.f, 254.f);
}

void TreeBehaviour::OnCollideEnter(Collider* _other)
{

}
