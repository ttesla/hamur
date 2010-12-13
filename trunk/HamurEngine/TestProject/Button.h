#include "GUIElement.h"

class Button : public GUIElement
{
	public:
		Button(const string &name);
		Button(const string &name, const HamurVec3 &position,
				   const string &sprite, 
				   const int width, const int height);
		virtual void Update(float deltaTime);
		//virtual void Draw(float deltaTime);
		bool isPushed();
		bool isSelected(){return mSelected;}
		void SetSelected(bool sel) {mSelected = sel;}
		void SetHover(bool hover) {mHover = hover;}

	private:
		bool mSelected; // Only for selection buttons
		bool mHover;
		
};