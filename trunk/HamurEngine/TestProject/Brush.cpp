#include "Brush.h"
#include "Base.h"
#include "IngameState.h"

using namespace hamur;

Brush::Brush( const string &name, const float &cooldown) : Bullet(name, HamurVec3(0, 0, 0), HamurVec3(0, 0, 0), 0),
mCooldown(cooldown)
{
}

void Brush::Update( float deltaTime )
{
	//Calculating cooldown time
	if(!mIsUsable)
	{
		mRemainingCooldown -= deltaTime;

		if(mRemainingCooldown <= 0)
			mIsUsable = true;
	}

}

void Brush::Explode()
{
	for(int i = 0; i < MAXTEETH; i++)
	{
		HamurString str;
		str << i;
		Tooth *t = (Tooth *)HAMURWORLD->GetHamurObject("Tooth" + str.GetString());

		//TODO:Value of shield increase must be set
		t->SetShield(t->GetShield() + 3);
	}

	mRemainingCooldown = mCooldown;
	mIsUsable = false;
}