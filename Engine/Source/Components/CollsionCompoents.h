#pragma once
#pragma once
#include "../FrameWork/Object.h"

class CollisionComponent : public Object
{
public:
	void Update(float dt);

public:
	class Actor* owner{ nullptr };

	void Initialize() override;

	virtual std::unique_ptr<Object> Clone() {
		return std::make_unique<CollisionComponent>(*this);
	}
	bool CheckCollision(CollisionComponent *collisonWith);

};