#include "FlossingBullet.h"
#include "Wave.h"

using namespace hamur;

void FlossingBullet::Update( float deltaTime )
{
	using namespace hamur;
	HamurVec3 distance = targetPosition - mPos;
	if(distance.GetLength() < 2)
	{
		Explode();
		
		SetVisible(false);
		SetActive(false);
		mPos = startingPosition;

		return;
	}

	Bullet::Update(deltaTime);
}

void FlossingBullet::Draw( float deltaTime )
{
	HamurPlotter::DrawSolidCircle(mPos.x, mPos.y, 5, HamurColor::BLUE);
}

void FlossingBullet::Explode()
{
	//Get enemies from wave and calculate their distances
	using namespace std;
	list<Bacteria *> *bacterias = Wave::GetActiveWave()->GetSpawnedBacterias();
	list<Bacteria *>::iterator Iter;

	if (!bacterias->empty())
	{
		for(Iter = bacterias->begin(); Iter != bacterias->end(); Iter++)
		{
			HamurVec3 distance = (*Iter)->GetPosition() - mPos; 
			//TODO:Set distance
			if(distance.GetLength() < 10)
			{
				//TODO:Set damage
				(*Iter)->SetLife((*Iter)->GetLife() - 3);
			}
		}
	}
}