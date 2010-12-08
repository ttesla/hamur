#include "GUIElement.h"
#include "hamur.h"

class Panel : public GUIElement
{
	public:
		Panel(const string &name);
		Panel(const string &name, const HamurVec3 &position,
				   const string &sprite,
				   const int width, const int height, 
				   HamurColor color = HamurColor::BLACK);
		virtual void Update(float deltaTime);
		virtual void Draw(float deltaTime);

	private:
		bool mPaintColor;
		HamurColor mColor;
};