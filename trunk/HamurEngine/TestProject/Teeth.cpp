#include "Teeth.h"

float Teeth::mLife = 100;
float Teeth::mShield = 100;

Teeth::Teeth(const string &name, const string &sprite, float life, float shield):HamurObject(name, sprite)
{
	mLife = life;
	mShield = shield;
}

void Teeth::Reset()
{

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

//void Draw(float deltaTime);