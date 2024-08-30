#pragma once
#include "PhyisicsComponent.h"

class EnginePhysicsComponent : public PhysicsComponent
{
public:
	static const char* GetTypeName() {
		return "EnginePhysicsComponent";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);

		void Initialize() override;
	void Update(float dt) override;

	void ApplyForce(const Vector2& force) override;
	void SetPosition(const Vector2& position) override;
	void SetVelocity(const Vector2& velocity) override { this->velocity = velocity; }

	void ApplyTorque(float torque) override;

	friend class PhysicsComponent;
private:
	Vector2 velocity;
};