#pragma once
#include "Component.h"

class RenderComponent : public Component
{
public:
	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<RenderComponent>(*this);
	}

	virtual void Draw(class Renderer& renderer) {};

	// Inherited via Component
	void Initialize() override;
	void Update(float dt) override;

	// Inherited via Component
	void Read(const json_t& value);
	void Write(json_t& value);
};