#include "hamurFont.h"



namespace hamur
{
	//// HamurFont constructor
	//HamurFont::HamurFont()
	//{
	//	SDL_Surface *charSurface;
	//	SDL_Surface *fontSurface;
	//	SDL_Rect charRect;
	//	charRect.w = 16;
	//	charRect.h = 16;

	//	// Prepare surfaces
	//	charSurface = SDL_CreateRGBSurface(SDL_HWSURFACE, 16, 16, 24, 0, 0, 0, 0);
	//	fontSurface = IMG_Load("data/font.png");

	//	// Error check
	//	if(fontSurface == 0)
	//	{
	//		HAMURLOG->write_log("Can't load font file 'font.png'");
	//		exit(1);
	//	}

	//	// Prepare font
	//	string fontList[128];

	//	for(int i = 32; i < 127; i++)
	//		fontList[i - 32].push_back((char)i);
	//	
	//	for(int i = 95; i < 128; i++)
	//		fontList[i] = " ";

	//	// Generate font textures
	//	for(int y = 0; y < 8; y++)
	//	{
	//		for(int x = 0; x < 16; x++)
	//		{
	//			charRect.x = x*16;
	//			charRect.y = y*16;
	//			SDL_BlitSurface(fontSurface, &charRect, charSurface, 0);
	//			//cout << "List:" << fontList[x + y * 16] << ":" << x + y*16 << endl;
	//			HAMURTEXMR->addTexture(charSurface, fontList[x + y * 16]);
	//		}
	//	}

	//	// Free surfaces
	//	SDL_FreeSurface(charSurface);
	//	SDL_FreeSurface(fontSurface);

	//	HAMURLOG->writeInitLog("HamurFont");
	//}

 //   // HamurFont destructor
 //   HamurFont::~HamurFont()
 //   {

 //   }


	//// Draw given text to screen
	//void HamurFont::drawText(const string &text, float x, float y, float z)
	//{
	//	for(unsigned int i = 0; i < text.length(); i++)
	//	{
	//		string tempStr;
	//		tempStr.push_back(text.at(i));
	//		HAMURTEXMR->blitTexture(tempStr, x + i*0.015f, y, z);
	//	}
	//}

    /*
    // Draw an integer 
    void HamurFont::drawText(int number, float x, float y, float z)
    {
        stringstream tempstring;
        string text;

        tempstring << number;

        text = tempstring.str();

        for(unsigned int i = 0; i < text.length(); i++)
        {
            string tempStr;
            tempStr.push_back(text.at(i));
            HAMURTEXMR->blitTexture(tempStr, x + i*0.015f, y, z);
        }   
    }

    // Draw a float 
    void HamurFont::drawText(float number, float x, float y, float z)
    {
        stringstream tempstring;
        string text;

        tempstring << number;

        text = tempstring.str();

        for(unsigned int i = 0; i < text.length(); i++)
        {
            string tempStr;
            tempStr.push_back(text.at(i));
            HAMURTEXMR->blitTexture(tempStr, x + i*0.015f, y, z);
        }   
    }

    // Draw a double 
    void HamurFont::drawText(double number, float x, float y, float z)
    {
        stringstream tempstring;
        string text;

        tempstring << number;

        text = tempstring.str();

        for(unsigned int i = 0; i < text.length(); i++)
        {
            string tempStr;
            tempStr.push_back(text.at(i));
            HAMURTEXMR->blitTexture(tempStr, x + i*0.015f, y, z);
        }   
    }

    // Draw a Hamur String 
    void HamurFont::drawText(HamurString _stream, float x, float y, float z)
    {
 
        string text = _stream.getString();

        for(unsigned int i = 0; i < text.length(); i++)
        {
            string tempStr;
            tempStr.push_back(text.at(i));
            HAMURTEXMR->blitTexture(tempStr, x + i*0.015f, y, z);
        }   
    }
    */
}