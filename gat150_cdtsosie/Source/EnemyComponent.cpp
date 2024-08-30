//#include "Enemy.h"
//#include "Player.h"
//#include "Scene.h"
//#include "Random.h"
//
//void Enemy::Update(float dt)
//{
//	Player* player = m_scene->GetActor<Player>();
//	if (player)
//	{
//		Vector2 direction = player->GetTransform().position - m_transfrom.position;
//		m_velocity += direction.Normalized() * m_speed * dt;
//		m_transfrom.rotation = direction.Angle();
//	}
//	Actor::Update(dt);
//}
//
//void Enemy::OnColliison(Actor* actor)
//{
//	if (actor->GetTag() == "Player" || actor->GetTag() == "Bullet" || actor->GetTag() == "Sheild")
//	{
//		m_destoryed = true;
//	}
//	for (int i = 0; i < 100, i++;) {
//		Particle::Data data
//		{
//
//		m_transfrom.position,
//		Vector2{1,0}.Rotate(randomF(Math::TwoPi)) * 50,
//		randomF(0.5f, 0.2f),
//		255, 255, 255, 255
//		};
//	}
//
//}