#include "Text.h"

Text::Text(const string &name, const string &text):GUIElement(name)
{	
	SDL_Color c = {0, 0, 0};
	if(!(mFont = TTF_OpenFont("Fonts/DejaVuSans.ttf", 20))) 
	{
		cerr << "Error opening the font" << endl;
	}
	
	mSurface = TTF_RenderText_Blended(mFont, text.c_str(), c);

	mID = HAMURTEXMR->AddTexture(mSurface, mName);
}

Text::Text(const string &name, const string &text, const string &fontpath,
		   int fontsize, const HamurVec3 &position, HamurColorRGB color, int style):GUIElement(name)
{
	mPosition = position;
	mColor = color;
	
	SDL_Color c = {color.R, color.G, color.B};
	if(!(mFont = TTF_OpenFont(fontpath.c_str(), fontsize))) 
	{
		cerr << "Error opening the font" << endl;
	}
	
	switch (style)
	{
		case NORMAL:
			TTF_SetFontStyle(mFont, TTF_STYLE_NORMAL);
			break;
		case BOLD:
			TTF_SetFontStyle(mFont, TTF_STYLE_BOLD);
			break;
		case UNDERLINE:
			TTF_SetFontStyle(mFont, TTF_STYLE_UNDERLINE);
			break;
		case ITALIC:
			TTF_SetFontStyle(mFont, TTF_STYLE_ITALIC);
			break;
		case STRIKETHROUGH:
			TTF_SetFontStyle(mFont, TTF_STYLE_STRIKETHROUGH);
			break;
		default:
			break;
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

Text::~Text()
{
	SDL_FreeSurface(mSurface);
	TTF_CloseFont(mFont);
}

void Text::SetText( const string &text )
{
	SDL_Color c = {mColor.R, mColor.G, mColor.B};
	mSurface = TTF_RenderText_Blended(mFont, text.c_str(), c);
	HAMURTEXMR->DeleteTexture(mID);
	mID = HAMURTEXMR->AddTexture(mSurface, mName);
}

void Text::DeleteText()
{
	HAMURTEXMR->DeleteTexture(mID);
}