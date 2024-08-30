
#include "..//../Source/FrameWork/Scene.h"
#include "..//../Source/FrameWork/Actor.h"
#include "..//../Source/Math/Random.h"
#include "..//../Source/Renderer/Vector2.h"
#include "..//Core/Factory.h"
#include "..//..//Source/Core/Ensert.h"
#include "..//Components/TitleComponent.h"
#include <Phyisics/Box2DPhysicsComponent.h>

#include <algorithm>
#include <iostream>
#include <chrono>
#include <map>


Scene::Scene(const Scene& other)
{
	((false) ? (void)0 : CustomAssert("false", "C:\\Users\\ctsosie\\Neumont\\Year 1 Neumont\\Q 3\\Sprint 1\\C++\\C++ Visual Studio\\GAT150 GameEngine\\gat150_cdtsosie\\Engine\\Source\\FrameWork\\Scene.cpp", 19));
}

void Scene::Update(float dt)
{
	//Update
	for (auto& actor : actors)
	{
		actor->Update(dt);
	}

	for (Particle& particle : particles)
	{
		particle.Update(dt);
		if (particle.position.x > 1000) particle.position.x = 0;
		if (particle.position.x < 0) particle.position.x = 1000;

	}

	//destory
	actors.erase(std::remove_if(actors.begin(), actors.end(), [](auto& actor) { return actor->destoryed; }), actors.end());

	// Handle destruction and removal of actors
	auto it = actors.begin();
	while (it != actors.end())
	{
		if ((*it).get()->IsDestoryed())
		{
			it = actors.erase(it);
		}
		else
		{
			++it;
		}
	}

	//collsion
	for (auto& actor1 : actors)
	{
		for (auto& actor2 : actors)
		{
			//Checks if actors are desstoryed
			if (actor1 == actor2 || (actor1->IsDestoryed()) || (actor2->IsDestoryed())) continue;

			//Checks if the actors are near each other
			Vector2 direction = actor1->GetTransform().position - actor2->GetTransform().position;
			float distance = direction.Length();

			// Assuming GetRadius() is defined elsewhere
				//float radius = actor1->GetRadius() + actor2->GetRadius();

				//if (distance <= radius)
				// { code;}

			//Where the collison happens 
			actor1->OnColliison(actor2.get());
			actor2->OnColliison(actor1.get());

		}
	}

}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : actors)
	{
		actor->Draw(renderer);
	}
	for (Particle& particleses : particles)
	{
		renderer.SetColor(particleses.red, particleses.green, particleses.blue, particleses.alpha);
		particleses.Draw(renderer);
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor, bool initialize)
{
	// Check if the actor is valid before proceeding
	if (!actor) {
		std::cerr << "Error: Attempting to add a null actor to the scene!" << std::endl;
		return;
	}

	actor->scene = this;

	if (initialize) {
		actor->Initialize();  // Make sure the actor is initialized if necessary
	}

	// Move the actor into the vector and invalidate the passed unique_ptr
	actors.push_back(std::move(actor));
}

void Scene::RemoveAll()
{
	actors.clear();
}

void Scene::Initialize()
{
	Factory::Instance().Register<Scene>("Scene");
	Factory::Instance().Register<Actor>("Actor");
	Factory::Instance().Register<TextureComponent>("TextureComponent");
	Factory::Instance().Register<Box2DPhysicsComponent>("Box2DPhysicsComponent");
	Factory::Instance().Register<TitlemapComponent>("TitlemapComponent");
	Factory::Instance().Register<AudioComponent>("AudioComponent");

}

void Scene::Collision()
{
	for (auto& actor1 : actors)
	{
		CollisionComponent* collision1 = actor1->GetComponent<CollisionComponent>();
		if (!collision1) continue;

		for (auto& actor2 : actors)
		{
			// don't check with self
			if (actor1 == actor2) continue;

			CollisionComponent* collision2 = actor2->GetComponent<CollisionComponent>();
			if (!collision2) continue;

			if (collision1->CheckCollision(collision2))
			{
				//if (actor1->OnCollisionEnterB) actor1->OnCollisionEnter(actor2);
				//if (actor2->OnCollisionEnterB) actor2->OnCollisionEnter(actor1);
			}
		}
	}
}

void Scene::Read(const json_t& value)
{
	if (HAS_DATA(value, actors) && GET_DATA(value, actors).IsArray())
	{
		for (auto& actorValue : GET_DATA(value, actors).GetArray()) {
			//Adding Actors to the scence
			auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
			actor->Read(actorValue);

			bool prototype = false;
			Json::Read(actorValue, "prototype", prototype);

			if (prototype)
			{
			  std::string name = actor->GetTypeName();
			  Factory::Instance().RegisterPrototype<Actor>(name, std::move(actor));
			}
			else
			{
				AddActor(std::move(actor), true);
				
			}
		}
	}
}

void Scene::Write(json_t& value)
{
	//
}
