#include "hamurTextureManager.h"

#include "hamurOpenGL.h"
#include "hamurTexture.h"
#include "helper/hamurLog.h"
#include "helper/hamurConsole.h"
#include "helper/hamurHash.h"
#include "helper/hamurMath.h"
#include "hamurDefinitions.h"


namespace hamur
{

HamurTextureManager::HamurTextureManager() : mDepthShift(1.0f), mOpenglY(0.414f)
{
    // Calculactions for world - openGL coordinate translations
    mAspectRatio = (float)HAMURGL->GetScreenWidth() / (float)HAMURGL->GetScreenHeight();
    mOpenglX     = mOpenglY * mAspectRatio;
    mPixRatioX   = (float)HAMURGL->GetScreenWidth()  / (mOpenglX*2);
    mPixRatioY   = (float)HAMURGL->GetScreenHeight() / (mOpenglY*2);		
}


// Initialize Hamur texture manager
bool HamurTextureManager::Init()
{
    HAMURLOG->WriteInitLog("HamurTextureManager");  
    return true;
}


// Deletes all textures in the map container
HamurTextureManager::~HamurTextureManager()
{
	ClearAll();
    HAMURLOG->WriteTerminateLog("HamurTextureManager");
}


// Get texture from "map" container according to given texture name
HamurTexture* HamurTextureManager::GetTexture(unsigned int textureID) const
{
	//Look in the map if the texture is already loaded.
	map<unsigned int, HamurTexture*>::const_iterator iter = mTextureMap.find(textureID);

	if(iter != mTextureMap.end())
		return iter->second;

	else
		return NULL; // Texture not found.
}


// Add texture into "map" container with texture name index from image file.
// If the texture is already loaded, it doesn't add another copy
unsigned int HamurTextureManager::AddTexture(const string& filePath)
{
    // Generate textureID according to hash function
    unsigned int textureID = HamurHash::hashFunction(filePath);

	// Look in the map if the texture is already loaded.
	map<unsigned int, HamurTexture*>::iterator iter = mTextureMap.find(textureID);
	
	// If not found, then add
	if(iter == mTextureMap.end())
	{
		HamurTexture *newTex = new HamurTexture(filePath);
		mTextureMap[textureID] = newTex;
	}

    return textureID;
}


// Add texture into "map" container with texture name index from image file with colorkey.
// If the texture is already loaded, it doesn't add another copy
unsigned int HamurTextureManager::AddTexture(const string& filePath, Uint8 red, Uint8 green, Uint8 blue)
{
    // Generate textureID according to hash function
    unsigned int textureID = HamurHash::hashFunction(filePath);

    // Look in the map if the texture is already loaded.
    map<unsigned int, HamurTexture*>::iterator iter = mTextureMap.find(textureID);

    // If not found, then add
    if(iter == mTextureMap.end())
    {
        HamurTexture *newTex = new HamurTexture(filePath, red, green, blue);
        mTextureMap[textureID] = newTex;
    }

    return textureID;
}



// Add texture into "map" container with texture name index from SDL surface.
// If the texture is already loaded, it doesn't add another copy
unsigned int HamurTextureManager::AddTexture(SDL_Surface* newSurface, const string& strName)
{
    // Generate textureID according to hash function
    unsigned int textureID = HamurHash::hashFunction(strName);

	// Look in the map if the texture is already loaded.
	map<unsigned int, HamurTexture*>::iterator iter = mTextureMap.find(textureID);
	
	// If not found, then add
	if(iter == mTextureMap.end())
	{
		HamurTexture *newTex = new HamurTexture(newSurface);
		mTextureMap[textureID] = newTex;
	}

    return textureID;
}


// Add texture into "map" container with texture name index from SDL surface with colorkey.
// If the texture is already loaded, it doesn't add another copy
unsigned int HamurTextureManager::AddTexture(SDL_Surface* newSurface, const string& strName, Uint8 red, Uint8 green, Uint8 blue)
{
    // Generate textureID according to hash function
    unsigned int textureID = HamurHash::hashFunction(strName);

    // Look in the map if the texture is already loaded.
    map<unsigned int, HamurTexture*>::iterator iter = mTextureMap.find(textureID);

    // If not found, then add
    if(iter == mTextureMap.end())
    {
        HamurTexture *newTex = new HamurTexture(newSurface, red, green, blue);
        mTextureMap[textureID] = newTex;
    }

    return textureID;
}

// Deletes texture according to given texture name. 
bool HamurTextureManager::DeleteTexture(unsigned int textureID)
{
	map<unsigned int, HamurTexture*>::iterator iter = mTextureMap.find(textureID);

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


// Assuming that all the properties of the texture was set before Blitting 
void HamurTextureManager::BlitTexture(unsigned int textureID)
{
    HamurTexture *texture = GetTexture(textureID);

    if(texture == 0)
    {
        HAMURLOG->WriteLog("Error!: Can't find texture, ID: ", HamurLog::ALWAYS);
        HAMURLOG->WriteLogln(textureID, HamurLog::ALWAYS);
        exit(1);
    }

    Blit(texture);
}


// Blits with position and rotation (if any)
void HamurTextureManager::BlitTexture(unsigned int textureID, const HamurVec3& position, 
    float rotation, float alpha)
{
    HamurTexture *texture = GetTexture(textureID);

    if(texture == 0)
    {
        HAMURLOG->WriteLog("Error!: Can't find texture, ID: ", HamurLog::ALWAYS);
        HAMURLOG->WriteLogln(textureID, HamurLog::ALWAYS);
        exit(1);
    }

    // World to openGL coordinates - Update position - Scale 
    HamurVec3 openglPos = WorldToGL(position);
    texture->SetAllCoord(openglPos.x, openglPos.y, openglPos.z); 
    texture->SetRotation(rotation);
    texture->SetAlpha(alpha);

    Blit(texture);    
}


// Blits image onto screen
void HamurTextureManager::BlitTexture(unsigned int textureID, const HamurVec3& position, 
    const HamurVec2& scale, float rotation, float alpha)
{
	HamurTexture *texture = GetTexture(textureID);

	if(texture == 0)
	{
        HAMURLOG->WriteLog("Error!: Can't find texture, ID: ", HamurLog::ALWAYS);
        HAMURLOG->WriteLogln(textureID, HamurLog::ALWAYS);
		exit(1);
	}

    // World to openGL coordinates - Update position - Scale 
    HamurVec3 openglPos = WorldToGL(position);
	texture->SetAllCoord(openglPos.x, openglPos.y, openglPos.z);
    texture->SetScale(scale);
    texture->SetRotation(rotation);
    texture->SetAlpha(alpha);
    
    Blit(texture);
}


// Blits image onto screen
void HamurTextureManager::BlitTexture(unsigned int textureID, float x, float y, float z, 
    float scaleX, float scaleY, float rotation, float alpha)
{
    HamurTexture *texture = GetTexture(textureID);

    if(texture == NULL)
    {
        HAMURLOG->WriteLog("Error!: Can't find texture: ", HamurLog::ALWAYS);
        HAMURLOG->WriteLogln(textureID, HamurLog::ALWAYS);
        exit(1);
    }

    // World to openGL coordinates - Update position - Scale 
    HamurVec3 openglPos = WorldToGL(x, y, z);
    texture->SetAllCoord(openglPos.x, openglPos.y, openglPos.z); 
    texture->SetScale(HamurVec2(scaleX, scaleY));
    texture->SetRotation(rotation);
    texture->SetAlpha(alpha);

    Blit(texture);
}


// Actual Blit is done here
void HamurTextureManager::Blit(const HamurTexture* texture)
{
    // This function does:
    // - Calculate scaling (also middle)
    // - Bind texture
    // - Save current matrix 
    // - Translate and Rotate
    // - Set transparency color - alpha
    // - Blit texture from middle
    // - Restore color
    // - Restore matrix

    float scaledWidth  = (texture->GetOpenglWidth()  * texture->GetScale().x) / 2;
    float scaledHeight = (texture->GetOpenglHeight() * texture->GetScale().y) / 2;

    glBindTexture(GL_TEXTURE_2D, texture->GetGLtextureID()); 
  
    glPushMatrix();

    glTranslatef(texture->GetX(), texture->GetY(), texture->GetZ());
    glRotatef(texture->GetRotation(), 0, 0, 1.0f); 

    glColor4f(1.0f, 1.0f, 1.0f, texture->GetAlpha());

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-scaledWidth,  scaledHeight, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(scaledWidth,   scaledHeight, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(scaledWidth,  -scaledHeight, 0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-scaledWidth, -scaledHeight, 0); 
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glPopMatrix();
}


void HamurTextureManager::ClearAll()
{
    map<unsigned int, HamurTexture*>::iterator iter;

    for(iter = mTextureMap.begin(); iter != mTextureMap.end(); iter++)
    {
        if(iter->second)
            delete iter->second;
    }

    HAMURLOG->WriteLogln("All textures deleted.");
}

} // namespace hamur
