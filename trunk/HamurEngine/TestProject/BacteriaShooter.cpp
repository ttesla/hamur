#include "BacteriaShooter.h"
#include <cstdlib> 
#include <ctime> 
using namespace std;
 
BacteriaShooter::BacteriaShooter(const string &name, const string &sprite, HamurVec3 basePosition, const float &speed):Bacteria(name, sprite, basePosition, speed)
{
	// We set Life and Shield for Norms
	this->SetLife(2.0); // Example values at the moment
	this->SetShield(3.0); 
	this->mRadius = 200;
	this->mLastShot = SDL_GetTicks();
    //setPhysics();

	// The shooter bacteria will have some ShooterBullets
	for(int i = 0; i < 64; i++)
	{
		HamurString str;
		str << i;
		Bullet *b = new ShooterBullet("ShooterBullet" + str.GetString(), mPos, mBasePosition, 300); 
		b->SetActive(false);
		b->SetVisible(false);

		mBullets.push_back(b);
	}
}

void BacteriaShooter::Fire(const HamurVec3 &targetPos)
{
	vector<Bullet *>::iterator Iter;

	for(Iter = mBullets.begin(); Iter != mBullets.end(); Iter++)
	{
		if(!(*Iter)->IsActive() && !(*Iter)->IsVisible())
		{
			(*Iter)->SetPosition(mPos);
			(*Iter)->SetTarget(targetPos);
			(*Iter)->SetActive(true);
			(*Iter)->SetVisible(true);
			break;
		}
	}
}

bool BacteriaShooter::IsAttacking2Tooth(float deltaTime)
{
	if (isMoving())
	{
		HamurVec3 dif = this->GetPosition() - mBasePosition;
	
		// Dif to be checked
		if (dif.Length() < mRadius) 
		{
			this->movementDirection.SetZero();
		}
	}
	// Check if it is shooting teeth

	return false;
}

bool BacteriaShooter::isMoving()
{
	return (this->movementDirection.Length() != 0);
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

void BacteriaShooter::Draw(float deltaTime)
{
	// Draw yellow circles
	HamurPlotter::DrawSolidCircle(mPos.x, mPos.y, mWidth, HamurColor::WHITE);
}
*/

void BacteriaShooter::Update(float deltaTime)
{
	if (SDL_GetTicks() - mLastShot > 1500)
	{
		Fire (mBasePosition);
		mLastShot = SDL_GetTicks();	
	}

	Bacteria::Update(deltaTime);
}

