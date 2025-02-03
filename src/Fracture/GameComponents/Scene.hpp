#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Transform2D;
class Component;

class Scene
{
	std::vector<Component*> m_ComponentsList;

public:
	Scene();

	template <typename _type>
	std::vector<_type*> GetAll();

	Transform2D* CreateEntity(sf::Vector2f _position, float _scale, float _rotation);
	void Add(Component* _component);
	void Update();
	void Drawing(sf::RenderWindow* _render);
};

template<typename _type>
inline std::vector<_type*> Scene::GetAll()
{
	std::vector<_type*> vect;
	
	for (int i = 0; i < m_ComponentsList.size(); i++)
	{
		_type* me = dynamic_cast<_type*>(m_ComponentsList[i]);

		if (me)
			vect.push_back(me);
	}

	return vect;
}
