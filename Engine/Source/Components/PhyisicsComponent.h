#pragma once
#include "RenderComponent.h"

class PhysicsComponent : public RenderComponent 
{
public:
	virtual void ApplyForce(const Vector2& force) = 0;
	virtual void SetPosition(const Vector2& position) = 0;
	virtual void SetVelocity(const Vector2& velocity) = 0;
	virtual Vector2 GetVelocity() = 0;
	virtual void ApplyTorque(float torque) = 0;

	// Inherited via RenderComponent
	void Draw(Renderer& renderer) override;

	// Inherited via Serializable
	void Read(const json_t& value) override;

	void Write(json_t& value) override;
protected:

private:
};