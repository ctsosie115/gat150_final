#pragma once
#include "PlayerComponents.h"
#include <FrameWork/Actor.h>

class RocketComponent : public PlayerComponent
{
	virtual void Update(float dt);
	virtual void OnColliison(Actor* actor);
	void Initialize();

private:
	float m_speed = 0;
};