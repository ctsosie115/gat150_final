#pragma once

#include "..//../Source/Renderer/Transform.h"
#include "..//Renderer/Model.h"
#include <string>
//#include <memory>
#include <vector>
#include "../Components/Component.h"

class Renderer;
class Scene; 

class Actor : public Object
{
public:
	Actor() = default;
	Actor(const Actor& other);
	Actor(const Transform& tranfrom) : transfrom( tranfrom) {}
	/*Actor(const Transform& tranfrom, Model& model) :
		m_transfrom{ tranfrom }
	{}*/
	static const char* GetTypeName() {
		return "Actor";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);

	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<Actor>(*this);
	}

	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);
	virtual void OnColliison(Actor* actor) {};
	
	void Initialize() override;
	void AddComponent(std::unique_ptr<Component> component);

	//comment od delete the getters and setters
	void SetDampling(float damping) { dampling = damping; }
	void SetLifespan(float lifespan) { lifespan = lifespan; }

	const Transform& GetTransform() const { return transfrom; }
	bool IsDestoryed() const { return destoryed; }
	void SetDestroyed(bool isDestroyed) { destoryed = isDestroyed; }

	//float GetRadius() const { return (m_model) ? m_model->GetRadius() * m_transfrom.scale : 0; }
	void SetTag(const std::string& Tag) { tag = Tag; } 

	bool OnCollisionEnter(std::unique_ptr<Actor> *otherActor);
	bool OnCollisionExit(std::unique_ptr<Actor>* otherActor);

	friend class Model;
	friend class Scene;

public:

	bool OnCollisionEnterB = false;
	std::string tag;
	float lifespan = 0;
	bool destoryed = false;
	Transform transfrom{ 0,0 };
	Scene* scene{ nullptr };

	template<typename T>
	T* GetComponent();

	template<typename T>
	std::vector<T*> GetComponents();

protected:
	//Delete velocity and dampling 
	Vector2 velocity{ 0, 0 };
	float dampling{ 0 };

	std::vector<std::unique_ptr<Component>> components;
};

template<typename T> T* GetComponent();
template<typename T> std::vector<T*> GetComponents();
//
template<typename T>
inline T* Actor::GetComponent()
{
	for (auto& component : components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result) return result;
	}

	return nullptr;
}

template<typename T>
inline std::vector<T*> Actor::GetComponents()
{
	std::vector<T*> results;

	for (auto& component : components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result) results.push_back(result);
	}

	return results;
}

template<typename T>
inline T* GetComponent()
{
	return nullptr;
}

template<typename T>
inline std::vector<T*> GetComponents()
{
	return std::vector<T*>();
}
