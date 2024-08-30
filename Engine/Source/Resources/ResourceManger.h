#pragma once

#include "Resources.h"
#include "..//Core/Singleton.h"
#include "..//Core/EString.h"
#include "..//Renderer/Texture.h"
#include <iostream>
#include <map>

class ResourceManger : public Singleton<ResourceManger>
{
public:
	template<typename T, typename ... TArgs>
	res_t<T> Get(const std::string& name, TArgs ... args);
	
	void Clear() { m_resource.clear(); }
	friend class Singleton;
protected:
	ResourceManger() = default;
	
private:
	std::map<std::string, res_t<Resource>> m_resource;
};

template<typename T, typename ... TArgs>
inline res_t<T> ResourceManger::Get(const std::string& name, TArgs ... args)
{

	std::string lowerName = ToLower(name);

	if (m_resource.find(lowerName) != m_resource.end())
	{
		return std::dynamic_pointer_cast<T>(m_resource[lowerName]);
		//return std::dynamic_pointer_cast<T>(m_resourceFind->second);
	}

	////find resource in resource manager
	if (m_resource.find(name) != m_resource.end())
	{
		return std::dynamic_pointer_cast<T>(m_resource[name]);
	}

	//Resource not fount, create resource
	res_t<T> resource = std::make_shared<T>();

	
	//Resource not found, create resource
	if (!resource->Create(name, args ...)) {
		std::cerr << "Can't not create resource: " << name << std::endl;
		return nullptr;
	}

	//Add resource to resource manager
	//m_resource[name] = resource;
	m_resource[lowerName] = resource;

	return resource;
}