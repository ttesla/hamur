#include "Bullet.h"

using namespace hamur;

Bullet::Bullet( const string &name ) : HamurObject(name)
{

}

void Bullet::Update( float deltaTime )
{
	mPos.x += movingDirection.x * movingSpeed;
	mPos.y += movingDirection.y * movingSpeed;
	mPos.z += movingDirection.z * movingSpeed;

	//TODO:Some collision calculations must be done to see if the bullet hit something
}