#include "Scene.hpp"
#include "../Components/Behaviour.h"
#include "../Components/Render.h"

Scene::Scene()
{
}

uint64_t Scene::CreateEntity()
{
	return 0;
}

void Scene::Add(Component* _component)
{
	m_Components.push_back(_component);
}

void Scene::Update()
{
	for (int i = 0; i < m_Components.size(); i++)
	{
		if (Behaviour* b = dynamic_cast<Behaviour*>(m_Components[i]))
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



