#ifndef HAMURTEX_H
#define HAMURTEX_H

//#include "hamurGL.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"

#include <string>

using std::string;


namespace hamur
{
	class HamurTex
	{
		public:

			HamurTex(const string& _filePath);
			HamurTex(const SDL_Surface *newSurface);
			~HamurTex();

			// SETTERS & GETTERS
			int getGLtextureID();
			float getScaledWidth();
			float getScaledHeight();
			float getVolume();
			void setVolume(float vol);
			string getTextName();
			string getFilePath();
			void setCorX(float x);
			void setCorY(float y);
			void setCorZ(float z);
			void setAllCoord(float x, float y, float z);
			void setScaledWidth(float sw);
			void setScaledHeight(float sh);
			float getCorX();
			float getCorY();
			float getCorZ();

		private:

			GLuint textureID[1]; // Storage for one texture
			int textureWidth;    // Width of the texture
			int textureHeight;   // Height of the texture
			float scaledWidth;   // Scaled width of the texture
			float scaledHeight;  // Scaled height of the texture
			string filePath;  // File path name of the texture
			float corX; // X coordinate of the texture
			float corY; // Y coordinate of the texture
			float corZ; // Z coordinate of the texture

			bool loadTexture(); // Loads texture from image file
			bool loadTexture(const SDL_Surface *newSurface); // Loads texture from SDL surface
	};
}
#endif //HAMURTEX_H
