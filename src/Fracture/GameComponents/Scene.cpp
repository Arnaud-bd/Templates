#include "Scene.hpp"
#include "../GameComponents/BackGroundBehaviour.h"
#include "../GameComponents/PlayerBehaviour.h"
#include "../GameComponents/BrickBehaviour.h"
#include "../GameComponents/BallBehaviour.h"
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

void Scene::Init()
{

	Transform2D* backGround = CreateEntity({ 500, 594 }, {1,1}, 0);
	BackGroundBehaviour* backGroundBehaviour = backGround->Add<BackGroundBehaviour>();

	Transform2D* gameobject = CreateEntity({ 100, 800 }, { 1,1 }, 0);
	PlayerBehaviour* playerBehaviour = gameobject->Add<PlayerBehaviour>(); // Création du joueurs

	const int rows = 10;				// Nombre de rang�es de briques
	const int cols = 10;				// Nombre de briques par rang�e
	const float brickWidth = 50.0f;		// Largeur de la brique
	const float brickHeight = 20.0f;	// Hauteur de la brique
	const float gap = 30.0f;			// Espace entre les briques

	const float startX = 200.0f;
	const float startY = 500.0f;

	for (int row = 0; row < rows; ++row)
	{
		float y = startY - row * (brickHeight + gap);

		for (int col = 0; col < cols; ++col)
		{
			float x = startX + col * (brickWidth + gap);
			Transform2D* gameobject = CreateEntity({ x, y }, {1, 1}, 0);
			BrickBehaviour* brickBehaviour = gameobject->Add<BrickBehaviour>();
		}
	}

	Transform2D* ball = CreateEntity({ 500, 500 }, { 1,1 }, 0);
	BallBehaviour* ballBehaviour = ball->Add<BallBehaviour>();
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

Transform2D* Scene::CreateEntity(sf::Vector2f _position, sf::Vector2f _scale, float _rotation)
{
	Transform2D* transform = new Transform2D();
	transform->Init(_position, _scale, _rotation, m_CurrentID);

	transform->Awake();
	m_ComponentsList.push_back(transform);

	m_CurrentID++;

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
	std::vector<std::pair<Component*, Component*>> newColliders;
	std::vector<Collider*> colliders = this->GetAll<Collider>();
	for (int i = 0; i < colliders.size(); ++i)
	{
		for (int j = i + 1; j < colliders.size(); ++j) 
		{
			if (colliders[i] != colliders[j] && colliders[i]->IsCollide(*colliders[j]))
			{
				std::pair<Collider*, Collider*> c (colliders[i], colliders[j]);

				if (!(std::find(m_lastColliders.begin(), m_lastColliders.end(), c) != m_lastColliders.end()))
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