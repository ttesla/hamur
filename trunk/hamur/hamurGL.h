#ifndef HAMURGL_H
#define HAMURGL_H

#include <iostream>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "hamurTex.h"
#include "hamurLog.h"
#include "hamurDefinition.h"

// Used std functions
using std::cout;
using std::endl;
using std::cerr;
using std::string;


// INTERFACE OF hamurGL
namespace hamur
{	
	class HamurGL
	{
	public:

		// Return HamurGL singleton object
		static HamurGL* getInstance(); 
	
		// Initialize SDL with OpenGL support
		bool init_SDL(const string &caption, int width, int height, int bpp, Uint32 flags);

		// Initialize OpenGL and set OpenGL attributes
		bool init_GL();

		// Display some primitive openGL properties to stdout
		void display_GL_attributes();

		// Terminate SDL and quit
		void quit();

		int get_screen_width();
		int get_screen_height();
		int get_screen_bpp();

		void set_screen_width(int width);
		void set_screen_height(int height);
		void set_screen_bpp(int bpp);

	protected:
			
			HamurGL();
			~HamurGL();

	private:

		// VARIABLES
		int SCREEN_WIDTH;  // Screen width
		int SCREEN_HEIGHT; // Screen height
		int SCREEN_BPP;	   // Screen bits per pixel

		// Sets openGL display attributes, color depth sizes, doublebuffer...
		void set_GL_attributes();
	};
}
#endif // HAMURGL_H
