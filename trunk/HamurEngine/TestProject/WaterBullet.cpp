#include "WaterBullet.h"

void WaterBullet::Update( float deltaTime )
{
	//Calculating cooldown time
	if(!mIsUsable)
	{
		mRemainingCooldown -= deltaTime;

		if(mRemainingCooldown <= 0)
			mIsUsable = true;
	}


}

void WaterBullet::Draw( float deltaTime )
{

}

void WaterBullet::Explode()
{
	//Get enemies from wave and damage all	

	mRemainingCooldown = mCooldownTime;
	mIsUsable = false;
}