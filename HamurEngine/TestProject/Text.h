#include "GUIElement.h"
#include "hamurOpenGL.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "hamurTextureManager.h"

class Text : public GUIElement
{
	public:
		Text(const string &name, const string &text);
		Text(const string &name, const string &text, const string &fontpath,
		   int fontsize, const HamurVec3 &position, HamurColorRGB c);
		virtual void Update(float deltaTime);
		virtual void Draw(float deltaTime);

	private:
		string mText;
		HamurVec3 mPosition;
		HamurColorRGB mColor;
		int mID;
		SDL_Surface* mSurface;
		TTF_Font* mFont;
};