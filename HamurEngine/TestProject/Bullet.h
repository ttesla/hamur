#pragma once

#include "hamur.h"

class Bullet : public hamur::HamurObject
{
public:

	Bullet(const string &name, const hamur::HamurVec3 &startingPos, 
		const hamur::HamurVec3 &targetPos, const float &speed );
	virtual void Update(float deltaTime);
	virtual void Draw(float deltaTime){};
	virtual void Explode(){};

private:
	hamur::HamurVec3 mMovementDir;
	float mSpeed;
};