#include "Bullet.h"

using namespace hamur;

Bullet::Bullet( const string &name, const HamurVec3 &startingPos, 
			   const HamurVec3 &targetPos, const float &speed) : HamurObject(name), mSpeed(speed)
{
	mPos = startingPos;
	mMovementDir = targetPos - startingPos;
	mMovementDir.Normalize();
}

Bullet::Bullet( const string &name, const string &sprite, const HamurVec3 &startingPos, 
			   const HamurVec3 &targetPos, const float &speed) : HamurObject(name, sprite), mSpeed(speed)
{
	mPos = startingPos;
	mMovementDir = targetPos - startingPos;
	mMovementDir.Normalize();
}

void Bullet::Update( float deltaTime )
{
	mPos.x += mMovementDir.x * mSpeed * deltaTime;
	mPos.y += mMovementDir.y * mSpeed * deltaTime;
	mPos.z += mMovementDir.z * mSpeed * deltaTime;

	//TODO:Some collision calculations must be done to see if the bullet hit something
}

void Bullet::SetTarget(const HamurVec3 &target)
{
	mMovementDir = target - mPos;
	mMovementDir.Normalize();
}