#pragma once
#include <vector>
#include <cstdint>
#include <iostream>

class Component
{
	uint64_t m_ID;
	std::string m_tag;

public:

	template <typename _type>
	_type* Add(Component* _componant);
	template <typename _type>
	_type* Get();
	template <typename _type>
	_type* GetAll();
	
	virtual void Awake() = 0;
	virtual void Start() = 0;
};

template<typename _type>
_type* Component::Add(Component* _componant)
{
	GameManager.GetInstance().GetCurrentScene().Add(_componant);
}

template<typename _type>
_type* Component::Get()
{
	std::vector<_type*> ComponentList = GameManager.GetInstance().GetCurrentScene().GetAll(); 
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
	std::vector<_type*> ComponentList = GameManager.GetInstance().GetCurrentScene().GetAll(); 
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
