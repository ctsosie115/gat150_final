#include "RigidBody.h"
#include "Physics.h"

RigidBody::RigidBody(const Transform& transform, const Vector2& size, const def_t& def, const Physics& physics)
{
	b2BodyDef bodyDef = b2DefaultBodyDef();

	// set body definition
	bodyDef.type = (def.isDynamic) ? b2_dynamicBody : b2_staticBody;
	bodyDef.position = ConvertVec2(Physics::ScreenToWorld(transform.position));
	bodyDef.rotation = b2MakeRot(transform.rotation);
	bodyDef.fixedRotation = def.constrainAngle;
	bodyDef.gravityScale = def.gravityScale;
	bodyDef.linearDamping = def.damping;
	bodyDef.angularDamping = def.angularDamping;
	bodyDef.userData = def.actor;

	// create body
	bodyId = b2CreateBody(physics.worldId, &bodyDef);

	b2ShapeDef shapeDef = b2DefaultShapeDef();

	shapeDef.friction = def.friction;
	shapeDef.restitution = def.restitution;
	shapeDef.density = def.density;
	shapeDef.isSensor = def.isSensor;

	// set shape
	b2Vec2 hsize = ConvertVec2(Physics::ScreenToWorld(size * transform.scale * 0.5f));
	
	switch (def.shape)
	{
	case Shape::BOX:
	{
		//b2Polygon box = b2MakeBox(hsize.x, hsize.y); 
		//b2CreatePolygonShape(bodyId, &shapeDef, &box); 

		b2Vec2 vs[4] =
		{
			{ -hsize.x, -hsize.y },
			{  hsize.x, -hsize.y },
			{  hsize.x,  hsize.y },
			{ -hsize.x,  hsize.y },
		};

		b2ChainDef chainDef = b2DefaultChainDef();
		chainDef.points = vs;
		chainDef.count = 4;
		chainDef.isLoop = true;
		b2CreateChain(bodyId, &chainDef);
	}
		break;
	case Shape::CAPSULE:
	{
		b2Capsule capsule{ b2Vec2{0, hsize.y - hsize.x}, b2Vec2{0, -(hsize.y - hsize.x)} };
		b2CreateCapsuleShape( bodyId, &shapeDef, &capsule );
	}
		break;
	case Shape::CIRCLE:
	{
		b2Circle circle{ b2Vec2{0,0}, hsize.x };
		b2CreateCircleShape(bodyId, &shapeDef, &circle);
	}
		break;
	case Shape::CHAIN:
	{
		
	}
	default:
		break;
	}


}

RigidBody::~RigidBody()
{
	b2DestroyBody(bodyId);
}

void RigidBody::SetTransform(const Vector2& position, float rotation)
{
	b2Body_SetTransform(bodyId, ConvertVec2(Physics::ScreenToWorld(position)), b2MakeRot(Math::DegtoRad(rotation)));
}

Vector2 RigidBody::GetPosition()
{
	return Physics::WorldToScreen(ConvertVec2(b2Body_GetPosition(bodyId)));
}

float RigidBody::GetAngle()
{
	return Math::RadtoDeg(b2Rot_GetAngle(b2Body_GetRotation(bodyId)));
}

void RigidBody::ApplyForce(const Vector2& force)
{
	b2Body_ApplyForceToCenter(bodyId, ConvertVec2(Physics::ScreenToWorld(force)), true);
}

void RigidBody::SetVelocity(const Vector2& velocity)
{
	b2Body_SetLinearVelocity(bodyId, ConvertVec2(Physics::ScreenToWorld(velocity)));
}

Vector2 RigidBody::GetVelocity()
{
	return Physics::WorldToScreen(ConvertVec2(b2Body_GetLinearVelocity(bodyId)));
}

void RigidBody::ApplyTorque(float torque)
{
	b2Body_ApplyTorque(bodyId, torque, true);
}

void RigidBody::SetAngularVelocity(float velocity)
{
	b2Body_SetAngularVelocity(bodyId, velocity);
}