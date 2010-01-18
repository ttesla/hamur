#include "hamurTex.h"
#include "hamurGL.h"

namespace hamur
{
	HamurTex::HamurTex(const string &_filePath) 
	: filePath(_filePath), TEXTURE_RATIO(RATIO)
	{
		if(!loadTexture()) exit(1);
	}


	HamurTex::HamurTex(const SDL_Surface *newSurface) : TEXTURE_RATIO(RATIO)
	{
		if(!loadTexture(newSurface)) exit(1);
	}


	HamurTex::~HamurTex()
	{
	}


	// Loads texture from "Image file" and registers it to openGL's texture array. 
	bool HamurTex::loadTexture()
	{
		SDL_Surface *loadedImage = 0;
		int mode; // Texture mode RGB, RGBA 

		//loadedImage = SDL_LoadBMP(fileName.c_str()); //Load BMP Image
		loadedImage = IMG_Load(filePath.c_str()); // Load BMP, PNG or JPG

		if(loadedImage == 0)
		{
			HAMURLOG->write_log("Can't load texture: " + filePath);
			return false;
		}
		
		// RAGNORA SOR!

		// Work out what format to tell glTexImage2D to use...
        if(loadedImage->format->BytesPerPixel == 3) // RGB 24bit
                mode = GL_RGB;

        else if(loadedImage->format->BytesPerPixel == 4)// RGBA 32bit
                mode = GL_RGBA;

		// Create & bind the texture 
		glGenTextures(1, &textureID[0]);
		glBindTexture(GL_TEXTURE_2D, textureID[0]);

		// Set current image properties
		textureWidth  = loadedImage->w;
		textureHeight = loadedImage->h;
		scaledWidth   = textureWidth  / (float)HAMURGL->getScreenWidth(); 
		scaledHeight  = textureHeight / (float)HAMURGL->getScreenWidth(); 

		// Generate texture with LINEAR filtering
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// MAG filter
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);// MIN filter
		glTexImage2D(GL_TEXTURE_2D, 0, 4, textureWidth, textureHeight, 0, mode, GL_UNSIGNED_BYTE, loadedImage->pixels);

		// Generate texture with MIPMAP
		//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);				   // MAG filter
		//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); // MIN filter
		//gluBuild2DMipmaps(GL_TEXTURE_2D, 4, textureWidth, textureHeight, mode, GL_UNSIGNED_BYTE, loadedImage->pixels);

		// Free SDL_surfaces
		SDL_FreeSurface(loadedImage);

		HAMURLOG->write_log("Texture loaded: " + filePath);
		return true;
	}


	// Loads texture from "SDL surface" and registers it to openGL's texture array. 
	bool HamurTex::loadTexture(const SDL_Surface *newSurface)
	{
		int mode; // Texture mode RGB, RGBA 

		if(newSurface == 0)
		{
			HAMURLOG->write_log("Can't load texture from surface.");
			return false;
		}

		// Work out what format to tell glTexImage2D to use...
        if(newSurface->format->BytesPerPixel == 3) // RGB 24bit
                mode = GL_RGB;

        else if(newSurface->format->BytesPerPixel == 4)// RGBA 32bit
                mode = GL_RGBA;

		// Create & bind the texture 
		glGenTextures(1, &textureID[0]);
		glBindTexture(GL_TEXTURE_2D, textureID[0]);

		// Set current image properties
		textureWidth  = newSurface->w;
		textureHeight = newSurface->h;
		scaledWidth   = textureWidth  / (float)HAMURGL->getScreenWidth(); 
		scaledHeight  = textureHeight / (float)HAMURGL->getScreenWidth(); 

		// Generate texture with LINEAR filtering
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// MAG filter
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);// MIN filter
		glTexImage2D(GL_TEXTURE_2D, 0, 4, textureWidth, textureHeight, 0, mode, GL_UNSIGNED_BYTE, newSurface->pixels);

		// Generate texture with MIPMAP
		//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);				   // MAG filter
		//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); // MIN filter
		//gluBuild2DMipmaps(GL_TEXTURE_2D, 4, textureWidth, textureHeight, mode, GL_UNSIGNED_BYTE, newSurface->pixels);

		return true;
	}


	// GETTERS & SETTERS 
	int HamurTex::getGLtextureID()		{ return textureID[0];	}
	float HamurTex::getScaledWidth()	{ return scaledWidth;	}
	float HamurTex::getScaledHeight()	{ return scaledHeight;	}
	string HamurTex::getFilePath()		{ return filePath;	}
	float HamurTex::getCorX() { return corX; }
	float HamurTex::getCorY() { return corY; }
	float HamurTex::getCorZ() { return corZ; }

	void HamurTex::setCorX(float x) { corX = x; }
	void HamurTex::setCorY(float y) { corY = y; }
	void HamurTex::setCorZ(float z) { corZ = z; }
	void HamurTex::setScaledWidth(float sw)  { scaledWidth  = sw; }
	void HamurTex::setScaledHeight(float sh) { scaledHeight = sh; }
	void HamurTex::setAllCoord(float x, float y, float z)
	{
		corX = x;
		corY = y;
		corZ = z;
	}
}