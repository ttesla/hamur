#ifndef BACTERIA_H
#define BACTERIA_H

#include "hamur.h"
#include "Animation.h"

using namespace hamur;

class Teeth;

/**
*	This is an abstract bacteria class.
*	Each concrete bacteria would have its own life, shield and speedcoef
*/
class Bacteria : public HamurObject
{
    public:
		Bacteria(const string& name, const string& sprite, const int &spriteCount, HamurVec3 basePos, const float &speed);
		virtual ~Bacteria();
		void Draw(float deltaTime);
		virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...

		bool IsActive(){return mActive;}

		float GetLife(){return mLife;}
		float GetShield(){return mShield;}
		float GetDamage(){return mDamage;}
		void SetLife(float pLife){mLife = pLife;}
		void SetShield(float pShield){mShield = pShield;}
		void SetDamage(float pDamage){mDamage = pDamage;}

		HamurVec3 GetMovementDirection(){return movementDirection;}
		virtual string GetType() = 0;
		virtual int GetInitialLife() = 0;
		// returns true: bacteria killed, false otherwise
		bool DecreaseLife (int bulletPower);
		virtual bool IsAttacking2Tooth(float deltaTime);

		void ResetMovement();

		void SetAnimation(const string& sprite, const int &spriteCount);
		virtual void DoHit() = 0;
		virtual void UndoHit() = 0;

	protected:
		Teeth *mTeeth;
		Animation *mAnimation;
		HamurVec3 mBasePosition;
		HamurVec3 movementDirection;
		float mLife;
		float mShield;
		float mSpeed;
		float mDamage;

		float mHitTimer;
};

#endif

