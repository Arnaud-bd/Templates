#pragma once
#include <vector>
#include <cstdint>
#include <iostream>
#include "../Managers/GameManager.h"

class Component
{
	uint64_t m_ID;
	std::string m_tag;

public:
	Component();

	template <typename _type>
	_type* Add();
	template <typename _type>
	_type* Get();
	template <typename _type>
	_type* GetAll();
	
	uint64_t GetID();
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
_type* Component::Get()
{
	std::vector<_type*> ComponentList = GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->GetAll<_type>();
	for (int i = 0; i < ComponentList.size(); ++i)
	{
		if (_type* result = dynamic_cast<_type*>(ComponentList[i]))
		{
			return result;
		}
	}
	return nullptr;
}

template<typename _type>
inline _type* Component::GetAll()
{
	std::vector<_type*> ComponentList = GameManager::GetInstance().GetCurrentScene().GetAll(); 
	std::vector<_type*> resultList; 
	for (int i = 0; i < ComponentList.size(); ++i)
	{
		if (_type* result = dynamic_cast<_type*>(ComponentList[i])) 
		{
			resultList.push_back(result); 
		}
	}
	return resultList;
}
