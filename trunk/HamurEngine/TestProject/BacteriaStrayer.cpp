#include "BacteriaStrayer.h"
#include <cstdlib> 
#include <ctime> 
using namespace std;
 
BacteriaStrayer::BacteriaStrayer(const string &name, const string &sprite, HamurVec3 basePosition, const float &speed):Bacteria(name, sprite, basePosition, speed)
{
	// We set Life and Shield for Norms
	this->SetLife(2.0); // Example values at the moment
	this->SetShield(3.0); 
	this->mPrevTickCount = (double)SDL_GetTicks();
	this->mMovementRange = 500;
	this->mSideMovFactor = 1;
}

/*
void BacteriaStrayer::Draw(float deltaTime)
{
	// Draw yellow circles
	HamurPlotter::DrawSolidCircle(mPos.x, mPos.y, mWidth, HamurColor::RED);
}
*/

void BacteriaStrayer::Update(float deltaTime)
{
	if(IsAttacking2Tooth(deltaTime))
	{
		return;
	}

	if (SDL_GetTicks() - mPrevTickCount <= mMovementRange)
	{	
		mPos.x += sin(((double)mPrevTickCount)) / mSideMovFactor;	
		mPos.y += cos(((double)mPrevTickCount)) / mSideMovFactor;	
	}
	else
		mPrevTickCount = SDL_GetTicks();

	Bacteria::Update(deltaTime);
}
