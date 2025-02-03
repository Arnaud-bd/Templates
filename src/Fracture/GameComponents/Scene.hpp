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
	~Scene();

	template <typename _type>
	std::vector<_type*> GetAll();

	void Init();
	void AddComponent(Component* _component);
	Transform2D* CreateEntity(sf::Vector2f _position, float _scale, float _rotation);
	void Update(float _deltaTime);
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


