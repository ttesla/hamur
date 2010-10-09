#include "FlossingBullet.h"

using namespace hamur;

void FlossingBullet::Update( float deltaTime )
{

	Bullet::Update(deltaTime);
}

void FlossingBullet::Draw( float deltaTime )
{
	HamurPlotter::DrawSolidCircle(mPos.x, mPos.y, 5, HamurColor::BLUE);
}

void FlossingBullet::Explode()
{
	//Get enemies from wave and calculate their distances
}