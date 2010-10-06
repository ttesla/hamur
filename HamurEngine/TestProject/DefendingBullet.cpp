#include "DefendingBullet.h"
#include "hamurDefinitions.h"
#include "IngameState.h"

using namespace hamur;

Bullet::Bullet( string name, hamur::HamurVec3 pos, hamur::HamurObject *target, IngameState *state) : HamurObject(name)
{
	mState = state;
	this->target = target;
	mPos = pos;
	mSpeed = 0.3;
}

void Bullet::Update()
{
	movementDir = target->GetPosition() - mPos;
	movementDir.Normalize();
	movementDir = movementDir * mSpeed;


	mPos.x += movementDir.x;
	mPos.y += movementDir.y;


	if((mPos - target->GetPosition()).GetLength() < 2)
	{
		/*mState->GetActiveObjList()->remove(target);
		mState->GetActiveObjList()->remove(this);

		HAMURWORLD->DeleteObject(target->GetName());
		HAMURWORLD->DeleteObject(mName);*/
		mState->killObj1 = target;
		mState->killObj2 = this;
		return;
	}

	//TODO: Control the position of bullet to see if it' s out of the screen
}

void Bullet::Draw()
{
	hamur::HamurPlotter::DrawCircle(mPos, 3, hamur::HamurColor::WHITE);
}
