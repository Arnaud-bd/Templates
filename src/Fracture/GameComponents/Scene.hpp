#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Components/Component.h"

class Scene : public sf::Drawable
{
	std::vector<Component*> m_Components;

public:
	Scene();

	template <typename _type>
	std::vector<_type*> GetAll();

	uint64_t CreateEntity();
	void Add(Component* _component);
	void Update();
	void Draw();
};

template<typename _type>
inline std::vector<_type*> Scene::GetAll()
{
	std::vector<_type*> vect;
	
	for (int i = 0; i < m_Components.size(); i++)
	{
		_type* me = dynamic_cast<_type*>(m_Components[i]);

		if (me)
			vect.push_back(me);
	}

	return vect;
}
