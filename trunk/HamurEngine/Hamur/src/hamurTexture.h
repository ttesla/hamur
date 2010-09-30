#ifndef HAMURTEX_H
#define HAMURTEX_H

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"

#include <string>

using std::string;


namespace hamur
{

class HamurTexture
{
	public:

		HamurTexture(const string& filePath);
        HamurTexture(const string& filePath, Uint8 red, Uint8 green, Uint8 blue);
		HamurTexture(SDL_Surface* newSurface);
        HamurTexture(SDL_Surface* newSurface, Uint8 red, Uint8 green, Uint8 blue);
		~HamurTexture();

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
        bool mHasColorKey; /// If texture image has color-key or not
        Uint8 mRedKey;   /// Colorkey for RED
        Uint8 mGreenKey; /// Colorkey for GREEN
        Uint8 mBlueKey;  /// Colorkey for BLUE

        // SDL color masks according to endianness (byte order) of the machine 
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
        const static Uint32 mRedMask   = 0xff000000;
        const static Uint32 mGreenMask = 0x00ff0000;
        const static Uint32 mBlueMask  = 0x0000ff00;
        const static Uint32 mAlphaMask = 0x000000ff;
#else
        const static Uint32 mRedMask   = 0x000000ff;
        const static Uint32 mGreenMask = 0x0000ff00;
        const static Uint32 mBlueMask  = 0x00ff0000;
        const static Uint32 mAlphaMask = 0xff000000;
#endif

		bool LoadTextureFromFile(); /// Loads texture from image file
		bool LoadTextureFromSurface(SDL_Surface* newSurface); /// Loads texture from SDL surface
        void GenerateTexture(const SDL_Surface* surface, int mode);
};

} // namespace hamur

#endif //HAMURTEX_H
