#include "Button.h"

Button::Button(const string &name):GUIElement(name)
{
	//Temporal
	c = HamurColor::CYAN;
}

Button::Button(const string &name, const HamurVec3 &position, const string &sprite, 
			   const int width, const int height): GUIElement(name, position, sprite, width, height)
{

}

void Button::Update(float deltaTime)
{
	//if(HAMUREVENT->IsMousePressed(Keys::Mouse::LeftButton))
	if(HAMUREVENT->IsMouseDown(Keys::LeftButton))
	{
		if(isPushed())
		{
			c = HamurColor::GREEN;
		}
		else
		{
			c = HamurColor::CYAN;
		}
	}
}

void Button::Draw(float deltaTime)
{
	HamurPlotter::DrawSolidRectangle(mPos, mWidth, mHeight, c);
}

bool Button::isPushed()
{
	HamurVec3 mousePos;
	mousePos.x = HAMUREVENT->GetMouseX();
	mousePos.y = HAMUREVENT->GetMouseY();

	if((mousePos.x > this->GetPosition().x) && (mousePos.x < this->GetPosition().x + this->mWidth)
		&& (mousePos.y > this->GetPosition().y) && (mousePos.y < this->GetPosition().y + this->mHeight))
	{
		return true;
	}
	return false;
}