#include "hamurTexture.h"
#include "hamurOpenGL.h"

#include "helper/hamurLog.h"
#include "hamurDefinitions.h"


namespace hamur
{

HamurTexture::HamurTexture(const string& filePath) : mFilePath(filePath), mHasColorKey(false)
{
	if(!LoadTextureFromFile()) exit(1);
}


HamurTexture::HamurTexture(const string& filePath, Uint8 red, Uint8 green, Uint8 blue) : mFilePath(filePath), mHasColorKey(true)
{
    mRedKey   = red;
    mGreenKey = green;
    mBlueKey  = blue;

    if(!LoadTextureFromFile()) exit(1);
}


HamurTexture::HamurTexture(SDL_Surface* newSurface) : mHasColorKey(false)
{
	if(!LoadTextureFromSurface(newSurface)) exit(1);
}

HamurTexture::HamurTexture(SDL_Surface* newSurface, Uint8 red, Uint8 green, Uint8 blue) : mHasColorKey(true)
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
	int mode = 0; // Texture mode RGB, RGBA, BGRA...ect

    // Load image from disk
	tempSurface = IMG_Load(mFilePath.c_str());

	if(tempSurface == NULL)
	{
        HAMURLOG->WriteLogln("Error!: Can't load texture: " + mFilePath, HamurLog::ALWAYS);
		return false;
	}

    //TODO: bitmap, tga, jpeg support & check will be added here
	
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
    if (finalSurface->format->BytesPerPixel == 4) // RGBA 32bit (it should be always this)
        mode = GL_RGBA; 
    else 
    {
        HAMURLOG->WriteLogln("Error!: Can't set 32bit texture format (use PNG images only): " + mFilePath, HamurLog::ALWAYS);
        SDL_FreeSurface(tempSurface);
        SDL_FreeSurface(finalSurface);
        return false;
    }

    // Generate texture
	GenerateTexture(finalSurface, mode);

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
	int mode = 0; // Texture mode RGB, RGBA 

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

    // Determine texture format
    if (finalSurface->format->BytesPerPixel == 4) // RGBA 32bit (it should be always this)
        mode = GL_RGBA; 
    else 
    {
        HAMURLOG->WriteLogln("Error!: Can't set 32bit texture format of given surface.", HamurLog::ALWAYS);
        SDL_FreeSurface(finalSurface);
        return false;
    }

    // Generate texture
    GenerateTexture(finalSurface, mode);

	return true;
}


// Generate opengl texture from given surface
void HamurTexture::GenerateTexture(const SDL_Surface* surface, int mode)
{
    // Create & bind the texture 
    glGenTextures(1, &mTextureID[0]);
    glBindTexture(GL_TEXTURE_2D, mTextureID[0]);

    // Set current image properties
    mTextureWidth  = surface->w;
    mTextureHeight = surface->h;
    mScaledWidth   = mTextureWidth  / (float)HAMURGL->GetScreenWidth(); 
    mScaledHeight  = mTextureHeight / (float)HAMURGL->GetScreenWidth(); 

    // Generate texture with LINEAR filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// MAG filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);// MIN filter
    glTexImage2D(GL_TEXTURE_2D, 0, 4, mTextureWidth, mTextureHeight, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

    // Generate texture with MIPMAP
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);				   // MAG filter
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); // MIN filter
    //gluBuild2DMipmaps(GL_TEXTURE_2D, 4, textureWidth, textureHeight, mode, GL_UNSIGNED_BYTE, loadedImage->pixels);
}


// GETTERS & SETTERS 
int HamurTexture::GetGLtextureID() const	    { return mTextureID[0];	}
int HamurTexture::GetWidth() const              { return mTextureWidth;  }
int HamurTexture::GetHeight() const             { return mTextureHeight; }
float HamurTexture::GetScaledWidth() const      { return mScaledWidth;	}
float HamurTexture::GetScaledHeight() const     { return mScaledHeight;	}
string HamurTexture::GetFilePath() const        { return mFilePath;	}
float HamurTexture::GetCorX() const { return mCorX; }
float HamurTexture::GetCorY() const { return mCorY; }
float HamurTexture::GetCorZ() const { return mCorZ; }

void HamurTexture::SetCorX(float x) { mCorX = x; }
void HamurTexture::SetCorY(float y) { mCorY = y; }
void HamurTexture::setCorZ(float z) { mCorZ = z; }
void HamurTexture::SetScaledWidth(float sw)  { mScaledWidth  = sw; }
void HamurTexture::SetScaledHeight(float sh) { mScaledHeight = sh; }
void HamurTexture::SetAllCoord(float x, float y, float z)
{
	mCorX = x;
	mCorY = y;
	mCorZ = z;
}


} // namespace hamur
