#ifndef BACTERIA_H
#define BACTERIA_H

#include "hamur.h"

using namespace hamur;

/**
*	This is an abstract bacteria class.
*	Each concrete bacteria would have its own life, shield and speedcoef
*/
class Bacteria : public HamurObject
{
    public:
		Bacteria(const string& name, const string& sprite, HamurVec3 basePos, const float &speed);
		void Draw(float deltaTime){HamurObject::Draw(deltaTime);};
		virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...

		bool IsActive(){return mActive;}

		float GetLife(){return mLife;}
		float GetShield(){return mShield;}
		void SetLife(float pLife){mLife = pLife;}
		void SetShield(float pShield){mShield = pShield;}
		HamurVec3 GetMovementDirection(){return movementDirection;}

		// returns true: bacteria killed, false otherwise
		bool DecreaseLife (int bulletPower);
		virtual bool IsAttacking2Tooth(float deltaTime);

	protected:
		HamurVec3 mBasePosition;
		HamurVec3 movementDirection;
		float mLife;
		float mShield;
		float mSpeed;
		float mDamage;
};

#endif

