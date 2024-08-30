#include "..//../Source/FrameWork/Actor.h"
#include "../Components/RenderComponent.h"
#include "..//Core/Json.h"
//#include <Instance.h>
#include <Components/CollsionCompoents.h>
#include <Core/Factory.h>


void Actor::Update(float dt)
{
	//check for lifespan
	if (lifespan != 0)
	{
		lifespan -= dt;
		if (lifespan <= 0) {
			destoryed = true;
		}
	}

	for (auto& component : components) {
		component->Update(dt);
	}

	transfrom.position += (velocity * dt);
	velocity *= 1.0f / (1.0f + dampling * dt);
}
void Actor::Initialize()
{
	for (auto& component : components) {
		component->Initialize();
	}
}

void Actor::Draw(Renderer& renderer)
{
	if (destoryed) return;

	for (auto& component : components) {
		std::cout << component->name << std::endl;
		RenderComponent* renderComponent = dynamic_cast<RenderComponent*>(component.get());
		if (renderComponent) {
			renderComponent->Draw(renderer);
		}
	}
}


void Actor::AddComponent(std::unique_ptr<Component> component)
{
	component->owner = this;

	components.push_back(std::move(component));
}

bool Actor::OnCollisionEnter(std::unique_ptr<Actor>* otherActor)
{

	return false;
}

bool Actor::OnCollisionExit(std::unique_ptr<Actor>* otherActor)
{
	return false;
}


Actor::Actor(const Actor& other)
{
	this->tag = other.tag;
	this->lifespan = other.lifespan;
	this->destoryed = other.destoryed;

	this->transfrom = other.transfrom;
	this->scene = other.scene;

	for (const auto& component : other.components) {
		std::unique_ptr<Component> clone = std::unique_ptr<Component>(dynamic_cast<Component*>(component->Clone().release()));
		AddComponent(std::move(clone));
	}
}

void Actor::Read(const json_t& value)
{
	// Read actor-specific data
	if (value.HasMember("name")) name = value["name"].GetString();
	if (value.HasMember("tag")) tag = value["tag"].GetString();

	Object::Read(value);
	
	if (HAS_DATA(value, transfrom)) transfrom.Read(GET_DATA(value, transfrom));

	//Read Componenets
	if (HAS_DATA(value, components) && GET_DATA(value, components).IsArray())
	{
		for (auto& componentValue : GET_DATA(value, components).GetArray()) {
			//Adding Actors to the scence
			
			std::string type;
			READ_DATA(componentValue, type);
			
			//
			auto componenet = Factory::Instance().Create<Component>(type);
			componenet->Read(componentValue);
			AddComponent(std::move(componenet));
		}
	}
}

void Actor::Write(json_t& value)
{
	//
}
