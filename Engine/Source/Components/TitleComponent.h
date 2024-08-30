#pragma once
#include "Component.h"
#include <vector>

class TitlemapComponent : public Component
{
public:
	TitlemapComponent() = default;

	static const char* GetTypeName() {
		return "TitlemapComponent";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);
	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<TitlemapComponent>(*this);
	}

	// Inherited via Component;
	void Initialize() override;

	void Update(float dt) override;

public:
	int numColumns = 0;
	int numRows = 0;

	Vector2 titleSize{ 0,0 };

	std::vector<std::string> titleNames;
	std::vector<int> titles;

};