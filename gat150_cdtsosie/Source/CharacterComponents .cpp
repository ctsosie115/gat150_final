#include "PlayerComponents.h"
#include "../Source/Components/PhyisicsComponent.h"
#include "./FrameWork/Scene.h"
#include "./FrameWork/Actor.h"
#include "CharacterComponents.h"

void ChracaterComponent::Read(const json_t& value)
{
}

void ChracaterComponent::Write(json_t& value)
{
	//owner->OnCollisionEnter = std::bind(&ChracaterComponent::OnCollisionEnter, this, std::placeholders::_1);
	//owner->OnCollisionExit = std::bind(&ChracaterComponent::OnCollisionExit, this, std::placeholders::_1);

	m_phyisics = owner->GetComponent<PhysicsComponent>();
	m_animation = owner->GetComponent<TextureAnimationComponent>();
 }

void ChracaterComponent::Update(float dt)
{
	bool OnGround = (groundcount > 0);
 
	////Movemnet 
	Vector2 direction{ 0,1 };
	float thrust = 0;

 float  modifer = (OnGround) ? 1 : 0.2f;
	m_phyisics->ApplyForce(direction * m_speed * 5 * modifer);
 
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = direction.x - 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x = direction.x + 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.y = direction.y + 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.y = direction.y - 1;

	//owner->GetComponent<PhysicsComponent>()->ApplyForce(Vector2{0, -50});

	if(OnGround && owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) {
		m_phyisics->SetVelocity(Vector2{ 0, -500 });
	}
	if(m_phyisics->GetVelocity().x < -0.1f) m_animation->hflip = true;
	else if (m_phyisics->GetVelocity().y > 0.1f) m_animation->hflip = false;
 
 if(Math::Absolute(m_phyisics->GetVelocity().x) > 0.1f) m_animation->SetAnimation("run", true);
 
	////Speed
	Vector2 acceleration = Vector2{ thrust, 0.0f }.Rotate(owner->GetTransform().rotation) * thrust;
	m_phyisics->GetVelocity() += acceleration * dt;

	////Wrap
	owner->transfrom.position.x = Math::Wrap(owner->transfrom.position.x, (float)owner->scene->engine->GetRenderer().GetWidth());
	owner->transfrom.position.y = Math::Wrap(owner->transfrom.position.y, (float)owner->scene->engine->GetRenderer().GetHeight());

	////Follows the mouse
	//m_transfrom.rotation = (g_engine.GetInput().GetMousePosition() - m_transfrom.position).Angle();

	////fire intervals
	m_fire_timer -= dt;

	////Fire Bullets
	FireBullet();
}

void ChracaterComponent::OnColliison(Actor* actor)
{
	if (actor->tag == "Enemy")
{
		owner->destoryed = true;
	}
}

void ChracaterComponent::Read(const json_t json)
{
}

void ChracaterComponent::FireBullet()
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

void ChracaterComponent::OnCollisionEnter(Actor* actor)
{
	if (actor->tag == "Ground")groundcount++;
}

void ChracaterComponent::OnCollisionExit(Actor* actor)
{
	if (actor->tag == "Ground")groundcount--;
}
