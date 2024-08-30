#pragma once

#include "..//../Source/Renderer/Vector2.h"
#include "..//../Source/Renderer/Color.h"
#include "..//../Source/Renderer/Render.h"
#include "..//../Source/Renderer/Transform.h"
#include <vector>
#include <random>

class Model
{
public:
	Model() = default;
	Model(std::vector<Vector2>& points, Color& color, Transform& transform, Model& model) :
		points{ points },
		color{ color },
		transform{ transform },
		model{ model }
	{}

	void Draw(Renderer& render, const Vector2& position, float angle, float scale);
	void Draw(Renderer& render, const Transform& transform);
	void Draw(Renderer& render, Vector2& position, float angle, float size);
	void Draw(Renderer& render, Transform& transform);

	float GetRadius();
	//float GetRadius() { return (m_model) ? m_model->GetRadius() * m_transform.scale : 0; }

private:
	std::vector<Vector2> points;
	Color color;
	Transform& transform;
	Model& model;
};