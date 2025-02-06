#include "Scene.hpp"
#include "../GameComponents/BackGroundBehaviour.h"
#include "../GameComponents/PlayerBehaviour.h"
#include "../GameComponents/BrickBehaviour.h"
#include "../GameComponents/BallBehaviour.h"
#include "../GameComponents/ScoreBehaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Render.h"
#include "../Components/Collider.h"

Scene::Scene()
{
	
}

Scene::~Scene()
{
	for (int i = 0; i < m_ComponentsList.size(); i++)
	{
		delete(m_ComponentsList[i]);
	}
}

void Scene::AddComponent(Component* _component)
{
	m_ComponentsList.push_back(_component);
}

void Scene::RemoveComponent(Component* _component)
{
	int id = _component->GetID();
	for (int i = m_ComponentsList.size() - 1; i >= 0; --i)
	{
		if (m_ComponentsList[i]->GetID() == id)
		{
			m_destroyer.push_back(m_ComponentsList[i]);
		}
	}
}

void Scene::RemoveAllComponent()
{
	for (int i = 0; i < m_ComponentsList.size(); i++)
	{
		delete(m_ComponentsList[i]);
	}
}

Transform2D* Scene::CreateEntity(sf::Vector2f _position, sf::Vector2f _scale, float _rotation)
{
	Transform2D* transform = new Transform2D();
	transform->Init(_position, _scale, _rotation, m_ComponentsList.size()+1);

	transform->Awake();
	m_ComponentsList.push_back(transform);

	return transform;
}

void Scene::Destroy()
{
	for (int i = m_ComponentsList.size() - 1; i > 0 ; --i)
	{
		if (m_ComponentsList[i]->IsDestroy())
		{
			delete(m_ComponentsList[i]);
			m_ComponentsList.erase(m_ComponentsList.begin() + i);
		}
	}
}

void Scene::Update(float _deltaTime)
{
	for (int i = m_ComponentsList.size() - 1; i >= 0; --i)
	{
		if (Behaviour* b = dynamic_cast<Behaviour*>(m_ComponentsList[i]))
			b->Update(_deltaTime);
	}
}

void Scene::Physic()
{
	std::vector<Collider*> colliders = this->GetAll<Collider>();
	for (int i = 0; i < colliders.size(); ++i)
	{
		for (int j = i + 1; j < colliders.size(); ++j) 
		{
			if (colliders[i]->IsCollide(*colliders[j]) && colliders[i] != colliders[j])
			{
				colliders[i]->Get<Behaviour>()->OnCollide();
				colliders[j]->Get<Behaviour>()->OnCollide();
			}
		}
	}

	Destroy();
}

void Scene::Drawing(sf::RenderWindow* _render)
{
    _render->clear(sf::Color(207, 239, 252, 255));

   std::vector<Render*> renders = GetAll<Render>();

    for (int i = 0; i < renders.size(); ++i) 
	{
		_render->draw(*renders[i]);
    }

    _render->display();
}