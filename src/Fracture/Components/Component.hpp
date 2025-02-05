#pragma once
#include <vector>
#include <cstdint>
#include <iostream>
#include "../Managers/GameManager.h"

class Component
{
	uint64_t m_ID;
	std::string m_tag;
	bool m_toDestroy = false;

public:
	Component();

	template <typename _type>
	_type* Add();
	template <typename _type>
	_type* Get() const;
	template <typename _type>
	std::vector<_type*> GetAll();
	
	uint64_t GetID() const;
	void ToDestroy();
	bool IsDestroy();
	void SetID(uint64_t _ID);
	virtual void Awake() = 0;
	virtual void Start() = 0;
};

template<typename _type>
inline _type* Component::Add()
{
	_type* component = new _type();
	component->m_ID = m_ID;
	GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->AddComponent(component);
	component->Awake();
	return component;
}

template<typename _type>
_type* Component::Get() const
{
	std::vector<_type*> ComponentList = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->GetAll<_type>();
	for (int i = 0; i < ComponentList.size(); ++i)
	{
		if (ComponentList[i]->m_ID == m_ID)
		{
			return ComponentList[i];
		}
	}
	return nullptr;
}

template<typename _type>
inline std::vector<_type*> Component::GetAll()
{
	std::vector<_type*> ComponentList = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->GetAll<_type>();
	std::vector<_type*> resultList; 
	for (int i = 0; i < ComponentList.size(); ++i)
	{
		if (ComponentList[i]->m_ID == m_ID)
		{
			resultList.push_back(ComponentList[i]);
		}
	}
	return resultList;
}
