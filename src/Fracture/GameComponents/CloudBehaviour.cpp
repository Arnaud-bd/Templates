#include "CloudBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../Components/Transform2D.h"

CloudBehaviour::CloudBehaviour()
{
}

void CloudBehaviour::Update(float _deltaTime)
{
    m_Transform->move(-15.f * _deltaTime, 0.f);

    if (m_Transform->getPosition().x <= -122.f)
    {
        m_Transform->setPosition(GameManager::GetInstance()->GetWindow()->getSize().x + 122.f, m_Transform->getPosition().y);
    }
}

void CloudBehaviour::Awake()
{
    SpriteRender* cloud = Add<SpriteRender>();
    cloud->Init("..\\..\\..\\res\\Sprite\\cloud.png");
    cloud->Awake();
}

void CloudBehaviour::Start()
{
    m_Transform = Get<Transform2D>();
}

void CloudBehaviour::OnCollideEnter(Collider* _other)
{

}
