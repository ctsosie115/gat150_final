#include "PlayerComponents.h"
#include "../Source/Components/PhyisicsComponent.h"
#include "./FrameWork/Scene.h"
#include "./FrameWork/Actor.h"

void PlayerComponent::Read(const json_t& value)
{
}

void PlayerComponent::Write(json_t& value)
{
}

void PlayerComponent::Update(float dt)
{
	////Movemnet 
	Vector2 direction{ 0,1 };
	float thrust = 0;

	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = direction.x - 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x = direction.x + 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.y = direction.y + 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.y = direction.y - 1;


	//owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * m_speed * thrust);

	////Speed
	Vector2 acceleration = Vector2{ thrust, 0.0f }.Rotate(owner->GetTransform().rotation);
	//m_velocity += acceleration * dt;

	////Wrap
	owner->transfrom.position.x = Math::Wrap(owner->transfrom.position.x, (float)owner->scene->engine->GetRenderer().GetWidth());
	owner->transfrom.position.y = Math::Wrap(owner->transfrom.position.y, (float)owner->scene->engine->GetRenderer().GetHeight());

	////Follows the mouse
	//m_transfrom.rotation = (g_engine.GetInput().GetMousePosition() - m_transfrom.position).Angle();

	////fire intervals
	m_fire_timer -= dt;

	////Fire Bullets
	FireBullet();

	////Update Actor
	//owner->Update(dt);
}

void PlayerComponent::Initialize()
{

}

void PlayerComponent::OnColliison(Actor* actor)
{
	if (actor->tag == "Enemy")
	{
		owner->destoryed = true;
	}
	if (actor->tag == "Ground")
	{
		//onGround = true;
	}
}

void PlayerComponent::Read(const json_t json)
{
}


void PlayerComponent::FireBullet()
{
	////Checks if left click, and the fire interval
	
	if (owner->scene->engine->GetInput().GetPreviousMouseButtonDown(0) && m_fire_timer <= 0) {
		//create rockectComponent
		//Make it go
			//direction
			//SetTag
			//Sound with Fired
			//Add the rockectComponenet to Actor : Make Sure Scence Can See it
			//Create a texture for the rocket
	}
}
