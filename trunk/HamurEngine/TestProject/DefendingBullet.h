#pragma once


#include "hamur.h"

class IngameState;

class Bullet : public hamur::HamurObject
{
public:

	Bullet(string name, hamur::HamurVec3 pos, hamur::HamurObject *target, IngameState *state );
	void Update();
	void Draw();

private:
	IngameState *mState;
	hamur::HamurObject *target;
	hamur::HamurVec3 movementDir;
	float mSpeed;
	

};