#pragma once

#include "Bullet.h"

class Base;

class Brush : public Bullet
{
public:
	Brush(const string &name, const float &cooldown);

	void Update(float deltaTime);
	void Draw(float deltaTime){};
	void Explode();

	inline bool IsUsable(){return mIsUsable;}

private:
	int mUsedTimes;
	float mCooldown;
	float mRemainingCooldown;
	bool mIsUsable;
};