#pragma once
#include <chrono>

class Time
{
private:
	using clock = std::chrono::high_resolution_clock;

public:
	Time() : startTime{ clock::now() },
		frameTime{ clock::now() }
	{}

	void Tick();
	void Reset() const { startTime - clock::now(); }

	float GetTime() const { return m_time; }
	float GetDeltaTime() const { return m_deltaTime; }


private:
	float m_time{ 0 };
	float m_deltaTime{ 0 };

	clock::time_point startTime;
	clock::time_point frameTime;

};

