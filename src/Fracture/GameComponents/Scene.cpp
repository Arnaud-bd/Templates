#include "Scene.hpp"
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

//Détruit tous les components du même ID 
void Scene::RemoveAllComponent()
{
	for (int i = 0; i < m_ComponentsList.size(); i++)
	{
		delete(m_ComponentsList[i]);
	}
	m_ComponentsList.clear();
	m_CurrentID = 0;
}

//Crée un transform2D et le renvoie
Transform2D* Scene::CreateEntity(sf::Vector2f _position, sf::Vector2f _scale, float _rotation)
{
	Transform2D* transform = new Transform2D();
	transform->Init(_position, _scale, _rotation, m_CurrentID);

	transform->Awake();
	m_ComponentsList.push_back(transform);

	m_CurrentID++;

	return transform;
}

//Détruit les éléments à détruire
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

//Check les collisions entre tous les colliders de la scène
void Scene::Physic()
{
	std::vector<std::pair<Component*, Component*>> newColliders;
	std::vector<Collider*> colliders = this->GetAll<Collider>();
	for (int i = 0; i < colliders.size(); ++i)
	{
		for (int j = i + 1; j < colliders.size(); ++j) 
		{
			if (colliders[i] != colliders[j] && colliders[i]->IsCollide(colliders[j]))
			{
				std::pair<Collider*, Collider*> c (colliders[i], colliders[j]);

				if (std::find(m_lastColliders.begin(), m_lastColliders.end(), c) == m_lastColliders.end())
				{
					colliders[i]->Get<Behaviour>()->OnCollideEnter(colliders[j]);
					colliders[j]->Get<Behaviour>()->OnCollideEnter(colliders[i]);
				}

				newColliders.push_back(c);
			}
		}
	}

	m_lastColliders = newColliders;

	Destroy();
}

//appele tous les draw de la scène
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