#pragma once

#include "hamur.h"
using namespace hamur;

class GUIElement : public HamurObject
{
	public:
		GUIElement(const string &name);
		GUIElement(const string &name, const HamurVec3 &position,
				   const string &sprite, 
				   const int width, const int height);
		virtual void Update(float deltaTime)=0;
		virtual void Draw(float deltaTime)=0;

	protected:

};