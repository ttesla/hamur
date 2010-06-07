#ifndef HAMURTEXMR_H
#define HAMURTEXMR_H

#include <map>

#include "hamurGL.h"
#include "hamurTex.h"
#include "helper/hamurLog.h"
#include "helper/hamurConsole.h"
#include "helper/hamurHash.h"
#include "hamurDefinitions.h"
#include "hamurSingleton.h"
#include "helper/hamurVec2.h"
#include "helper/hamurVec3.h"

using std::map;


namespace hamur
{

	// Texture manager for Hamur. 
	// This manages all operations of the textures(blit, store, delete...)

	class HamurTexMR : public Singleton<HamurTexMR>
	{
		public:

            friend Singleton<HamurTexMR>;

			HamurTex* getTexture(unsigned int textureID); //Get texture
			bool deleteTexture(unsigned int textureID);   //Delete texture
			unsigned int addTexture(const string& filePath); //Add texture from image file
			unsigned int addTexture(const SDL_Surface *newSurface, const string &strName); //Add texture from SDL surface
			void blitTexture(unsigned int textureID, const HamurVec3 &position, float rotation = 0); // Blits image onto screen
            void blitTexture(unsigned int textureID, float x, float y, float z, float rotation = 0); // Blits image onto screen

            HamurVec3 worldToGL(float x, float y, float z);
            HamurVec3 worldToGL(const HamurVec3 &vec3);

            HamurVec2 worldToGL(float x, float y);
            HamurVec2 worldToGL(const HamurVec2 &vec2);


		protected:

            HamurTexMR();
            ~HamurTexMR();

		private:

            
			map<unsigned int, HamurTex*> textureMap; //Store textures according to their unique texture ID

            const float depthShift; /**< Default shift value to keep textures in visible area. Z = -1.0f */
            float openglX;
            float openglY;
            float aspectRatio;
            float pixRatioX;
            float pixRatioY;
	};


    // Translates world coordinate to openGL coordinates
    inline HamurVec3 HamurTexMR::worldToGL(float x, float y, float z)
    {
        HamurVec3 GLcoord;
        GLcoord.x = -openglX + (x / pixRatioX);
        GLcoord.y =  openglY - (y / pixRatioY);
        GLcoord.z = z / 1000.0f;

        return GLcoord;
    }


    // Translates world coordinate to openGL coordinates
    inline HamurVec3 HamurTexMR::worldToGL(const HamurVec3 &vec3)
    {
        HamurVec3 GLcoord;
        GLcoord.x = -openglX + (vec3.x / pixRatioX);
        GLcoord.y =  openglY - (vec3.y / pixRatioY);
        GLcoord.z = vec3.z / 1000.0f;

        return GLcoord;
    }


    // Translates world coordinate to openGL coordinates
    inline HamurVec2 HamurTexMR::worldToGL(float x, float y)
    {
        HamurVec2 GLcoord;
        GLcoord.x = -openglX + (x / pixRatioX);
        GLcoord.y =  openglY - (y / pixRatioY);

        return GLcoord;
    }


    // Translates world coordinate to openGL coordinates
    inline HamurVec2 HamurTexMR::worldToGL(const HamurVec2 &vec2)
    {
        HamurVec2 GLcoord;
        GLcoord.x = -openglX + (vec2.x / pixRatioX);
        GLcoord.y =  openglY - (vec2.y / pixRatioY);

        return GLcoord;
    }
}

#endif //HAMURTEXMR_H