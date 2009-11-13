#include "hamurTexMR.h"

namespace hamur
{
	HamurTexMR::HamurTexMR()
	{
		HAMURLOG->write_init_log("HamurTexture");
	}


	// Deletes all textures in the map container
	HamurTexMR::~HamurTexMR()
	{
		map<string, HamurTex*>::iterator iter;

		for(iter = textureMap.begin(); iter != textureMap.end(); iter++)
		{
			if(iter->second)
				delete iter->second;
		}
	}


	// Get texture from "map" container according to given texture name
	HamurTex* HamurTexMR::getTexture(const string& strTextName)
	{
		//Look in the map if the texture is already loaded.
		map<string, HamurTex*>::iterator iter = textureMap.find(strTextName);
		
		if(iter != textureMap.end())
			return iter->second;

		else
			return 0; // Return NULL, texture not found.
	}


	// Add texture into "map" container with texture name index from image file.
	// If the texture is already loaded, it doesn't add another copy
	void HamurTexMR::addTexture(const string& strFileName, const string& strTextName)
	{
		// Look in the map if the texture is already loaded.
		map<string, HamurTex*>::iterator iter = textureMap.find(strTextName);
		
		// If not found, then add
		if(iter == textureMap.end())
		{
			HamurTex *newTex = new HamurTex(strFileName, strTextName);
			textureMap[strTextName] = newTex;
		}
	}


	// Add texture into "map" container with texture name index from SDL surface.
	// If the texture is already loaded, it doesn't add another copy
	void HamurTexMR::addTexture(const SDL_Surface *newSurface, const string& strTextName)
	{
		// Look in the map if the texture is already loaded.
		map<string, HamurTex*>::iterator iter = textureMap.find(strTextName);
		
		// If not found, then add
		if(iter == textureMap.end())
		{
			HamurTex *newTex = new HamurTex(newSurface, strTextName);
			textureMap[strTextName] = newTex;
		}
	}


	// Deletes texture according to given texture name. 
	bool HamurTexMR::deleteTexture(const string& strTextName)
	{
		// Get texture from the map
		bool bFound = false;
		map<string, HamurTex*>::iterator iter = textureMap.find(strTextName);

		if(iter != textureMap.end())
		{
			// If it was found, delete it then
			bFound = true;

			if(iter->second)
				delete iter->second;
			
			textureMap.erase(iter);
		}

		return bFound;
	}


	// Blits image onto screen
	void HamurTexMR::blitTexture(const string &textureName, float x, float y, float z)
	{
		HamurTex *texture = getTexture(textureName);

		if(texture == 0)
		{
			HAMURLOG->write_log("Can't find texture: " + textureName);
			exit(1);
		}

		texture->setAllCoord(x, y, z); // Update texture coordinates
		glBindTexture(GL_TEXTURE_2D, texture->getTextureID()); // Bind texture

		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y, z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + texture->getScaledWidth(), y, z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x + texture->getScaledWidth(), y + texture->getScaledHeight(), z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + texture->getScaledHeight(), z); 
		glEnd();
	}


	// Blits image onto screen - without coordinates
	void HamurTexMR::blitTexture(const string &textureName)
	{
		HamurTex *texture = getTexture(textureName);

		if(texture == 0)
		{
			HAMURLOG->write_log("Can't find texture: " + textureName);
			exit(1);
		}

		// Get current texture coordinates...
		float x = texture->getCorX();
		float y = texture->getCorY();
		float z = texture->getCorZ();

		glBindTexture(GL_TEXTURE_2D, texture->getTextureID()); // Bind texture

		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y, z);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + texture->getScaledWidth(), y, z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x + texture->getScaledWidth(), y + texture->getScaledHeight(), z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + texture->getScaledHeight(), z); 
		glEnd();
	}
}
