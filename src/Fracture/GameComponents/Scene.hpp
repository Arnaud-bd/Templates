#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Transform2D;
class Component;

class Scene
{
	std::vector<Component*> m_ComponentsList;
	std::vector<Component*> m_destroyer;

public:
	Scene();
	~Scene();

	template <typename _type>
	std::vector<_type*> GetAll();

	virtual void Init() = 0;
	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);
	void RemoveAllComponent();
	Transform2D* CreateEntity(sf::Vector2f _position, sf::Vector2f _scale, float _rotation);
	void Destroy();
	void Update(float _deltaTime);
	void Physic();
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


