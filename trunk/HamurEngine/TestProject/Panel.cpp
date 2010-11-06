#include "Panel.h"

Panel::Panel(const string &name):GUIElement(name)
{
}

Panel::Panel(const string &name, const HamurVec3 &position, const string &sprite, 
			   const int width, const int height): GUIElement(name, position, sprite, width, height)
{
}

void Panel::Update(float deltaTime)
{
}