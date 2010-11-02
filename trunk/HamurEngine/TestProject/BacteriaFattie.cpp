#include "BacteriaFattie.h"
#include <cstdlib> 
#include <ctime> 
using namespace std;
 
BacteriaFattie::BacteriaFattie(const string &name, const string &sprite, HamurVec3 basePosition, const float &speed):Bacteria(name, sprite, basePosition, speed)
{
	// We set Life and Shield for Norms
	this->SetLife(5.0); // Example values at the moment
	this->SetShield(3.0); 
	this->mWidth = 30.0;
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

/*
void BacteriaFattie::Draw(float deltaTime)
{
	Bacteria::Draw(deltaTime);
}

void BacteriaFattie::Update(float deltaTime)
{
	Bacteria::Update(deltaTime);
}
*/