#include "hamurTex.h"
#include "hamurGL.h"

#include "helper/hamurLog.h"
#include "hamurDefinitions.h"


namespace hamur
{

HamurTex::HamurTex(const string& filePath) : mFilePath(filePath)
{
	if(!LoadTexture()) exit(1);
}


HamurTex::HamurTex(const SDL_Surface* newSurface)
{
	if(!LoadTexture(newSurface)) exit(1);
}


HamurTex::~HamurTex()
{
    HAMURLOG->writeLogln("Texture deleted: " + mFilePath);
}


// Loads texture from "Image file" and registers it to openGL's texture array. 
bool HamurTex::LoadTexture()
{
	SDL_Surface *loadedImage = 0;
	int mode; // Texture mode RGB, RGBA 

	//loadedImage = SDL_LoadBMP(fileName.c_str()); //Load BMP Image
	loadedImage = IMG_Load(mFilePath.c_str()); // Load BMP, PNG or JPG

	if(loadedImage == 0)
	{
        HAMURLOG->writeLogln("Error!: Can't load texture: " + mFilePath, HamurLog::ALWAYS);
		return false;
	}
	
	// RAGNORA SOR!

	// Work out what format to tell glTexImage2D to use...
    if(loadedImage->format->BytesPerPixel == 3) // RGB 24bit
            mode = GL_RGB;

    else if(loadedImage->format->BytesPerPixel == 4)// RGBA 32bit
            mode = GL_RGBA;

	// Create & bind the texture 
	glGenTextures(1, &mTextureID[0]);
	glBindTexture(GL_TEXTURE_2D, mTextureID[0]);

	// Set current image properties
	mTextureWidth  = loadedImage->w;
	mTextureHeight = loadedImage->h;
	mScaledWidth   = mTextureWidth  / (float)HAMURGL->getScreenWidth(); 
	mScaledHeight  = mTextureHeight / (float)HAMURGL->getScreenWidth(); 

	// Generate texture with LINEAR filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// MAG filter
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);// MIN filter
	glTexImage2D(GL_TEXTURE_2D, 0, 4, mTextureWidth, mTextureHeight, 0, mode, GL_UNSIGNED_BYTE, loadedImage->pixels);

	// Generate texture with MIPMAP
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);				   // MAG filter
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); // MIN filter
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 4, textureWidth, textureHeight, mode, GL_UNSIGNED_BYTE, loadedImage->pixels);

	// Free SDL_surfaces
	SDL_FreeSurface(loadedImage);
    HAMURLOG->writeLogln("Texture loaded: " + mFilePath);

	return true;
}


// Loads texture from "SDL surface" and registers it to openGL's texture array. 
bool HamurTex::LoadTexture(const SDL_Surface* newSurface)
{
	int mode; // Texture mode RGB, RGBA 

	if(newSurface == 0)
	{
        HAMURLOG->writeLogln("Error!: Can't load texture from surface.", HamurLog::ALWAYS);
		return false;
	}

	// Work out what format to tell glTexImage2D to use...
    if(newSurface->format->BytesPerPixel == 3) // RGB 24bit
            mode = GL_RGB;

    else if(newSurface->format->BytesPerPixel == 4)// RGBA 32bit
            mode = GL_RGBA;

	// Create & bind the texture 
	glGenTextures(1, &mTextureID[0]);
	glBindTexture(GL_TEXTURE_2D, mTextureID[0]);

	// Set current image properties
	mTextureWidth  = newSurface->w;
	mTextureHeight = newSurface->h;
	mScaledWidth   = mTextureWidth  / (float)HAMURGL->getScreenWidth(); 
	mScaledHeight  = mTextureHeight / (float)HAMURGL->getScreenWidth(); // this should be Width!!

	// Generate texture with LINEAR filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// MAG filter
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);// MIN filter
	glTexImage2D(GL_TEXTURE_2D, 0, 4, mTextureWidth, mTextureHeight, 0, mode, GL_UNSIGNED_BYTE, newSurface->pixels);

	// Generate texture with MIPMAP
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);				   // MAG filter
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); // MIN filter
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 4, textureWidth, textureHeight, mode, GL_UNSIGNED_BYTE, newSurface->pixels);

	return true;
}


// GETTERS & SETTERS 
int HamurTex::GetGLtextureID() const	    { return mTextureID[0];	}
int HamurTex::GetWidth() const              { return mTextureWidth;  }
int HamurTex::GetHeight() const             { return mTextureHeight; }
float HamurTex::GetScaledWidth() const      { return mScaledWidth;	}
float HamurTex::GetScaledHeight() const     { return mScaledHeight;	}
string HamurTex::GetFilePath() const        { return mFilePath;	}
float HamurTex::GetCorX() const { return mCorX; }
float HamurTex::GetCorY() const { return mCorY; }
float HamurTex::GetCorZ() const { return mCorZ; }

void HamurTex::SetCorX(float x) { mCorX = x; }
void HamurTex::SetCorY(float y) { mCorY = y; }
void HamurTex::setCorZ(float z) { mCorZ = z; }
void HamurTex::SetScaledWidth(float sw)  { mScaledWidth  = sw; }
void HamurTex::SetScaledHeight(float sh) { mScaledHeight = sh; }
void HamurTex::SetAllCoord(float x, float y, float z)
{
	mCorX = x;
	mCorY = y;
	mCorZ = z;
}

}// namespace hamur
