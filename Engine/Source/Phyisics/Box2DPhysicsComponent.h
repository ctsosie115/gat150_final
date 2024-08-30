#pragma once
#include "..//Phyisics/Box2DPhysicsComponent.h"
#include "..//Phyisics/RigidBody.h"
#include "..//Components/PhyisicsComponent.h"

#include <memory>

class Box2DPhysicsComponent : public PhysicsComponent
{
public:
	Box2DPhysicsComponent() = default;
	Box2DPhysicsComponent(const Box2DPhysicsComponent& other);

	static const char* GetTypeName() {
		return "Box2DPhysicsComponent";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);
	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<Box2DPhysicsComponent>(*this);
	}

	void Initialize() override;
	void Update(float dt) override;

	void ApplyForce(const Vector2& force) override;
	void ApplyTorque(float torque) override;

	void SetPosition(const Vector2& position) override;
	void SetVelocity(const Vector2& velocity) override;

public:
	RigidBody::def_t rigidBodyDef;
	Vector2 size{ 0, 0 };
	Vector2 scale{ 1,1 };

private:
	std::unique_ptr<RigidBody> rigidBody;

	// Inherited via PhysicsComponent
	Vector2 GetVelocity() override;
};