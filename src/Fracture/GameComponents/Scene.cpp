#include "Scene.hpp"
#include "../Components/Behaviour.h"
#include "../Components/Transform2D.h"
#include "../Components/Render.h"

Scene::Scene()
{
}

Transform2D* Scene::CreateEntity(sf::Vector2f _position, float _scale, float _rotation)
{
	Transform2D transform = {_position, _scale, _rotation};
	
	m_ComponentsList.push_back(&transform);

	return &transform;
}

void Scene::Add(Component* _component)
{
	m_ComponentsList.push_back(_component);
}

void Scene::Update()
{
	for (int i = 0; i < m_ComponentsList.size(); i++)
	{
		if (Behaviour* b = dynamic_cast<Behaviour*>(m_ComponentsList[i]))
			b->Update();
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



