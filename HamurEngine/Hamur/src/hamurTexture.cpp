#include "hamurTexture.h"
#include "hamurOpenGL.h"

#include "helper/hamurLog.h"
#include "hamurDefinitions.h"


namespace hamur
{

HamurTexture::HamurTexture(const string& filePath) 
    : mFilePath(filePath), mHasColorKey(false), mScale(1.0f,1.0f), mRotation(0.0f), mAlpha(1.0f)
{
	if(!LoadTextureFromFile()) exit(1);
}


HamurTexture::HamurTexture(const string& filePath, Uint8 red, Uint8 green, Uint8 blue) 
    : mFilePath(filePath), mHasColorKey(true), mScale(1.0f,1.0f), mRotation(0.0f), mAlpha(1.0f)
{
    mRedKey   = red;
    mGreenKey = green;
    mBlueKey  = blue;

    if(!LoadTextureFromFile()) exit(1);
}


HamurTexture::HamurTexture(SDL_Surface* newSurface) 
    : mHasColorKey(false), mScale(1.0f,1.0f), mRotation(0.0f), mAlpha(1.0f)
{
	if(!LoadTextureFromSurface(newSurface)) exit(1);
}


HamurTexture::HamurTexture(SDL_Surface* newSurface, Uint8 red, Uint8 green, Uint8 blue) 
    : mHasColorKey(true), mScale(1.0f,1.0f), mRotation(0.0f), mAlpha(1.0f)
{
    mRedKey   = red;
    mGreenKey = green;
    mBlueKey  = blue;

    if(!LoadTextureFromSurface(newSurface)) exit(1);
}


HamurTexture::~HamurTexture()
{
    HAMURLOG->WriteLogln("Texture deleted: " + mFilePath);
}


// Loads texture from "Image file" and registers it to openGL's texture array. 
bool HamurTexture::LoadTextureFromFile()
{
    SDL_Surface* tempSurface = NULL;
	SDL_Surface* finalSurface = NULL;

    // Load image from disk
	tempSurface = IMG_Load(mFilePath.c_str());

	if(tempSurface == NULL)
	{
        HAMURLOG->WriteLogln("Error!: Can't load texture: " + mFilePath, HamurLog::ALWAYS);
		return false;
	}
	
    // Add alpha channel with colorkey (if has colorkey)
    // colorkey pixels are full transparent (Alpha = 0)
    if(mHasColorKey)
    {
        Uint32 colorkey = SDL_MapRGB(tempSurface->format, mRedKey, mGreenKey, mBlueKey);
        SDL_SetColorKey(tempSurface, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey);
    }
    
    tempSurface = SDL_DisplayFormatAlpha(tempSurface);
    SDL_SetAlpha(tempSurface, 0, 0 );
    finalSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, tempSurface->w, tempSurface->h, 32, mRedMask, mGreenMask, mBlueMask, mAlphaMask);
    SDL_BlitSurface(tempSurface, NULL, finalSurface, NULL);

    // Determine texture format
    if (finalSurface->format->BytesPerPixel != 4) // RGBA 32bit (it should be always this)
    {
        HAMURLOG->WriteLogln("Error!: Can't set 32bit texture format (use PNG images only): " + mFilePath, HamurLog::ALWAYS);
        SDL_FreeSurface(tempSurface);
        SDL_FreeSurface(finalSurface);
        return false;
    }

    // Generate texture
	GenerateTexture(finalSurface);

	// Free SDL_surfaces
	SDL_FreeSurface(tempSurface);
    SDL_FreeSurface(finalSurface);
    HAMURLOG->WriteLogln("Texture loaded: " + mFilePath);

	return true;
}


// Loads texture from "SDL surface" and registers it to openGL's texture array. 
bool HamurTexture::LoadTextureFromSurface(SDL_Surface* surface)
{
    SDL_Surface* finalSurface = NULL;

	if(surface == NULL)
	{
        HAMURLOG->WriteLogln("Error!: Can't load texture from surface.", HamurLog::ALWAYS);
		return false;
	}

    // Add alpha channel with colorkey (if has colorkey)
    // colorkey pixels are full transparent (Alpha = 0)
    if(mHasColorKey)
    {
        Uint32 colorkey = SDL_MapRGB(surface->format, mRedKey, mGreenKey, mBlueKey);
        SDL_SetColorKey(surface, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey);
    }

    surface = SDL_DisplayFormatAlpha(surface);
    SDL_SetAlpha(surface, 0, 0 );
    finalSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, surface->w, surface->h, 32, mRedMask, mGreenMask, mBlueMask, mAlphaMask);
    SDL_BlitSurface(surface, NULL, finalSurface, NULL);

    // Check texture format
    if (finalSurface->format->BytesPerPixel != 4) // RGBA 32bit (it should be always this!)
    {
        HAMURLOG->WriteLogln("Error!: Can't set 32bit texture format of given surface.", HamurLog::ALWAYS);
        SDL_FreeSurface(finalSurface);
        return false;
    }

    // Generate texture
    GenerateTexture(finalSurface);

    // Free SDL Surfaces
    SDL_FreeSurface(finalSurface);

	return true;
}


// Generate opengl texture from given surface
void HamurTexture::GenerateTexture(const SDL_Surface* surface)
{
    // Create & bind the texture 
    glGenTextures(1, &mTextureID[0]);
    glBindTexture(GL_TEXTURE_2D, mTextureID[0]);

    // Set current image properties
    mPixelWidth  = surface->w;
    mPixelHeight = surface->h;
    mOpenglWidth   = (mPixelWidth  / (float)HAMURGL->GetScreenWidth()) * 0.8f; // 0.8 is magic number for perfect ratio
    mOpenglHeight  = (mPixelHeight / (float)HAMURGL->GetScreenWidth()) * 0.8f; 

    // Generate texture with LINEAR filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// MAG filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);// MIN filter
    glTexImage2D(GL_TEXTURE_2D, 0, 4, mPixelWidth, mPixelHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);

    // Generate texture with MIPMAP
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);				   // MAG filter
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); // MIN filter
    //gluBuild2DMipmaps(GL_TEXTURE_2D, 4, textureWidth, textureHeight, GL_RGBA, GL_UNSIGNED_BYTE, loadedImage->pixels);
}


} // namespace hamur
