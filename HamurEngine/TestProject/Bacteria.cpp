#include "Bacteria.h"
#include <cstdlib> 
#include <ctime> 
#include "Tooth.h"
#include "Collision.h"
using namespace std;

#define SPEEDCOEF 0.01;
 
Bacteria::Bacteria(const string &name, const string &sprite, HamurVec3 basePosition, const float &speed):HamurObject(name, sprite), mBasePosition(basePosition), mSpeed(speed)
{
	mActive = false;

	//Distributing bacterias to the borders of screen
	//we can distribute them equally. It' s being done by chance
	int dice = (int)rand() % 4;

	if(dice == 0)
	{
		mPos.x = 0; 
		mPos.y = (int)rand() % (int)HamurOpenGL::GetInstance()->GetScreenHeight();
	}
	else if(dice == 1)
	{
		mPos.x = (int)rand() % (int)HamurOpenGL::GetInstance()->GetScreenWidth(); 
		mPos.y = 0;
	}
	else if(dice == 2)
	{
		mPos.x = (int)rand() % (int)HamurOpenGL::GetInstance()->GetScreenWidth(); 
		mPos.y = HamurOpenGL::GetInstance()->GetScreenHeight();
	}
	else if(dice == 3)
	{
		mPos.x = HamurOpenGL::GetInstance()->GetScreenWidth(); 
		mPos.y = (int)rand() % (int)HamurOpenGL::GetInstance()->GetScreenHeight();
	}

	mPos.z = 0;

	//moving direction towards the base
	movementDirection = mBasePosition - mPos;
	movementDirection.Normalize();
	
	// Don't know at the moment, we'll have to try width & height
    mWidth = 20;
    mHeight = 20;

	mDamage = 1;
}


void Bacteria::Update( float deltaTime )
{
	if(IsAttacking2Tooth(deltaTime))
		return;
	
	mPos.x += movementDirection.x * mSpeed * deltaTime;
	mPos.y += movementDirection.y * mSpeed * deltaTime;

	

}

bool Bacteria::DecreaseLife(int bulletPower)
{
	mLife -= bulletPower;
	
	if (mLife <= 0)
	{
		return true;
	}

	return false;
}

bool Bacteria::IsAttacking2Tooth(float deltaTime)
{
	std::list<Tooth *> teeth = Tooth::GetTeeth();
	std::list<Tooth *>::iterator Iter;

	// Checks if the bacteria is on a tooth. NOT for shooters
	for(Iter = teeth.begin(); Iter != teeth.end(); Iter++)
	{
		if(Collision::RectsIntersectWith(this, (*Iter)))
		{
			if((*Iter)->GetShield() > 0)
			{
				(*Iter)->SetShield((*Iter)->GetShield() - deltaTime * 90);
			}
			else
				(*Iter)->SetLife((*Iter)->GetLife() - deltaTime * 90);

			return true;
		}
	}
	
	return false;
}
/* Not using it at the moment...

void Bacteria::setPhysics()
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set((mPos.x + mWidth / 2) / 100.0f, (mPos.y + mHeight /2) / 100.0f);
    groundBodyDef.userData = this;
    SetBodyDef(groundBodyDef);
        
   // b2Vec2 _center(3.5f, 0.25f);

    mBox.SetAsBox(mWidth / 200.0f, mHeight / 200.0f);
    //setShape(mBox);
   
    b2Vec2 vertices[4];
    vertices[0].Set(0.0f, height / 100.0f);
    vertices[1].Set(width / 100.0f, height / 100.0f);
    vertices[2].Set(width / 100.0f, 0.0f);
    vertices[3].Set(0.0f, 0.0f);

    int vertexCount = 4;

    b2PolygonShape groundBox;
    groundBox.Set(vertices, 4);
    setShape(groundBox);
    

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &mBox;
    SetFixDef(fixtureDef);

    mBody = HAMURWORLD->Getb2World()->CreateBody(&mBodyDef);
    mBody->CreateFixture(&fixtureDef);
}
*/
