#include "GUIElement.h"

class Panel : public GUIElement
{
	public:
		Panel(const string &name);
		Panel(const string &name, const HamurVec3 &position,
				   const string &sprite, 
				   const int width, const int height);
		virtual void Update(float deltaTime);
		//virtual void Draw(float deltaTime);

	private:
		// Temporal
		HamurColor c;
};