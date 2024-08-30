#pragma once
#include "..//Engine.h"
#include "..//FrameWork/Object.h"
#include "..//../Source/Renderer/Particle.h"
#include "..//..//Source/FrameWork/Actor.h"

#include <list>
#include <string>
#include <vector>
//#include <memory>
#include "../Components/CollsionCompoents.h"

class Renderer;

class Engine;

class Scene : public Object
{
public:
	Scene() = default;
	Scene(const Scene& other);
	Scene(Engine* engine) : engine {engine} {}

	static const char* GetTypeName() {
		return "Scene";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);
		virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<Scene>(*this);
	}

	void Update(float dt);

	void Draw(Renderer& renderer);

	void AddActor(std::unique_ptr<Actor> actor, bool initialize);
	void RemoveAll();
	void Collision();
	
	// Inherited via Object
	void Initialize();

	template<typename T> // always in header
	T* GetActor();

	std::vector<Particle> GetParticles() { return particles; }

	int SetScore(int score) const { return score; }
	int GetScore() const { return score; }
	std::string GetStringScore() const { return std::to_string(score); }

	friend Engine;
	friend Renderer;
	
public:
	Engine* engine{ nullptr };
	std::list<std::unique_ptr<Actor>> actors;

protected:
	int score = 0;
	std::vector<Particle> particles;

};

template<typename T> // always in header
T* Scene::GetActor()
{
	static_assert(std::is_base_of_v<Actor, T>, "T must be derived from Actor");
	
	for (auto& actor : actors)
	{
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}
	return nullptr;
}