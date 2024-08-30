#pragma once
#include <FrameWork/Actor.h>
#include <Components/RenderComponent.h>

class PlayerComponent : public RenderComponent
{
public:
	PlayerComponent() = default;

	static const char* GetTypeName() {
		return "PlayerComponent";
	} virtual void Read(const json_t& value); virtual void Write(json_t& value);
	void Update(float dt);
	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<PlayerComponent>(*this);
	}

	void Initialize();
	void OnColliison(Actor* actor);
	void Read(const json_t json);

	void SetFireModifer(float modifer) {
		m_fireModifer = m_fireModifer * modifer;
	}
	float GetFireModifer() const { return m_fireModifer; }

	void FireBullet();

	Vector2 enemy_position;
	bool m_bullet_special = false;
	bool m_prevBullet_special = true;

private:
	float m_speed = 0;
	float m_fire_timer = 0;
	float m_bullet_shot = 0;

	float m_fireModifer = 1.0f;
	float m_sBulletTimer = 0.0f;

	float m_sheild_number = 1;
};