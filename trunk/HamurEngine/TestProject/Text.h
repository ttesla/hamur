#include "GUIElement.h"
#include "hamurOpenGL.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "hamurTextureManager.h"

#define NORMAL 0
#define BOLD 1
#define UNDERLINE 2
#define ITALIC 3
#define STRIKETHROUGH 4

class Text : public GUIElement
{
	public:
		Text(const string &name, const string &text);
		Text(const string &name, const string &text, const string &fontpath,
		   int fontsize, const HamurVec3 &position, HamurColorRGB c, int style = 0);
		virtual ~Text();
		virtual void Update(float deltaTime);
		virtual void Draw(float deltaTime);
		
		void SetText(const string &text);
		void DeleteText();
	private:
		string mText;
		HamurVec3 mPosition;
		HamurColorRGB mColor;
		int mID;
		SDL_Surface* mSurface;
		TTF_Font* mFont;
};