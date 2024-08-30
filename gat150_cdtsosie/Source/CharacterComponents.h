#pragma once
#include <FrameWork/Actor.h>
#include <Components/TextureAnimationComponent.h>
#include <Components/RenderComponent.h>

class ChracaterComponent : public RenderComponent
{
public:
	ChracaterComponent() = default;

	static const char* GetTypeName() {
		return "ChracaterComponent";
	}
	virtual void Read(const json_t& value);
	virtual void Write(json_t& value);
	void Update(float dt);
	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<ChracaterComponent>(*this);
	}
	void OnColliison(Actor* actor);
	void Read(const json_t json);

	void SetFireModifer(float modifer) {
		m_fireModifer = m_fireModifer * modifer;
	}
	float GetFireModifer() const { return m_fireModifer; }
	void FireBullet();

	void OnCollisionEnter(Actor* actor);
	void OnCollisionExit(Actor* actor);

	Vector2 enemy_position;
	bool m_bullet_special = false;
	bool m_prevBullet_special = true;

public:
	float m_speed = 0;
	float m_fire_timer = 0;
	float m_bullet_shot = 0;
	int groundcount{0};
 
	float m_fireModifer = 1.0f;
	float m_sBulletTimer = 0.0f;

	float m_sheild_number = 1;
 
	PhysicsComponent* m_phyisics{ nullptr };
	TextureAnimationComponent* m_animation{ nullptr };

};