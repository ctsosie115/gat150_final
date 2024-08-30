//#pragma once
//#include "Actor.h"
//
//class Pickup : public Actor
//{
//public:
//	Pickup() = default;
//	Pickup(const Transform& transfrom) : Actor{ transfrom } {}
//	Pickup(const Transform& transfrom, Model* model) :
//		Actor{ transfrom, model }
//	{}
//	void OnColliison(Actor* actor) override;
//
//private:
//	bool m_destroyed = false;
//};


//#include "Pickup.h"
//#include "Player.h"
//#include <iostream>
//
//void Pickup::OnColliison(Actor* actor)
//{
//	if (actor->GetTag() == "Bullet")
//	{
//		Player* player2 = dynamic_cast<Player*>(actor);
//		//player2->SetFireModifer(player2->GetFireModifer() * 0.5f);
//		m_destoryed = true;
//
//		std::cout << "Pickup" << std::endl;
//	}
//}
