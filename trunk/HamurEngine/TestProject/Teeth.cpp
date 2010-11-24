#include "Teeth.h"

Teeth::Teeth(const string &name, const string &sprite, float life, float shield):HamurObject(name, sprite)
{
	mLife = life;
	mShield = shield;
}

void Teeth::Reset()
{
	mLife = mShield = 1000.0;
}

void Teeth::Update(float deltaTime)
{
	/*
	if(mLife <= 0)
	{
		HAMURWORLD->DeleteObject(this->GetName());
	}
	*/
}

void Teeth::HitDamage( const float &value )
{
	mShield -= value;

	if(mShield < 0)
	{
		mLife += mShield;
		mShield = 0;
	}
}