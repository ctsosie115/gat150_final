#pragma once

#include "..//../Source/Renderer/Vector2.h"
#include "..//../Source/Renderer/Render.h"

struct Particle
{
	struct Data {
		Vector2 position{ 0, 0 };
		Vector2 velocity{ 0,0 };
		float m_lifespan{ 0.0f };
		int red;
		int green;
		int blue;
		int alpha;
	};

	Vector2 position{ 0, 0 };
	Vector2 velocity{ 0,0 };
	float lifespan = 0.0f;
	int red = 0;
	int green = 0;
	int blue = 0;
	int alpha = 0;
	//uint8_t r{}, g{}, b{}, a{}
	bool isActive{ false };

	Particle() = default;

	/*Particle(Vector2 position, Vector2 velocity) :
		position{ position },
		velocity{ velocity },
		m_lifespan{ 0 }
	{}

	Particle(Vector2 position, Vector2 velocity, float lifespan) :
		position{ position },
		velocity{ velocity },
		m_lifespan{ lifespan }
	{}*/
	Particle(Vector2 position, Vector2 velocity, float lifespan, int red, int green, int blue, int alpha) :
		position{ position },
		velocity{ velocity },
		lifespan{ lifespan },
		red{ red },
		green{ green },
		blue{ blue },
		alpha{ alpha }
	{}

	void Update(float dt);

	void Draw(Renderer& renderer) const;

	void Initialize(const Data& data);

};