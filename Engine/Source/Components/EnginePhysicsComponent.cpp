#include "EnginePhysicsComponent.h"
#include "..//Core/Ensert.h"
#include "..//Renderer/Transform.h"
#include "..//FrameWork/Actor.h"

void EnginePhysicsComponent::Initialize()

{

}

void EnginePhysicsComponent::Update(float dt)

{

	//velocity += acceleration * dt;
	owner->transfrom.position += velocity * dt;
	//velocity *= 1.0f / (1.0f + dampling * dt);

	//acceleration = Vector2{ 0, 0 };
}

void EnginePhysicsComponent::ApplyForce(const Vector2& force)

{
	
	//assert(mass != 0);

	// acceleration = F + F + F

	// f = ma

	// a = f / m

	//acceleration += force / mass;

}

void EnginePhysicsComponent::SetPosition(const Vector2& position)

{

	owner->transfrom.position = position;

}

void EnginePhysicsComponent::ApplyTorque(float torque)
{
}

void EnginePhysicsComponent::Read(const json_t& value)

{
	PhysicsComponent::Read(value);
}

void EnginePhysicsComponent::Write(json_t& value)

{

}