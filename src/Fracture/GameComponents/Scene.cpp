#include "Scene.hpp"
#include "../Components/Behaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Render.h"

Scene::Scene()
{
}

Transform2D* Scene::CreateEntity(sf::Vector2f _position, float _scale, float _rotation)
{
	Transform2D transform;
	transform.Init(_position, _scale, _rotation);

	m_ComponentsList.push_back(&transform);

	return &transform;
}

void Scene::Update(float _deltaTime)
{
	for (int i = 0; i < m_ComponentsList.size(); i++)
	{
		if (Behaviour* b = dynamic_cast<Behaviour*>(m_ComponentsList[i]))
			b->Update(_deltaTime);
	}
}

void Scene::Drawing(sf::RenderWindow* _render)
{
    _render->clear(sf::Color::Black);

    std::vector<Render*> renders = GetAll<Render>();

    for (size_t i = 0; i < renders.size(); ++i) 
	{
        _render->draw(*renders[i]);
    }

    _render->display();
}



