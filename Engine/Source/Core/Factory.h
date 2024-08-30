#pragma once
#include "../Core/Singleton.h"
#include <ostream>
#include <iostream>
#include <string>
#include <map>
#include <functional>

class CreateBase
{
public:
	virtual ~CreateBase() = default;
	virtual std::unique_ptr<class Object> Create() = 0;
};

template<typename T>
class Creator : public CreateBase
{
public:
	std::unique_ptr<class Object> Create() override
	{
		return std::make_unique<T>();
	}
};

template <typename T>
class PrototypeCreator : public CreateBase
{
public:
	PrototypeCreator(std::unique_ptr<T> prototype) : m_prototype{ std::move(prototype) } {}
	std::unique_ptr<class Object> Create() override
	{
		return m_prototype->Clone();
	}

private:
	std::unique_ptr<T> m_prototype;
};

class Factory : public Singleton<Factory>
{
public:
	template<typename T> void Register(const std::string& name);
	template<typename T> void RegisterPrototype(const std::string& name, std::unique_ptr<T> prototype);
	template<typename T = class Object> std::unique_ptr<T> Create(const std::string& name);

private:
	std::map<const std::string, std::unique_ptr<CreateBase>> m_registry;
};

template<typename T>
inline void Factory::Register(const std::string& name)
{
	m_registry[name] = std::make_unique<Creator<T>>();
}

template<typename T>
inline void Factory::RegisterPrototype(const std::string& name, std::unique_ptr<T> prototype)
{
	// Store the prototype in the registry
	m_registry[name] = std::make_unique<PrototypeCreator<T>>(std::move(prototype));
}

template<typename T>
inline std::unique_ptr<T> Factory::Create(const std::string& name)
{
	// check if name is in registry
	if (m_registry.find(name) != m_registry.end())
	{
		// if in registry, create object of type T
		return std::unique_ptr<T>(dynamic_cast<T*>(m_registry[name]->Create().release()));
	}

	std::cerr << "Could not create factory object: " << name << std::endl;

	// name is not in registry, return empty unique_ptr
	return std::unique_ptr<T>();
}

