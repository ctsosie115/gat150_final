#include "..//../Source/Core/CTime.h"

void Time::Tick()
{
	clock::duration duration = clock::now() - startTime;
	m_time = duration.count() / (float)clock::duration::period::den;

	duration = clock::now() - frameTime;
	m_deltaTime = duration.count() / (float)clock::duration::period::den;

	frameTime = clock::now();
}
