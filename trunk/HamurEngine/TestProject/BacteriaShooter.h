#ifndef BACTERIASHOOTER_H
#define BACTERIASHOOTER_H

#include "Bacteria.h"
#include "Bullet.h"
#include "ShooterBullet.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.3;

class BacteriaShooter : public Bacteria
{
    public:
		BacteriaShooter(const string& name, const string& sprite, const int &spriteCount, HamurVec3 basePos, const float &speed);
		virtual ~BacteriaShooter();
		virtual bool IsAttacking2Tooth(float deltaTime);
        //virtual void Draw(float deltaTime);	
		virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...
		bool isMoving();
		void Fire(const HamurVec3 &targetPos);

	private:
		// Minimun length or distance to the base
		int mRadius;
		// Bullets to shoot
		vector<Bullet *> mBullets;
		// Last shot 
		int mLastShot;
};

#endif

