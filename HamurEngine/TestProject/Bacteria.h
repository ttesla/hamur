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
        virtual void Draw()=0;
		virtual void Update()=0;
		//void setPhysics(); We are not using physics at the moment...

		bool IsActive(){return mActive;}
		void SetActive(bool isActive){mActive = isActive;}

		float GetLife(){return mLife;}
		float GetShield(){return mShield;}
		void SetLife(float pLife){mLife = pLife;}
		void SetShield(float pShield){mShield = pShield;}
		HamurVec3 GetMovementDirection(){return movementDirection;}

	protected:
		HamurVec3 mBasePosition;
		HamurVec3 movementDirection;
		bool mActive;
		float mLife;
		float mShield;
};

#endif

