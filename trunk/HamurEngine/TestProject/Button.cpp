#include "Button.h"

Button::Button(const string &name):GUIElement(name)
{

}

Button::Button(const string &name, const HamurVec3 &position, const string &sprite, 
			   const int width, const int height): GUIElement(name, position, sprite, width, height)
{

}

void Button::Update(float deltaTime)
{
	HamurVec3 mousePos;
	mousePos.x = HAMUREVENT->GetMouseX();
	mousePos.y = HAMUREVENT->GetMouseY();
	float halfW = mWidth/2;
	float halfH = mHeight/2;
	
	// On mouse over animation
	if((mousePos.x > this->GetPosition().x - halfW) && (mousePos.x < this->GetPosition().x + halfW)
			&& (mousePos.y > this->GetPosition().y - halfH) && (mousePos.y < this->GetPosition().y + halfH))
	{
		this->ScaleSprite(1.2, 1.2);
	}
	else
	{
		this->ScaleSprite(1, 1);
	}
}

bool Button::isPushed()
{
	HamurVec3 mousePos;
	mousePos.x = HAMUREVENT->GetMouseX();
	mousePos.y = HAMUREVENT->GetMouseY();

	float halfW = mWidth/2;
	float halfH = mHeight/2;

	if(HAMUREVENT->IsMousePressed(Keys::LeftButton))
	{
		if((mousePos.x > this->GetPosition().x - halfW) && (mousePos.x < this->GetPosition().x + halfW)
			&& (mousePos.y > this->GetPosition().y - halfH) && (mousePos.y < this->GetPosition().y + halfH))
		{
			return true;
		}
	}
	return false;
}