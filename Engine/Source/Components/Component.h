#pragma once
#include "../FrameWork/Object.h"

class Component : public Object
{
public:
	virtual void Update(float dt) = 0;

public:
	class Actor* owner{ nullptr };

	void Initialize() = 0;


	// Inherited via Object
	std::unique_ptr<Object> Clone() override;

	// Inherited via Serializable
	void Read(const json_t& value) override;

	void Write(json_t& value) override;
};