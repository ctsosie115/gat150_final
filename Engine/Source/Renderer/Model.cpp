#include "..//../Source/Renderer/Model.h"

void Model::Draw(Renderer& render, const Vector2& position, float angle, float scale)
{
	if (points.empty()) return;

	render.SetColor(Color::Toint(color.r), Color::Toint(color.g), Color::Toint(color.b), Color::Toint(color.a));
	for (int i = 0; i < points.size() - 1; i++)
	{
		Vector2 p1 = points[i].Rotate(angle) * scale + position;
		Vector2 p2 = points[static_cast<std::vector<Vector2, std::allocator<Vector2>>::size_type>(i) + 1].Rotate(angle) * scale + position;

		render.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

void Model::Draw(Renderer& render, const Transform& transform)
{
	if (points.empty()) return;

	render.SetColor(Color::Toint(color.r), Color::Toint(color.g), Color::Toint(color.b), Color::Toint(color.a));
	for (int i = 0; i < points.size() - 1; i++)
	{
		Vector2 p1 = points[i].Rotate(transform.rotation) * transform.scale + transform.position;
		Vector2 p2 = points[static_cast<std::vector<Vector2, std::allocator<Vector2>>::size_type>(i) + 1].Rotate(transform.rotation) * transform.scale + transform.position;

		render.DrawLine(p1.x, p1.y, p2.x, p2.y);
	}
}

float Model::GetRadius()
{
	float radius = 0;
	for (const Vector2& point : points)
	{
		float r = point.Length();
		if (r > radius)
		{
			radius = r;
		}
	}

	return radius;
}
