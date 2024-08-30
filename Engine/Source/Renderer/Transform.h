#pragma once

#include "..//../Source/Renderer/Vector2.h"
#include "..//..//Source/Core/Serializable.h"
#include "..//..//Source/Math/MathUTIS.h"

struct Transform : public Serializable
{

	Transform(Vector2 position, float rotation = 0.0f, float scale = 1.0f)
		: position(position), rotation(rotation), scale(scale) {}

	Transform(float x, float y)
		: position(x, y), rotation(0.0f), scale(1.0f) {}

	Vector2 Forward() {return Vector2{ 1,0 }.Rotate(Math::DegtoRad(rotation)); } 

	Vector2 position;
	float rotation = 0;
	float scale= 1;

	void Read(const json_t& value) override;
	void Write(json_t& value) override;
};