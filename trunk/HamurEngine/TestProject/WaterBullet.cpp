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
		std::list<Bacteria *> *bacterias = Wave::GetAllSpawnedBacterias();
		std::list<Bacteria *>::iterator Iter;
	
		for(Iter = bacterias->begin(); Iter != bacterias->end(); Iter++)
		{
			if((*Iter)->DecreaseLife(1))
			{
				HAMURWORLD->DeleteObject((*Iter)->GetName());
				bacterias->erase(Iter);
				Iter = bacterias->begin();
			}
		}
	
	
		mRemainingCooldown = mCooldownTime;
		mIsUsable = false;
	}
}