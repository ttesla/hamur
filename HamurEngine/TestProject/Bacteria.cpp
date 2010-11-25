#include "Bacteria.h"
#include <cstdlib> 
#include <ctime> 
#include "Tooth.h"
#include "Teeth.h"
#include "Collision.h"
using namespace std;

#define SPEEDCOEF 0.01;
 
Bacteria::Bacteria(const string &name, const string &sprite, const int &spriteCount, HamurVec3 basePosition, const float &speed):HamurObject(name), mBasePosition(basePosition), mSpeed(speed)
{
	mActive = false;
	mTeeth = static_cast<Teeth *>(HAMURWORLD->GetHamurObject("teeth"));
	
	//Distributing bacterias to the borders of screen
	//we can distribute them equally. It' s being done by chance
	int dice = (int)rand() % 4;

	if(dice == 0)
	{
		mPos.x = 0; 
		mPos.y = (int)rand() % (int)HamurOpenGL::GetInstance()->GetScreenHeight();
	}
	else if(dice == 1)
	{
		mPos.x = (int)rand() % (int)HamurOpenGL::GetInstance()->GetScreenWidth(); 
		mPos.y = 0;
	}
	else if(dice == 2)
	{
		mPos.x = (int)rand() % (int)HamurOpenGL::GetInstance()->GetScreenWidth(); 
		mPos.y = HamurOpenGL::GetInstance()->GetScreenHeight();
	}
	else if(dice == 3)
	{
		mPos.x = HamurOpenGL::GetInstance()->GetScreenWidth(); 
		mPos.y = (int)rand() % (int)HamurOpenGL::GetInstance()->GetScreenHeight();
	}

	mPos.z = 0;

	//moving direction towards the base
	movementDirection = mBasePosition - mPos;
	movementDirection.Normalize();
	
	// Don't know at the moment, we'll have to try width & height
    mWidth = 20;
    mHeight = 20;

	mDamage = 3;

	mAnimation = new Animation(sprite, spriteCount);
	mAnimation->PlayAnimation(true);
}

void Bacteria::Draw(float deltaTime)
{
	//HamurObject::Draw(deltaTime);
	mAnimation->Draw(mPos, mRotation);
}

void Bacteria::Update( float deltaTime )
{
	mAnimation->Update(deltaTime * 5);

	if(IsAttacking2Tooth(deltaTime))
		return;

	if (mPos.x > 800 || mPos.x < 0 || mPos.y > 600 || mPos.y < 0)
		ResetMovement();
	
	mPos.x += movementDirection.x * mSpeed * deltaTime;
	mPos.y += movementDirection.y * mSpeed * deltaTime;
}

bool Bacteria::DecreaseLife(int bulletPower)
{
	mLife -= bulletPower;
	
	if (mLife <= 0)
	{
		return true;
	}

	return false;
}

bool Bacteria::IsAttacking2Tooth(float deltaTime)
{
	std::list<Tooth *> teeth = Tooth::GetTeeth();
	std::list<Tooth *>::iterator Iter;

	// Checks if the bacteria is on a tooth. NOT for shooters
	for(Iter = teeth.begin(); Iter != teeth.end(); Iter++)
	{
		if(Collision::RectsIntersectWith(this, (*Iter)))
		{
			//if (mTeeth->GetShield() > 0)
			//{
			//	cout << "Shield: " << mTeeth->GetShield() << endl;
			//	mTeeth->DecreaseShield(deltaTime * mDamage);			
			//}
			//else
			//{
			//	cout << "Life: " << mTeeth->GetHealth() << endl;
			//	mTeeth->DecreaseHealth(deltaTime * mDamage);
			//}
			mTeeth->HitDamage(deltaTime * mDamage);
			
			return true;
		}
	}
	
	return false;
}

void Bacteria::ResetMovement()
{
	movementDirection = mBasePosition - mPos;
	movementDirection.Normalize();
}

Bacteria::~Bacteria()
{
	delete mAnimation;
}