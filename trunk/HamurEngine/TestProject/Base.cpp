#include "Base.h"
//#include "Bullet.h"
#include "ToothPasteBullet.h"
#include "FlossingBullet.h"
#include "IngameState.h"
#include "Bacteria.h"
#include "WaterBullet.h"

//#include <cstdlib> 
//#include <ctime> 
#include <iostream>
using namespace std;

Base::Base(const string &name):HamurObject(name), killedEnemyCount(0)
{
    mWidth = 20;
    mHeight = 20;

	mPos.x = HamurOpenGL::GetInstance()->GetScreenWidth() / 2 - mWidth / 2; 
	mPos.y = HamurOpenGL::GetInstance()->GetScreenHeight() / 2 - mHeight / 2;
	mPos.z = 0;

	//ToothpasteBullet
	for(int i = 0; i < 64; i++)
	{
		HamurString str;
		str << i;
		Bullet *b = new ToothPasteBullet("ToothPasteBullet" + str.GetString(), mPos, 
			HamurVec3(0, 0, 0), 300);

		b->SetActive(false);
		b->SetVisible(false);

		mBullets.push_back(b);
	}

	//FlossingBullet
	for(int i = 0; i < 16; i++)
	{
		HamurString str;
		str << i;
		Bullet *b = new FlossingBullet("FlossingBullet" + str.GetString(), mPos, 
			HamurVec3(0, 0, 0), 150);

		b->SetVisible(false);
		b->SetActive(false);

		mBullets.push_back(b);
	}

	//WaterBullet. Because of having cooldown and can be used once per time, one instance is enough
	mWater = new WaterBullet("WaterBullet", 5);
	mFlossingBulletCooldown = 3;
	mLastFlossingBulletFiredTime = 3;
}


void Base::Draw(float deltaTime)
{
    HamurPlotter::DrawSolidRectangle(mPos, mWidth, mHeight, HamurColor::GREY);
}

void Base::Update(float deltaTime)
{
	if(mSelectedWeaponType == BulletTypes::FlossingBulletType)
		mLastFlossingBulletFiredTime += HAMURTIMER->DeltaTime();
}

void Base::Fire(const HamurVec3 &targetPos)
{
	//TODO:Selected type of weapon should be fired
	using namespace std;

	if(mSelectedWeaponType == BulletTypes::FlossingBulletType)
	{
		if(mLastFlossingBulletFiredTime < mFlossingBulletCooldown)
			return;

		mLastFlossingBulletFiredTime = 0;
	}

	std::vector<Bullet *>::iterator Iter;

	for(Iter = mBullets.begin(); Iter != mBullets.end(); Iter++)
	{
		if(!(*Iter)->IsActive() && !(*Iter)->IsVisible() && 
			(*Iter)->GetBulletType() == mSelectedWeaponType )
		{
			(*Iter)->SetPosition(mPos);
			(*Iter)->SetTarget(targetPos);
			(*Iter)->SetActive(true);
			(*Iter)->SetVisible(true);
			break;
		}
	}
}

void Base::UseWater()
{
	mWater->Explode();
}