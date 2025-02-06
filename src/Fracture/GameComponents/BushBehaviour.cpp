#include "BushBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"

BushBehaviour::BushBehaviour()
{
}

void BushBehaviour::Update(float _deltaTime)
{
    if (m_Transform->getScale().x >= 1.2f)
    {
        m_ScaleSens = -1.f;
    }
    else if (m_Transform->getScale().x <= 1.0f)
    {
        m_ScaleSens = 1.f;
    }

    m_Transform->setScale(m_Transform->getScale().x + 0.05f * m_ScaleSens * _deltaTime, m_Transform->getScale().y + 0.0005f * m_ScaleSens * _deltaTime);
}

void BushBehaviour::Awake()
{
    SpriteRender* bush = Add<SpriteRender>();
    bush->Init("..\\..\\..\\res\\Sprite\\bush.png");
    bush->Awake();
}

void BushBehaviour::Start()
{
    m_Transform = Get<Transform2D>();
}

void BushBehaviour::OnCollideEnter(Collider* _other)
{

}
