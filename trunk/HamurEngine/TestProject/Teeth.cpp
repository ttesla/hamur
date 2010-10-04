#include "Teeth.h"

using namespace hamur;

Teeth::Teeth(const string &name) : HamurObject(name)
{
	mWidth = 100;
	mHeight = 100;

	mPos = HamurVec3((HamurOpenGL::GetInstance()->GetScreenWidth() - mWidth) / 2, 
		(HamurOpenGL::GetInstance()->GetScreenHeight() - mHeight) / 2, 0);
}

void Teeth::Reset()
{
	health = 100;
	shield = 100;
}

void Teeth::Update( float deltaTime )
{

}

void Teeth::Draw( float deltaTime )
{
	HamurPlotter::DrawRectangle(mPos, 100, 100, HamurColor::GREEN);
}