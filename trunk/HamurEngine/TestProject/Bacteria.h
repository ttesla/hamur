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
		Bacteria(const string& name, hamur::HamurVec3 basePos);
		virtual void Draw(float deltaTime){};
		virtual void Update(float deltaTime){};
		//void setPhysics(); We are not using physics at the moment...

		bool IsActive(){return mActive;}

		float GetLife(){return mLife;}
		float GetShield(){return mShield;}
		void SetLife(float pLife){mLife = pLife;}
		void SetShield(float pShield){mShield = pShield;}
		HamurVec3 GetMovementDirection(){return movementDirection;}

	protected:
		HamurVec3 mBasePosition;
		HamurVec3 movementDirection;
		float mLife;
		float mShield;
};

#endif

