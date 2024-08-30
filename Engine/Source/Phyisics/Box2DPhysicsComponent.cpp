#include "Box2DPhysicsComponent.h"
#include "Engine.h"

class RegisterBox2DPhysicsComponent {
public: RegisterBox2DPhysicsComponent() {
	Factory::Instance().Register<Box2DPhysicsComponent>("Box2DPhysicsComponent");
}
}; static RegisterBox2DPhysicsComponent register_instance;

Box2DPhysicsComponent::Box2DPhysicsComponent(const Box2DPhysicsComponent& other)
{
	rigidBodyDef = other.rigidBodyDef;
	if (other.rigidBody)
	{
		rigidBody = std::make_unique<RigidBody>(*other.rigidBody.get());
	}
}

void Box2DPhysicsComponent::Initialize()
{
	rigidBodyDef.actor = owner;
	rigidBody = std::make_unique<RigidBody>(owner->transfrom, size * scale, rigidBodyDef, owner->scene->engine->GetPhysics()); 

	/*if (size.x == 0 && size.y == 0) {
		m_rigidBody = std::make_unique<RigidBody>(owner->GetComponent<TextureComponent>());
		size = Vector2{ textureComponent->Source.w, textureComponent->Source.h };
		m_rigidBody = std::make_unique<RigidBody>(owner->m_transfrom, size, rigidBodyDef, owner->m_scene->engine->GetPhysics());
	}*/
}

void Box2DPhysicsComponent::Update(float dt)
{
	owner->transfrom.position = rigidBody->GetPosition();
	owner->transfrom.rotation = rigidBody->GetAngle();
	//velocity = m_rigidBody->GetVelocity();
}


void Box2DPhysicsComponent::ApplyForce(const Vector2& force)
{
	rigidBody->ApplyForce(force);
}

void Box2DPhysicsComponent::ApplyTorque(float torque)
{
	rigidBody->ApplyTorque(torque);
}

void Box2DPhysicsComponent::SetPosition(const Vector2& position)
{
	rigidBody->SetTransform(position, rigidBody->GetAngle());
}

void Box2DPhysicsComponent::SetVelocity(const Vector2& velocity)
{
	rigidBody->SetVelocity(velocity);
}

Vector2 Box2DPhysicsComponent::GetVelocity()
{
	return rigidBody->GetVelocity();
}

void Box2DPhysicsComponent::Read(const json_t& value)
{
	Json::Read(value, "gravityScale", rigidBodyDef.gravityScale, false);
	Json::Read(value, "damping", rigidBodyDef.damping, false);
	Json::Read(value, "angularDamping", rigidBodyDef.angularDamping, false);
	Json::Read(value, "constrainAngle", rigidBodyDef.constrainAngle, false);
	Json::Read(value, "isDynamic", rigidBodyDef.isDynamic, false);
	Json::Read(value, "friction", rigidBodyDef.friction, false);
	Json::Read(value, "restitution", rigidBodyDef.restitution, false);
	Json::Read(value, "density", rigidBodyDef.density, false);
	Json::Read(value, "isSensor", rigidBodyDef.isSensor, false);

	//Asks about it later after class
	//READ_DATA_STRUCT(value, gravityScale, rigidBodyDef);

	//std::string shape;
	//Json::Read(value, "shape", shape);

	//if (shape == "capsule")
	//{
	//	rigidBodyDef.shape = RigidBody::Shape::CAPSULE; 
	//}
	////if  (shape == "capsule") rigidBodyDef.shape = RigidBody::Shape::CAPSULE;

	//if (shape == "circle")
	//{
	//	rigidBodyDef.shape = RigidBody::Shape::CIRCLE;
	//}
	////if  (shape == "circle") rigidBodyDef.shape = RigidBody::Shape::CIRCLE;

	Json::Read(value, "size", size);
	Json::Read(value, "scale", scale);
}

void Box2DPhysicsComponent::Write(json_t& value)
{
	//
}
