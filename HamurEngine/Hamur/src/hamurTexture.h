#ifndef HAMURTEX_H
#define HAMURTEX_H

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include "helper/hamurVec2.h"

#include <string>

using std::string;


namespace hamur
{

/**
* Hamur Texture
*/
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
        int GetPixelWidth() const;
        int GetPixelHeight() const;
		float GetOpenglWidth() const;
		float GetOpenglHeight() const;
        HamurVec2 GetScale() const;
        float GetRotation() const;
		float GetVolume() const;
        float GetX() const;
        float GetY() const;
        float GetZ() const;
        string GetTextName() const;
        string GetFilePath() const;
        float GetAlpha() const;

		void SetX(float x);
		void SetY(float y);
		void SetZ(float z);
		void SetAllCoord(float x, float y, float z);
		void SetOpenglWidth(float sw);
		void SetOpenglHeight(float sh);
        void SetScale(const HamurVec2&  scale);
        void SetRotation(float rotation);
        void SetAlpha(float alpha);
   

	private:

		GLuint mTextureID[1]; /// Storage for one texture
		int mPixelWidth;      /// Actual Width of the texture in pixels
		int mPixelHeight;     /// Actual Height of the texture in pixels
		float mOpenglWidth;   /// Width of the texture scaled to OpenGL coordinates
		float mOpenglHeight;  /// Height of the texture scaled to OpenGL coordinates
        HamurVec2 mScale;     /// Scale factor of texture
        float mRotation;      /// Rotation amount of the texture (0-360) degree
		string mFilePath;  /// File path name of the texture
		float mCorX; /// X coordinate of the texture
		float mCorY; /// Y coordinate of the texture
		float mCorZ; /// Z coordinate of the texture
        bool mHasColorKey; /// If texture image has color-key or not
        Uint8 mRedKey;   /// Colorkey for RED
        Uint8 mGreenKey; /// Colorkey for GREEN
        Uint8 mBlueKey;  /// Colorkey for BLUE
        float mAlpha; /// Alpha color of the texture for transparency (1: opaque, 0: transparent)

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
        void GenerateTexture(const SDL_Surface* surface);
};


// GETTERS & SETTERS 
inline int HamurTexture::GetGLtextureID() const	   { return mTextureID[0];	}
inline int HamurTexture::GetPixelWidth() const     { return mPixelWidth;  }
inline int HamurTexture::GetPixelHeight() const    { return mPixelHeight; }
inline float HamurTexture::GetOpenglWidth() const  { return mOpenglWidth;  }
inline float HamurTexture::GetOpenglHeight() const { return mOpenglHeight; }
inline HamurVec2 HamurTexture::GetScale() const     { return mScale; }
inline float HamurTexture::GetRotation() const { return mRotation;	}
inline string HamurTexture::GetFilePath() const    { return mFilePath;	}
inline float HamurTexture::GetX() const { return mCorX; }
inline float HamurTexture::GetY() const { return mCorY; }
inline float HamurTexture::GetZ() const { return mCorZ; }
inline float HamurTexture::GetAlpha() const { return mAlpha; }

inline void HamurTexture::SetX(float x) { mCorX = x; }
inline void HamurTexture::SetY(float y) { mCorY = y; }
inline void HamurTexture::SetZ(float z) { mCorZ = z; }
inline void HamurTexture::SetOpenglWidth(float sw)  { mOpenglWidth  = sw; }
inline void HamurTexture::SetOpenglHeight(float sh) { mOpenglHeight = sh; }
inline void HamurTexture::SetScale(const HamurVec2& scale) { mScale = scale; }
inline void HamurTexture::SetRotation(float rotation) { mRotation = rotation;}
inline void HamurTexture::SetAlpha(float alpha) { mAlpha = alpha; }

inline void HamurTexture::SetAllCoord(float x, float y, float z)
{
    mCorX = x;
    mCorY = y;
    mCorZ = z;
}


} // namespace hamur

#endif //HAMURTEX_H
