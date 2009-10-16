#ifndef HAMURTEXMR_H
#define HAMURTEXMR_H

#include <map>

#include "hamurTex.h"
#include "hamurLog.h"
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

			//static HamurTexMR* getInstance(); // Return TextureMR singleton object
			HamurTexMR();
			~HamurTexMR();

			HamurTex* getTexture(const string& strTextName); //Get texture
			bool delete_texture(const string& strTextName);   //Delete texture
			void add_texture(const string& strFileName, const string& strTextName);     //Add texture from image file
			void add_texture(const SDL_Surface *newSurface, const string& strTextName); //Add texture from SDL surface
			void blit_texture(const string &textureName, float x, float y, float z);   // Blits image onto screen
			void blit_texture(const string &textureName); // Blits image onto screen - without coordinates

		protected:

		private:

			map<string, HamurTex*> textureMap; //Store textures according to their text. names
	};
}

#endif //HAMURTEXMR_H