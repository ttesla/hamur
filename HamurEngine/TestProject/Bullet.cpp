#include "Bullet.h"

using namespace hamur;

Bullet::Bullet( const string &name, const HamurVec3 &startingPos, 
			   const HamurVec3 &targetPos, const float &speed) : HamurObject(name), mSpeed(speed)
{
	mPos = startingPos;
	mMovementDir = targetPos - startingPos;
	mMovementDir.Normalize();
}

void Bullet::Update( float deltaTime )
{
	mPos.x += mMovementDir.x * mSpeed;
	mPos.y += mMovementDir.y * mSpeed;
	mPos.z += mMovementDir.z * mSpeed;

	//TODO:Some collision calculations must be done to see if the bullet hit something
}