#include "GUIElement.h"

GUIElement::GUIElement(const string &name) : HamurObject(name){}

GUIElement::GUIElement(const string &name, const HamurVec3 &position,
		   const string &sprite, 
		   const int width, const int height) : HamurObject(name, sprite)
{
	this->SetPosition(position);
	this->SetWidth(width);
	this->SetHeight(height);
}

void GUIElement::Update(float deltaTime)
{
}

