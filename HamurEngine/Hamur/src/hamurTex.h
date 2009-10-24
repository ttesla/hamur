#ifndef HAMURTEX_H
#define HAMURTEX_H

#include <string>
#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"

#include "hamurGL.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"


using std::string;

const float RATIO = 128.0f; // TEXTURE_RATIO
const float VOL = 2.0f;     // VOLUME


namespace hamur
{
	
	class HamurTex
	{
		public:

			HamurTex();
			HamurTex(const string& fileName, const string& textName);
			HamurTex(const SDL_Surface *newSurface, const string& textName);
			~HamurTex();

			// SETTERS & GETTERS
			int get_textureID();
			float get_scaledWidth();
			float get_scaledHeight();
			float get_volume();
			void set_volume(float vol);
			string get_textName();
			string get_fileName();
			void set_corX(float x);
			void set_corY(float y);
			void set_corZ(float z);
			void set_all_coord(float x, float y, float z);
			void setScaledWidth(float sw);
			void setScaledHeight(float sh);
			float get_corX();
			float get_corY();
			float get_corZ();

		private:

			GLuint textureID[1]; // Storage for one texture
			int textureWidth;    // Width of the texture
			int textureHeight;   // Height of the texture
			float scaledWidth;   // Scaled width of the texture
			float scaledHeight;  // Scaled height of the texture
			float volume;		 // Virtual volume of the texture
			string strTextName;	 // Name of the texture
			string strFileName;  // File path name of the texture
			float TEXTURE_RATIO; // Scale ratio of all textures
			float corX; // X coordinate of the texture
			float corY; // Y coordinate of the texture
			float corZ; // Z coordinate of the texture

			bool loadTexture(const string& fileName);		 // Loads texture from image file
			bool loadTexture(const SDL_Surface *newSurface); // Loads texture from SDL surface
	};
}
#endif //HAMURTEX_H
