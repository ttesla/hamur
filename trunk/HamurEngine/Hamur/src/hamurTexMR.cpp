#include "hamurTexMR.h"

#include "hamurGL.h"
#include "hamurTex.h"
#include "helper/hamurLog.h"
#include "helper/hamurConsole.h"
#include "helper/hamurHash.h"
#include "hamurDefinitions.h"


namespace hamur
{

HamurTexMR::HamurTexMR() : mDepthShift(1.0f), mOpenglY(0.414f)
{
    // Calculactions for world - openGL coordinate translations
    mAspectRatio = (float)HAMURGL->GetScreenWidth() / (float)HAMURGL->GetScreenHeight();
    mOpenglX     = mOpenglY * mAspectRatio;
    mPixRatioX   = (float)HAMURGL->GetScreenWidth()  / (mOpenglX*2);
    mPixRatioY   = (float)HAMURGL->GetScreenHeight() / (mOpenglY*2);		
}


// Initialize Hamur texture manager
bool HamurTexMR::Init()
{
    HAMURLOG->WriteInitLog("HamurTexMR");  
    return true;
}


// Deletes all textures in the map container
HamurTexMR::~HamurTexMR()
{
	ClearAll();
    HAMURLOG->WriteTerminateLog("HamurTexMR");
}


// Get texture from "map" container according to given texture name
HamurTex* HamurTexMR::GetTexture(unsigned int textureID) const
{
	//Look in the map if the texture is already loaded.
	map<unsigned int, HamurTex*>::const_iterator iter = mTextureMap.find(textureID);

	if(iter != mTextureMap.end())
		return iter->second;

	else
		return 0; // Return NULL, texture not found.
}


// Add texture into "map" container with texture name index from image file.
// If the texture is already loaded, it doesn't add another copy
unsigned int HamurTexMR::AddTexture(const string& filePath)
{
    // Generate textureID according to hash function
    unsigned int textureID = HamurHash::hashFunction(filePath);

	// Look in the map if the texture is already loaded.
	map<unsigned int, HamurTex*>::iterator iter = mTextureMap.find(textureID);
	
	// If not found, then add
	if(iter == mTextureMap.end())
	{
		HamurTex *newTex = new HamurTex(filePath);
		mTextureMap[textureID] = newTex;
	}

    return textureID;
}


// Add texture into "map" container with texture name index from image file with colorkey.
// If the texture is already loaded, it doesn't add another copy
unsigned int HamurTexMR::AddTexture(const string& filePath, Uint8 red, Uint8 green, Uint8 blue)
{
    // Generate textureID according to hash function
    unsigned int textureID = HamurHash::hashFunction(filePath);

    // Look in the map if the texture is already loaded.
    map<unsigned int, HamurTex*>::iterator iter = mTextureMap.find(textureID);

    // If not found, then add
    if(iter == mTextureMap.end())
    {
        HamurTex *newTex = new HamurTex(filePath, red, green, blue);
        mTextureMap[textureID] = newTex;
    }

    return textureID;
}



// Add texture into "map" container with texture name index from SDL surface.
// If the texture is already loaded, it doesn't add another copy
unsigned int HamurTexMR::AddTexture(SDL_Surface* newSurface, const string& strName)
{
    // Generate textureID according to hash function
    unsigned int textureID = HamurHash::hashFunction(strName);

	// Look in the map if the texture is already loaded.
	map<unsigned int, HamurTex*>::iterator iter = mTextureMap.find(textureID);
	
	// If not found, then add
	if(iter == mTextureMap.end())
	{
		HamurTex *newTex = new HamurTex(newSurface);
		mTextureMap[textureID] = newTex;
	}

    return textureID;
}


// Add texture into "map" container with texture name index from SDL surface with colorkey.
// If the texture is already loaded, it doesn't add another copy
unsigned int HamurTexMR::AddTexture(SDL_Surface* newSurface, const string& strName, Uint8 red, Uint8 green, Uint8 blue)
{
    // Generate textureID according to hash function
    unsigned int textureID = HamurHash::hashFunction(strName);

    // Look in the map if the texture is already loaded.
    map<unsigned int, HamurTex*>::iterator iter = mTextureMap.find(textureID);

    // If not found, then add
    if(iter == mTextureMap.end())
    {
        HamurTex *newTex = new HamurTex(newSurface, red, green, blue);
        mTextureMap[textureID] = newTex;
    }

    return textureID;
}

// Deletes texture according to given texture name. 
bool HamurTexMR::DeleteTexture(unsigned int textureID)
{
	map<unsigned int, HamurTex*>::iterator iter = mTextureMap.find(textureID);

	if(iter != mTextureMap.end())
	{
		if(iter->second)
			delete iter->second;
		
		mTextureMap.erase(iter);

        return true;
	}

    HAMURLOG->WriteLog("Error!: Can't delete texture, ID: ", HamurLog::ALWAYS);
    HAMURLOG->WriteLogln(textureID, HamurLog::ALWAYS);
	return false;
}


// Blits image onto screen
void HamurTexMR::BlitTexture(unsigned int textureID, const HamurVec3& position, float rotation)
{
	HamurTex *texture = GetTexture(textureID);

	if(texture == 0)
	{
        HAMURLOG->WriteLog("Error!: Can't find texture, ID: ", HamurLog::ALWAYS);
        HAMURLOG->WriteLogln(textureID, HamurLog::ALWAYS);
		exit(1);
	}

    // Translate coordinates from World to openGL coordinates.
    HamurVec3 openglPos = WorldToGL(position);

	texture->SetAllCoord(openglPos.x, openglPos.x, openglPos.x); // Update texture coordinates
	glBindTexture(GL_TEXTURE_2D, texture->GetGLtextureID()); // Bind texture

    // Save current matrix. 
    // Perform translation to texture's middle and rotate from middle around Z axis.
    // Translate back and blit the texture.
    // Restore matrix.
    glPushMatrix();
    
    glTranslatef(openglPos.x, openglPos.y, openglPos.z);
    //glTranslatef(openglPos.x + texture->GetScaledWidth()/2, 
    //    openglPos.y - texture->GetScaledHeight()/2, openglPos.z);
    glRotatef(rotation, 0, 0, 1.0f); 
    //glTranslatef(-texture->GetScaledWidth()/2, texture->GetScaledHeight()/2, 0);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-texture->GetScaledWidth()/2, texture->GetScaledHeight()/2, 0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(texture->GetScaledWidth()/2, texture->GetScaledHeight()/2, 0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(texture->GetScaledWidth()/2, -texture->GetScaledHeight()/2, 0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-texture->GetScaledWidth()/2, -texture->GetScaledHeight()/2, 0); 
    glEnd();

    glPopMatrix();
}


// Blits image onto screen
void HamurTexMR::BlitTexture(unsigned int textureID, float x, float y, float z, float rotation)
{
    HamurTex *texture = GetTexture(textureID);

    if(texture == 0)
    {
        HAMURLOG->WriteLog("Error!: Can't find texture: ", HamurLog::ALWAYS);
        HAMURLOG->WriteLogln(textureID, HamurLog::ALWAYS);
        exit(1);
    }

    // Translate coordinates from World to openGL coordinates.
    HamurVec3 openglPos = WorldToGL(x, y, z);

    texture->SetAllCoord(openglPos.x, openglPos.x, openglPos.x); // Update texture coordinates
    glBindTexture(GL_TEXTURE_2D, texture->GetGLtextureID()); // Bind texture

    // Save current matrix. 
    // Perform translation to texture's middle and rotate from middle around Z axis.
    // Translate back and blit the texture.
    // Restore matrix.
    glPushMatrix();

    glTranslatef(openglPos.x + texture->GetScaledWidth()/2, 
        openglPos.y - texture->GetScaledHeight()/2, openglPos.z);
    glRotatef(rotation, 0, 0, 1.0f); // Rotate around Z axis
    glTranslatef(-texture->GetScaledWidth()/2, texture->GetScaledHeight()/2, 0);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(texture->GetScaledWidth(), 0, 0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(texture->GetScaledWidth(), -texture->GetScaledHeight(), 0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0, -texture->GetScaledHeight(), 0); 
    glEnd();

    glPopMatrix();
}


void HamurTexMR::ClearAll()
{
    map<unsigned int, HamurTex*>::iterator iter;

    for(iter = mTextureMap.begin(); iter != mTextureMap.end(); iter++)
    {
        if(iter->second)
            delete iter->second;
    }

    HAMURLOG->WriteLogln("All textures deleted.");
}

} // namespace hamur
