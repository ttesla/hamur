#ifndef HAMURTEX_H
#define HAMURTEX_H

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

		HamurTex(const string& filePath);
		HamurTex(const SDL_Surface* newSurface);
		~HamurTex();

		// SETTERS & GETTERS
		int GetGLtextureID() const;
        int GetWidth() const;
        int GetHeight() const;
		float GetScaledWidth() const;
		float GetScaledHeight() const;
		float GetVolume() const;
        float GetCorX() const;
        float GetCorY() const;
        float GetCorZ() const;
        string GetTextName() const;
        string GetFilePath() const;

		void SetCorX(float x);
		void SetCorY(float y);
		void setCorZ(float z);
		void SetAllCoord(float x, float y, float z);
		void SetScaledWidth(float sw);
		void SetScaledHeight(float sh);
		

	private:

		GLuint mTextureID[1]; /// Storage for one texture
		int mTextureWidth;    /// Width of the texture
		int mTextureHeight;   /// Height of the texture
		float mScaledWidth;   /// Scaled width of the texture
		float mScaledHeight;  /// Scaled height of the texture
		string mFilePath;  /// File path name of the texture
		float mCorX; /// X coordinate of the texture
		float mCorY; /// Y coordinate of the texture
		float mCorZ; /// Z coordinate of the texture

		bool LoadTexture(); /// Loads texture from image file
		bool LoadTexture(const SDL_Surface* newSurface); /// Loads texture from SDL surface
};

} // namespace hamur

#endif //HAMURTEX_H
