#pragma once
//#include "Actor.h"

class Enemy //: public Actor
{
public:
	Enemy() = default;
	/*Enemy(const Transform& transfrom) : Actor{ transfrom } {}
	Enemy(const Transform& transfrom, Model* model) :
		Actor{ transfrom, model }
	{}
	Enemy(float speed, const Transform& transfrom, Model* model) :
		Actor{ transfrom, model },
		m_speed{ speed }
	{}

	void OnColliison(Actor* actor) override;*/

	void Update(float dt);

private:
	float m_speed = 0;
	float m_fire_timer = 0;
};