#include "hamurTexMR.h"

namespace hamur
{
    HamurTexMR::HamurTexMR() : depthShift(1.0f), openglY(0.414f)
	{
        // Calculactions for world - openGL coordinate translations
        aspectRatio = (float)HAMURGL->getScreenWidth() / (float)HAMURGL->getScreenHeight();
        openglX = openglY * aspectRatio;
        pixRatioX = (float)HAMURGL->getScreenWidth()  / (openglX*2);
        pixRatioY = (float)HAMURGL->getScreenHeight() / (openglY*2);

		HAMURLOG->writeInitLog("HamurTexture");
	}


	// Deletes all textures in the map container
	HamurTexMR::~HamurTexMR()
	{
		map<unsigned int, HamurTex*>::iterator iter;

		for(iter = textureMap.begin(); iter != textureMap.end(); iter++)
		{
			if(iter->second)
				delete iter->second;
		}
	}


	// Get texture from "map" container according to given texture name
	HamurTex* HamurTexMR::getTexture(unsigned int textureID)
	{
		//Look in the map if the texture is already loaded.
		map<unsigned int, HamurTex*>::iterator iter = textureMap.find(textureID);

		if(iter != textureMap.end())
			return iter->second;

		else
			return 0; // Return NULL, texture not found.
	}


	// Add texture into "map" container with texture name index from image file.
	// If the texture is already loaded, it doesn't add another copy
	unsigned int HamurTexMR::addTexture(const string& filePath)
	{
        // Generate textureID according to hash function
        unsigned int textureID = HamurHash::hashFunction(filePath);

		// Look in the map if the texture is already loaded.
		map<unsigned int, HamurTex*>::iterator iter = textureMap.find(textureID);
		
		// If not found, then add
		if(iter == textureMap.end())
		{
			HamurTex *newTex = new HamurTex(filePath);
			textureMap[textureID] = newTex;
		}

        return textureID;
	}


	// Add texture into "map" container with texture name index from SDL surface.
	// If the texture is already loaded, it doesn't add another copy
	unsigned int HamurTexMR::addTexture(const SDL_Surface *newSurface, const string &strName)
	{
        // Generate textureID according to hash function
        unsigned int textureID = HamurHash::hashFunction(strName);

		// Look in the map if the texture is already loaded.
		map<unsigned int, HamurTex*>::iterator iter = textureMap.find(textureID);
		
		// If not found, then add
		if(iter == textureMap.end())
		{
			HamurTex *newTex = new HamurTex(newSurface);
			textureMap[textureID] = newTex;
		}

        return textureID;
	}


	// Deletes texture according to given texture name. 
	bool HamurTexMR::deleteTexture(unsigned int textureID)
	{
		// Get texture from the map
		bool bFound = false;
		map<unsigned int, HamurTex*>::iterator iter = textureMap.find(textureID);

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
	void HamurTexMR::blitTexture(unsigned int textureID, const HamurVec3 &position, float rotation)
	{
		HamurTex *texture = getTexture(textureID);

		if(texture == 0)
		{
            HAMURLOG->writeLog("Error!: Can't find texture: ");
            HAMURLOG->writeLogln(textureID);
			exit(1);
		}

        // Translate coordinates from World to openGL coordinates.
        HamurVec3 openglPos = worldToGL(position);
    
		texture->setAllCoord(openglPos.x, openglPos.x, openglPos.x); // Update texture coordinates
		glBindTexture(GL_TEXTURE_2D, texture->getGLtextureID()); // Bind texture

        // Save current matrix. 
        // Perform translation to texture's middle and rotate from middle around Z axis.
        // Translate back and blit the texture.
        // Restore matrix.
        glPushMatrix();
        
        glTranslatef(openglPos.x + texture->getScaledWidth()/2, 
            openglPos.y - texture->getScaledHeight()/2, openglPos.z - 1.0f);
        glRotatef(rotation, 0, 0, 1.0f); 
        glTranslatef(-texture->getScaledWidth()/2, texture->getScaledHeight()/2, 0);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(texture->getScaledWidth(), 0, 0);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(texture->getScaledWidth(), -texture->getScaledHeight(), 0);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(0, -texture->getScaledHeight(), 0); 
        glEnd();

        glPopMatrix();
	}


    // Blits image onto screen
    void HamurTexMR::blitTexture(unsigned int textureID, float x, float y, float z, float rotation)
    {
        HamurTex *texture = getTexture(textureID);

        if(texture == 0)
        {
            HAMURLOG->writeLog("Error!: Can't find texture: ");
            HAMURLOG->writeLogln(textureID);
            exit(1);
        }

        // Translate coordinates from World to openGL coordinates.
        HamurVec3 openglPos = worldToGL(x, y, z);

        texture->setAllCoord(openglPos.x, openglPos.x, openglPos.x); // Update texture coordinates
        glBindTexture(GL_TEXTURE_2D, texture->getGLtextureID()); // Bind texture

        // Save current matrix. 
        // Perform translation to texture's middle and rotate from middle around Z axis.
        // Translate back and blit the texture.
        // Restore matrix.
        glPushMatrix();

        glTranslatef(openglPos.x + texture->getScaledWidth()/2, 
            openglPos.y - texture->getScaledHeight()/2, openglPos.z - 1.0f);
        glRotatef(rotation, 0, 0, 1.0f); // Rotate around Z axis
        glTranslatef(-texture->getScaledWidth()/2, texture->getScaledHeight()/2, 0);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(texture->getScaledWidth(), 0, 0);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(texture->getScaledWidth(), -texture->getScaledHeight(), 0);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(0, -texture->getScaledHeight(), 0); 
        glEnd();

        glPopMatrix();
    }


    // Translates world coordinate to openGL coordinates
    HamurVec3 HamurTexMR::worldToGL(float x, float y, float z)
    {
        HamurVec3 GLcoord;
        GLcoord.x = -openglX + (x / pixRatioX);
        GLcoord.y =  openglY - (y / pixRatioY);
        GLcoord.z = z / 1000.0f;
        
        return GLcoord;
    }


    // Translates world coordinate to openGL coordinates
    HamurVec3 HamurTexMR::worldToGL(const HamurVec3 &vec3)
    {
        HamurVec3 GLcoord;
        GLcoord.x = -openglX + (vec3.x / pixRatioX);
        GLcoord.y =  openglY - (vec3.y / pixRatioY);
        GLcoord.z = vec3.z / 1000.0f;

        return GLcoord;
    }

    // Translates world coordinate to openGL coordinates
    HamurVec2 HamurTexMR::worldToGL(float x, float y)
    {
        HamurVec2 GLcoord;
        GLcoord.x = -openglX + (x / pixRatioX);
        GLcoord.y =  openglY - (y / pixRatioY);

        return GLcoord;
    }


    // Translates world coordinate to openGL coordinates
    HamurVec2 HamurTexMR::worldToGL(const HamurVec2 &vec2)
    {
        HamurVec2 GLcoord;
        GLcoord.x = -openglX + (vec2.x / pixRatioX);
        GLcoord.y =  openglY - (vec2.y / pixRatioY);

        return GLcoord;
    }
}
