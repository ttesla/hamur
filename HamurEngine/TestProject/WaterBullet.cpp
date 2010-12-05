#include "WaterBullet.h"
#include "Bacteria.h"
#include "Wave.h"
#include "Animation.h"

WaterBullet::WaterBullet(const string &name, const float &cooldown) : 
Bullet(name, hamur::HamurVec3(0, 0, 0), hamur::HamurVec3(0, 0, 0), 0), mCooldownTime(cooldown)
{
	mBulletType = BulletTypes::WaterBulletType;
	mAnimation = new Animation("Graphics/Water/water", 4);
}

void WaterBullet::Update( float deltaTime )
{
	mAnimation->Update(deltaTime * 5);
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
	mAnimation->Draw(HamurVec3(HamurOpenGL::GetInstance()->GetScreenWidth() / 2, 
		HamurOpenGL::GetInstance()->GetScreenHeight() / 2, 0), 
		HamurOpenGL::GetInstance()->GetScreenWidth(),
		HamurOpenGL::GetInstance()->GetScreenHeight(), 0);
}

void WaterBullet::Explode()
{
	if (mIsUsable)
	{
		mAnimation->PlayAnimation(false);

		std::list<Bacteria *> eraseList;

		//Get enemies from wave and damage all
		std::list<Bacteria *> *bacterias = Wave::GetAllSpawnedBacterias();
		std::list<Bacteria *>::iterator Iter;
	
		for(Iter = bacterias->begin(); Iter != bacterias->end(); Iter++)
		{
			if((*Iter)->DecreaseLife(1))
			{
				eraseList.push_back((*Iter));
				/*bacterias->erase(Iter++);
				if(bacterias->end() == Iter)
					break;*/
			}
		}

		for(Iter = eraseList.begin(); Iter != eraseList.end(); Iter++)
		{
			HAMURWORLD->DeleteObject((*Iter)->GetName());
			bacterias->remove((*Iter));
		}

		eraseList.clear();
	
	
		mRemainingCooldown = mCooldownTime;
		mIsUsable = false;
	}
}