#pragma once


#include "hamur.h"

class IngameState;

class Bullet : public hamur::HamurObject
{
public:

	Bullet(string name, hamur::HamurVec3 pos, hamur::HamurObject *target, IngameState *state );
	void Update(float deltaTime);
	void Draw(float deltaTime);

private:
	IngameState *mState;
	hamur::HamurObject *target;
	hamur::HamurVec3 movementDir;
	float mSpeed;
	

};