#include "Base.h"
#include "ToothPasteBullet.h"
#include "IngameState.h"
#include "Bacteria.h"
#include "Bullet.h"

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

	//TODO:Instantiate some flossingBullet
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
}


void Base::Draw(float deltaTime)
{
  
    HamurPlotter::DrawSolidRectangle(mPos, mWidth, mHeight, HamurColor::GREY);
}

void Base::Update(float deltaTime)
{
	
}

void Base::Fire(const HamurVec3 &targetPos)
{
	//TODO:Selected type of weapon should be fired
	using namespace std;

	std::vector<Bullet *>::iterator Iter;

	for(Iter = mBullets.begin(); Iter != mBullets.end(); Iter++)
	{
		if(!(*Iter)->IsActive() && !(*Iter)->IsVisible())
		{
			(*Iter)->SetPosition(mPos);
			(*Iter)->SetTarget(targetPos);
			(*Iter)->SetActive(true);
			(*Iter)->SetVisible(true);
			break;
		}
	}
}