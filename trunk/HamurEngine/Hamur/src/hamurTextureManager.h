#ifndef HAMURTEXMR_H
#define HAMURTEXMR_H

#include "SDL.h"
#include "hamurSingleton.h"
#include "helper/hamurVec2.h"
#include "helper/hamurVec3.h"

#include <map>
#include <string>

using std::string;
using std::map;


namespace hamur
{

// Forward declerations
class HamurTexture;


// Texture manager for Hamur.
// This manages all operations of the textures(blit, store, delete...)
class HamurTextureManager : public Singleton<HamurTextureManager>
{
	public:

        friend class Singleton<HamurTextureManager>;

        /**
        * Initialize Hamur Texture Manager
        * @return True if initialization is successful else return False
        */
        bool Init();

	    HamurTexture* GetTexture(unsigned int textureID) const; //Get texture
	    bool DeleteTexture(unsigned int textureID);   //Delete texture
	    unsigned int AddTexture(const string& filePath); //Add texture from image file
        unsigned int AddTexture(const string& filePath, Uint8 red, Uint8 green, Uint8 blue); //Add texture from image file with colorkey
	    unsigned int AddTexture(SDL_Surface* newSurface, const string &strName); //Add texture from SDL surface
        unsigned int AddTexture(SDL_Surface* newSurface, const string &strName, Uint8 red, Uint8 green, Uint8 blue); //Add texture from SDL surface with colorkey
	    void BlitTexture(unsigned int textureID, const HamurVec3& position, float rotation = 0); // Blits image onto screen
        void BlitTexture(unsigned int textureID, float x, float y, float z, float rotation = 0); // Blits image onto screen

        HamurVec3 WorldToGL(float x, float y, float z) const;
        HamurVec3 WorldToGL(const HamurVec3& vec3) const;

        HamurVec2 WorldToGL(float x, float y) const;
        HamurVec2 WorldToGL(const HamurVec2& vec2) const;

        /**
        * Clear and delete all texture objects in Texture manager
        */
        void ClearAll();

	protected:

        HamurTextureManager();
        ~HamurTextureManager();

	private:

		map<unsigned int, HamurTexture*> mTextureMap; //Store textures according to their unique texture ID

        const float mDepthShift; /**< Default shift value to keep textures in visible area. Z = -1.0f */
        float mOpenglX;
        const float mOpenglY;
        float mAspectRatio;
        float mPixRatioX;
        float mPixRatioY;
};


/**< Translates world coordinate to openGL coordinates */
inline HamurVec3 HamurTextureManager::WorldToGL(float x, float y, float z) const
{
    HamurVec3 GLcoord;
    GLcoord.x = -mOpenglX + (x / mPixRatioX);
    GLcoord.y =  mOpenglY - (y / mPixRatioY);
    GLcoord.z = z / 1000.0f;

    return GLcoord;
}


/**< Translates world coordinate to openGL coordinates */
inline HamurVec3 HamurTextureManager::WorldToGL(const HamurVec3 &vec3) const
{
    HamurVec3 GLcoord;
    GLcoord.x = -mOpenglX + (vec3.x / mPixRatioX);
    GLcoord.y =  mOpenglY - (vec3.y / mPixRatioY);
    GLcoord.z = vec3.z / 1000.0f;

    return GLcoord;
}


/**< Translates world coordinate to openGL coordinates */
inline HamurVec2 HamurTextureManager::WorldToGL(float x, float y) const
{
    HamurVec2 GLcoord;
    GLcoord.x = -mOpenglX + (x / mPixRatioX);
    GLcoord.y =  mOpenglY - (y / mPixRatioY);

    return GLcoord;
}


/**< Translates world coordinate to openGL coordinates */
inline HamurVec2 HamurTextureManager::WorldToGL(const HamurVec2 &vec2) const
{
    HamurVec2 GLcoord;
    GLcoord.x = -mOpenglX + (vec2.x / mPixRatioX);
    GLcoord.y =  mOpenglY - (vec2.y / mPixRatioY);

    return GLcoord;
}

} // namespace hamur

#endif // HAMURTEXMR_H
