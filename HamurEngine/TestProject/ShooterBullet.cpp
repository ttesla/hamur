#include "ShooterBullet.h"
#include "Collision.h"
#include "Teeth.h"

ShooterBullet::ShooterBullet(const string &name, const hamur::HamurVec3 &startingPos, 
		const hamur::HamurVec3 targetPos, const float &speed) : Bullet(name, startingPos, targetPos, speed), startingPosition(startingPos)
{
	mBulletType = BulletTypes::ShooterBulletType;
	mWidth = 3;
	mHeight = 3;
	mDamage = 1;
}

void ShooterBullet::Update(float deltaTime)
{	
	list<Tooth *> teeth = Tooth::GetTeeth();
	list<Tooth *>::iterator Iter;

	for(Iter = teeth.begin(); Iter != teeth.end(); Iter++)
	{
		if(Collision::RectsIntersectWith(this, (*Iter)))
		{
			Teeth *t = static_cast<Teeth *>(HAMURWORLD->GetHamurObject("teeth"));
			if((*Iter)->GetShield() > 0)
			{
				cout << "Shield: " << (*Iter)->GetShield() << endl;
				t->DecreaseShield(deltaTime * mDamage);
			}
			else
			{
				cout << "Life: " << (*Iter)->GetLife() << endl;
				t->DecreaseHealth(deltaTime * mDamage);
			}

			// Unactivate the bullets
			this->SetActive(false);
			this->SetVisible(false);
		}
	}

	/*
	//Get enemies from wave and look if they are colliding with this
	list<Bacteria *> *bacterias = Wave::GetActiveWave()->GetSpawnedBacterias();
	if(!bacterias->empty())
	{
		list<Bacteria *>::iterator Iter;
		for(Iter = bacterias->begin(); Iter != bacterias->end(); ++Iter)
		{
			if(Collision::RectsIntersectWith(this, (*Iter)))
			{
				ResetBullet();		
				if((*Iter)->DecreaseLife(1))
				{
					HAMURWORLD->DeleteObject((*Iter)->GetName());
					bacterias->erase(Iter);
				}
				return;
			}
		}
	}
	*/

	Bullet::Update(deltaTime);

	if(mPos.x < -5 || mPos.y < -5 || mPos.x > HamurOpenGL::GetInstance()->GetScreenWidth() + 5 || 
		mPos.y > HamurOpenGL::GetInstance()->GetScreenHeight() + 5)
	{
		this->SetVisible(false);
		this->SetActive(false);
		ResetBullet();
	}
}

void ShooterBullet::Draw(float deltaTime)
{
	HamurPlotter::DrawSolidCircle(mPos, 3, HamurColor::MAGENTA);
}

void ShooterBullet::Explode()
{
	
}

void ShooterBullet::ResetBullet()
{
	this->SetVisible(false);
	this->SetActive(false);

	mPos = startingPosition;
}