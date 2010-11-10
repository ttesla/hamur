#include "Panel.h"

Panel::Panel(const string &name):GUIElement(name)
{

}

Panel::Panel(const string &name, const HamurVec3 &position, const string &sprite, 
			   const int width, const int height,
			   HamurColor c): GUIElement(name, position, sprite, width, height)
{
	if (sprite == "") mPaintColor = true;
	else mPaintColor = false;
	mColor = c;
}

void Panel::Update(float deltaTime)
{
	
}

void Panel::Draw(float deltaTime)
{
	if (mPaintColor)
	{
		HamurPlotter::DrawSolidRectangle(this->mPos, this->mWidth, this->mHeight, mColor);
	}
	else
	{
		HamurObject::Draw(deltaTime);
	}
}