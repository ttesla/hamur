#include "ToothPasteBullet.h"

using namespace hamur;

void ToothPasteBullet::Update(float deltaTime)
{
	Bullet::Update(deltaTime);

	//Get enemies from wave and look if they are colliding with this
}

void ToothPasteBullet::Draw(float deltaTime)
{
	HamurPlotter::DrawSolidCircle(mPos, 3, HamurColor::YELLOW);
}

void ToothPasteBullet::Explode()
{
	
}