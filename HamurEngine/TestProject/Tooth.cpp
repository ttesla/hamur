#include "Tooth.h"
#include <iostream>
using namespace std;

Tooth::Tooth(const string &name):HamurObject(name)
{
    mWidth = 20;
    mHeight = 30;

	mPos.x = 0;
	mPos.y = 0;
	mPos.z = 0;

    //setPhysics();
}

void Tooth::SetPosition(float x, float y)
{
	mPos.x = x;
	mPos.y = y;
}

void Tooth::Draw(float deltaTime)
{
	HamurPlotter::DrawSolidRectangle(mPos, mWidth, mHeight, HamurColor::WHITE);
}

void Tooth::Update(float deltaTime)
{

}