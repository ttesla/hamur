#include "WaterBullet.h"
#include "Bacteria.h"
#include "Wave.h"

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
	if (mIsUsable)
	{
		//Get enemies from wave and damage all
		std::list<Bacteria *> *bacterias = Wave::GetActiveWave()->GetSpawnedBacterias();
		std::list<Bacteria *>::iterator Iter;
	
		for(Iter = bacterias->begin(); Iter != bacterias->end(); Iter++)
		{
			(*Iter)->SetLife((*Iter)->GetLife() - 1);
		}
	
	
		mRemainingCooldown = mCooldownTime;
		mIsUsable = false;
	}
}