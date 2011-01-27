#ifndef HAMURGL_H
#define HAMURGL_H

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_ttf.h"
#include "hamurSingleton.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using std::string;


namespace hamur
{

/**
* Hamur OpenGL Manager.
* Singleton class that manages graphic system.
*/
class HamurOpenGL : public Singleton<HamurOpenGL>
{
    public:

        friend class Singleton<HamurOpenGL>;

        /**
        * Initialization of SDL with OpenGL support
        * @param caption Sets the window tile and icon name.
        * @param width Sets the width of the screen.
        * @param height Sets the height of the screen.
        * @param bpp Sets bits-per-pixel of the screen.
        * @param flags Sets SDL flags for Video Mode.
        */
	    bool InitSDL(const string& caption, int width, int height, int bpp, Uint32 flags);

        /**
        * Initialization of default OpenGL and OpenGL attributes.
        */
	    bool InitGL();

	    /**
	    * Display some primitive openGL properties to stdout
	    */
	    void DisplayGLAttributes();

        /**
        * Gets the width of the screen.
        * @return Screen width
        */
	    int GetScreenWidth() const;

        /**
        * Gets the height of the screen.
        * @return Screen height
        */
	    int GetScreenHeight() const;

        /**
        * Gets the bits-per-pixel of the screen.
        * @return Bits-per-pixel
        */
	    int GetScreenBpp() const;

        /**
        * Sets the screen width of the screen.
        * @param width Screen width.
        */
	    void SetScreenWidth(int width);

        /**
        * Sets the height of the screen.
        * @param height Screen height
        */
	    void SetScreenHeight(int height);

        /**
        * Sets the bits-per-pixel of the screen.
        * @param bpp Bits-per-pixel
        */
	    void SetScreenBpp(int bpp);

    protected:

        HamurOpenGL();
        ~HamurOpenGL();

    private:

	    int SCREEN_WIDTH;  /**<  Screen width */
	    int SCREEN_HEIGHT; /**<  Screen height */
	    int SCREEN_BPP;	   /**<  Screen bits per pixel */

        /**
        * Sets openGL display attributes, color depth sizes, doublebuffer...
        * This function must be called after SDL_Init() and before SDL_SetVideoMode()
        */
	    void SetGLAttributes();
};

} // namespace hamur

#endif // HAMURGL_H
