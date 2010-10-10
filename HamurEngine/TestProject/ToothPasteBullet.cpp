#include "ToothPasteBullet.h"
#include "Wave.h"
#include "Collision.h"

using namespace hamur;

void ToothPasteBullet::Update(float deltaTime)
{
	using namespace std;

	//Get enemies from wave and look if they are colliding with this
	std::list<Bacteria *> *bacterias = Wave::GetActiveWave()->GetSpawnedBacterias();
	if(!bacterias->empty())
	{
		std::list<Bacteria *>::iterator Iter;
		for(Iter = bacterias->begin(); Iter != bacterias->end(); ++Iter)
		{
			if(Collision::RectsIntersectWith(this, (*Iter)))
			{
				HAMURWORLD->DeleteObject(this->GetName());
				HAMURWORLD->DeleteObject((*Iter)->GetName());
				HAMURCONSOLE << "Objeler silindi\n";
				bacterias->erase(Iter);
				return;
			}
		}
	}

	Bullet::Update(deltaTime);

	if(mPos.x < -5 || mPos.y < -5 || mPos.x > HamurOpenGL::GetInstance()->GetScreenWidth() + 5 || 
		mPos.y > HamurOpenGL::GetInstance()->GetScreenHeight() + 5)
	{
		this->SetVisible(false);
		this->SetActive(false);
	}
}

void ToothPasteBullet::Draw(float deltaTime)
{
	HamurPlotter::DrawSolidCircle(mPos, 3, HamurColor::YELLOW);
}

void ToothPasteBullet::Explode()
{
	
}