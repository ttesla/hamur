#include "Text.h"

Text::Text(const string &name, const string &text):GUIElement(name)
{	
	SDL_Color c = {0, 0, 0};
	if(!(mFont = TTF_OpenFont("Fonts/DejaVuSans.ttf", 20))) 
	{
		cout << "Error opening the font" << endl;
	}
	
	mSurface = TTF_RenderText_Blended(mFont, text.c_str(), c);

	mID = HAMURTEXMR->AddTexture(mSurface, mName);
}

Text::Text(const string &name, const string &text, const string &fontpath,
		   int fontsize, const HamurVec3 &position, HamurColorRGB color):GUIElement(name)
{
	mPosition = position;
	mColor = color;
	
	SDL_Color c = {color.R, color.G, color.B};
	if(!(mFont = TTF_OpenFont(fontpath.c_str(), fontsize))) 
	{
		cout << "Error opening the font" << endl;
	}
	
	mSurface = TTF_RenderText_Blended(mFont, text.c_str(), c);

	mID = HAMURTEXMR->AddTexture(mSurface, mName);
}


void Text::Update(float deltaTime)
{

}


void Text::Draw(float deltaTime)
{
	HAMURTEXMR->BlitTexture(mID, mPosition);
}