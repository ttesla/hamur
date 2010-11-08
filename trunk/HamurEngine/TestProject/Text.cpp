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
		   int fontsize, const HamurVec3 &position, HamurColorRGB color):GUIElement(name)
{
	mPosition = position;
	mColor = color;
	
	SDL_Color c = {color.R, color.G, color.B};
	if(!(mFont = TTF_OpenFont(fontpath.c_str(), fontsize))) 
	{
		cerr << "Error opening the font" << endl;
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

void Text::SetBold()
{
	TTF_SetFontStyle(mFont, TTF_STYLE_UNDERLINE);
}

/** Control text lines **

char* wrapText(NFont& font, const char* Text, unsigned int width) 
{ 
    if (Text == NULL) 
        return NULL; 
     
    string result, text, line, word; 
     
    line = ""; 
    result = ""; 
    text = Text; 
     
    while(text.size() > 0) 
    { 
        int nextSpace = text.find(' '); 
        if(nextSpace == string::npos) 
        { 
            nextSpace = text.size(); 
            word = text.substr(0, nextSpace); 
            text = ""; 
        } 
        else 
        { 
            word = text.substr(0, nextSpace+1); 
            text.erase(0, nextSpace + 1); 
        } 
        string temp = word + line; 


        if(font.getWidth(temp.c_str()) <= width) 
        { 
            line += word; 
        } 
        else 
        { 
            line += '\n'; 
            result += line; 
            line = word; 
        } 
         
    } 
    result += line; 
     
    return copyString(result); 
}

**/
