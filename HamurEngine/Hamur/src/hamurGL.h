#ifndef HAMURGL_H
#define HAMURGL_H
#include "hamurTex.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"
#include "hamurSingleton.h"

#include "SDL.h"
#include "SDL_opengl.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using std::string;

namespace hamur
{
    /**
    * Hamur GL Manager.
    * Singleton class that manages graphic system.
    */ 
	class HamurGL : public Singleton<HamurGL>
	{
	public:
        
        friend Singleton<HamurGL>;
	
        /**
        * Initialization of SDL with OpenGL support
        * @param caption Sets the window tile and icon name.
        * @param width Sets the width of the screen.
        * @param height Sets the height of the screen.
        * @param bpp Sets bits-per-pixel of the screen.
        * @param flags Sets SDL flags for Video Mode.
        */
		bool initSDL(const string &caption, int width, int height, int bpp, Uint32 flags);

        /**
        * Initialization of default OpenGL and OpenGL attributes.
        */
		bool initGL();

		// Display some primitive openGL properties to stdout
		void displayGLAttributes();

		/**
		* Terminate SDL and quit.
		*/
		void quit();

        /**
        * Gets the width of the screen.
        * @return Screen width
        */
		int getScreenWidth();

        /**
        * Gets the height of the screen.
        * @return Screen height
        */
		int getScreenHeight();

        /**
        * Gets the bits-per-pixel of the screen.
        * @return Bits-per-pixel
        */
		int getScreenBpp();

        /**
        * Sets the screen width of the screen.
        * @param width Screen width.
        */
		void setScreenWidth(int width);

        /**
        * Sets the height of the screen.
        * @param height Screen height
        */
		void setScreenHeight(int height);

        /**
        * Sets the bits-per-pixel of the screen.
        * @param bpp Bits-per-pixel
        */
		void setScreenBpp(int bpp);

	protected:

        HamurGL();
        ~HamurGL();
		
	private:
		int SCREEN_WIDTH;  /**<  Screen width */ 
		int SCREEN_HEIGHT; /**<  Screen height */
		int SCREEN_BPP;	   /**<  Screen bits per pixel */

        /**
        * Sets openGL display attributes, color depth sizes, doublebuffer...
        * This function must be called after SDL_Init() and before SDL_SetVideoMode()
        */ 
		void setGLAttributes();
	};
}

#endif // HAMURGL_H
