#include "BacteriaStrayer.h"
#include <cstdlib> 
#include <ctime> 
using namespace std;
 
BacteriaStrayer::BacteriaStrayer(const string &name, hamur::HamurVec3 basePosition, const float &speed):Bacteria(name, basePosition, speed)
{
	// We set Life and Shield for Norms
	this->SetLife(2.0); // Example values at the moment
	this->SetShield(3.0); 
	this->mPrevTickCount = (double)SDL_GetTicks();
	this->mMovementRange = 100;
	this->mSideMovFactor = 5;
}

void BacteriaStrayer::Draw(float deltaTime)
{
	// Draw yellow circles
	HamurPlotter::DrawSolidCircle(mPos.x, mPos.y, mWidth, HamurColor::RED);
}

void BacteriaStrayer::Update(float deltaTime)
{
	if(IsAttacking2Tooth(deltaTime))
		return;

	if (SDL_GetTicks() - mPrevTickCount <= mMovementRange)
	{	
		mPos.x += sin(((double)mPrevTickCount)) / mSideMovFactor;	
		mPos.y += cos(((double)mPrevTickCount)) / mSideMovFactor;	
	}
	else
		mPrevTickCount = SDL_GetTicks();

	Bacteria::Update(deltaTime);
}