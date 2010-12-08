#include "BacteriaShooter.h"
#include <cstdlib> 
#include <ctime> 
using namespace std;
 
BacteriaShooter::BacteriaShooter(const string &name, const string &sprite, const int &spriteCount, HamurVec3 basePosition, const float &speed):Bacteria(name, sprite, spriteCount, basePosition, speed)
{
	// We set Life and Shield for Norms
	this->SetLife(2.0); // Example values at the moment
	this->SetShield(3.0); 
	this->mRadius = 200;
	this->mLastShot = SDL_GetTicks();
    //setPhysics();

	// The shooter bacteria will have some ShooterBullets
	for(int i = 0; i < 64; i++)
	{
		Bullet *b = new ShooterBullet(name + " ShooterBullet" + HamurString::ParseInt(i).GetString(), 
			"Graphics/shooterbullet.png", mPos, mBasePosition, 300); 
		b->SetActive(false);
		b->SetVisible(false);

		mBullets.push_back(b);
	}
}

void BacteriaShooter::Fire(const HamurVec3 &targetPos)
{
	vector<Bullet *>::iterator Iter;

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

bool BacteriaShooter::IsAttacking2Tooth(float deltaTime)
{
	if (isMoving())
	{
		HamurVec3 dif = this->GetPosition() - mBasePosition;
	
		// Dif to be checked
		if (dif.Length() < mRadius) 
		{
			this->movementDirection.SetZero();
		}
	}

	return false;
}

bool BacteriaShooter::isMoving()
{
	return (this->movementDirection.Length() != 0);
}

/*
void BacteriaShooter::Draw(float deltaTime)
{
	// Draw yellow circles
	HamurPlotter::DrawSolidCircle(mPos.x, mPos.y, mWidth, HamurColor::WHITE);
}
*/

void BacteriaShooter::Update(float deltaTime)
{
	if (SDL_GetTicks() - mLastShot > 500)
	{
		Fire (mBasePosition);
		mLastShot = SDL_GetTicks();	
	}

	/* Edu: To erase bullets
	vector<Bullet *>::iterator Iter;
	for(Iter = mBullets.begin(); Iter != mBullets.end() && !mBullets.empty() ; Iter++)
	{
		if((*Iter)->IsActive() && !(*Iter)->IsVisible())
		{
			mBullets.erase(Iter);
			HAMURWORLD->DeleteObject(this->GetName());
		}
	}
	*/

	Bacteria::Update(deltaTime);
}

void BacteriaShooter::DoHit()
{
	this->SetAnimation("Graphics/bact_shooter/bact_shooter_hit", 1);
	this->mHitTimer = 2.99;
}

void BacteriaShooter::UndoHit()
{
	this->SetAnimation("Graphics/bact_shooter/bact_shooter", 3);
	this->mHitTimer = 3;
}

BacteriaShooter::~BacteriaShooter()
{
	std::vector<Bullet *>::iterator Iter;

	for(Iter = mBullets.begin(); Iter != mBullets.end(); Iter++)
		HAMURWORLD->DeleteObject((*Iter)->GetName());
}
