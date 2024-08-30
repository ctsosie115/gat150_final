#include "RocketComponent.h"

void RocketComponent::Update(float dt)
{
	//Particle::Data data
	//{
	//	m_transfrom.position,
	//	Vector2{1,0}.Rotate(randomF(0.1f, Math::TwoPi)) * 50.0f,
	//	randomF(1.5f),
	//	255, 255, 255, 255
	//};

	////g_engine.GetPS().AddParticle(data);

	//m_velocity = Vector2{ 1,0 }.Rotate(m_transfrom.rotation) * m_speed;
}

void RocketComponent::OnColliison(Actor* actor)
{
	if (owner->tag == "Enemy")
	{
		//when the rocket this other actor
	}
}

void RocketComponent::Initialize()
{
	//create rockectComponent
		//Make it go
			//direction
			//SetTag
			//Sound with Fired
			//Add the rockectComponenet to Actor : Make Sure Scence Can See it
			//Create a texture for the rocket
}
