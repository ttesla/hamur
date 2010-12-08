#include "Tooth.h"
#include <iostream>
using namespace std;

list<Tooth *> *Tooth::teeth = NULL;

Tooth::Tooth(const string &name):HamurObject(name)
{
    mWidth = 20;
    mHeight = 30;

	mPos.x = 0;
	mPos.y = 0;
	mPos.z = 0;

    //setPhysics();

	mLife = 1000;
	mShield = 1000;
}



Tooth::~Tooth()
{
	teeth->clear();
}

void Tooth::SetPosition(float x, float y)
{
	mPos.x = x;
	mPos.y = y;
}

void Tooth::Draw(float deltaTime)
{
	//HamurPlotter::DrawSolidRectangle(mPos, mWidth, mHeight, HamurColor(mLife / 1000, mLife / 1000, mLife / 1000));
	//HamurPlotter::DrawRectangle(mPos, mWidth, mHeight, HamurColor(0, 0, mShield / 1000));
}

void Tooth::Update(float deltaTime)
{
}