#pragma once

#include "hamur.h"

enum BulletTypes
{
	ToothPasteBulletType,
	FlossingBulletType,
	WaterBulletType,
	BrushBulletType,
	ShooterBulletType
};

class Bullet : public hamur::HamurObject
{
public:

	Bullet(const string &name, const hamur::HamurVec3 &startingPos, 
		const hamur::HamurVec3 &targetPos, const float &speed);
	Bullet(const string &name, const string &sprite, const hamur::HamurVec3 &startingPos, 
		const hamur::HamurVec3 &targetPos, const float &speed);
	virtual void Update(float deltaTime);
	// virtual void Draw(float deltaTime){};
	virtual void Explode(){};
	virtual void ResetBullet(){};

	void SetTarget(const hamur::HamurVec3 &target);

	inline BulletTypes GetBulletType() {return mBulletType;}
	inline void SetBulletType(const BulletTypes &bulletType) {mBulletType = bulletType;}

protected:

	hamur::HamurVec3 mMovementDir;
	BulletTypes mBulletType;
	float mSpeed;
	float mDamage;
};