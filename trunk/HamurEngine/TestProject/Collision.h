#pragma once

#include "hamur.h"
#include "SDL.h"

class Collision
{
public:
	static bool RectsIntersectWith(hamur::HamurObject *obj1, hamur::HamurObject *obj2)
	{

		SDL_Rect rect1;
		rect1.x = obj1->GetPosition().x;// - obj1->GetWidth() / 2; 
		rect1.y = obj1->GetPosition().y;// - obj1->GetHeight() / 2;
		rect1.w = obj1->GetWidth();
		rect1.h = obj1->GetHeight();

		SDL_Rect rect2;
		rect2.x = obj2->GetPosition().x;// - obj2->GetWidth() / 2;
		rect2.y = obj2->GetPosition().y;// - obj2->GetHeight() / 2;
		rect2.w = obj2->GetWidth();
		rect2.h = obj2->GetHeight();

		return !(rect1.y + rect1.h < rect2.y || rect1.y > rect2.y + rect2.h || 
			rect1.x + rect1.w < rect2.x ||
			rect1.x > rect2.x + rect2.w);
	}
};