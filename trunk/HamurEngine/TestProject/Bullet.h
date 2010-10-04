#pragma once

#include "hamur.h"

class Bullet : hamur::HamurObject
{
public:
	Bullet(const string &name);

	void Update(float deltaTime);

private:
	hamur::HamurVec3 movingDirection;
	float movingSpeed;
	float range;
	float damageArea;
};