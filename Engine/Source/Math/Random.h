#pragma once

#include "..//../Source/Renderer/Vector2.h"
#include "..//../Source/Math/MathUTIS.h"

#include <random>


inline int random() { return rand(); }
inline int random(unsigned int max) { return rand() % max; }
inline int random(int min, int max) { return min + random(max - min); }

inline float randomF() { return rand() / (float)RAND_MAX; } //0 -1
inline float randomF(float max) { return max * randomF(); }
inline float randomF(float min, float max) { return min + random(max - min); }

inline Vector2 randomOnUnitCircle()
{
	float angle = randomF(0, 360);
	return Vector2{ Math::Cos(Math::DegtoRad(angle)), Math::Sin(Math::DegtoRad(angle)) };
}

