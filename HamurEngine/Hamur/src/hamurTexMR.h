#ifndef HAMURTEXMR_H
#define HAMURTEXMR_H

#include <map>

#include "hamurTex.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"
#include "hamurSingleton.h"

using std::map;

namespace hamur
{

	// Texture manager for Hamur. 
	// This manages all operations of the textures(blit, store, delete...)

	class HamurTexMR : public Singleton<HamurTexMR>
	{
		public:

            friend Singleton<HamurTexMR>;

			HamurTex* getTexture(const string& strTextName); //Get texture
			bool deleteTexture(const string& strTextName);   //Delete texture
			void addTexture(const string& strFileName, const string& strTextName);     //Add texture from image file
			void addTexture(const SDL_Surface *newSurface, const string& strTextName); //Add texture from SDL surface
			void blitTexture(const string &textureName, float x, float y, float z);   // Blits image onto screen
			void blitTexture(const string &textureName); // Blits image onto screen - without coordinates

		protected:

            HamurTexMR();
            ~HamurTexMR();

		private:

			map<string, HamurTex*> textureMap; //Store textures according to their text. names
	};
}

#endif //HAMURTEXMR_H