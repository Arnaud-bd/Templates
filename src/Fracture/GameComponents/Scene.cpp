#include "Scene.hpp"
#include "../Components/Behaviour.h"
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

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

