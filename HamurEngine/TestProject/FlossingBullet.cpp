#include "FlossingBullet.h"
#include "Wave.h"
#include "Tooth.h"
#include "Collision.h"

#include <list>

using namespace std;
using namespace hamur;

void FlossingBullet::Update( float deltaTime )
{
	using namespace hamur;
	HamurVec3 distance = mPos - startingPosition;

	list<Tooth *> teeth = Tooth::GetTeeth();
	list<Tooth *>::iterator Iter;

	for(Iter = teeth.begin(); Iter != teeth.end(); Iter++)
	{
		if(Collision::RectsIntersectWith(this, (*Iter)))
		{
			Explode();

			SetVisible(false);
			SetActive(false);
			mPos = startingPosition;

			return;
		}
	}

	Bullet::Update(deltaTime);
	
	if(mPos.x < -5 || mPos.y < -5 || mPos.x > HamurOpenGL::GetInstance()->GetScreenWidth() + 5 || 
		mPos.y > HamurOpenGL::GetInstance()->GetScreenHeight() + 5)
	{
		this->SetVisible(false);
		this->SetActive(false);
		mPos = startingPosition;
	}

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
			if(distance.Length() < 50)
			{
				//TODO:Set damage
				if((*Iter)->DecreaseLife(100))
				{
					HAMURWORLD->DeleteObject((*Iter)->GetName());
					bacterias->erase(Iter++);
				}
			}
		}
	}
}
