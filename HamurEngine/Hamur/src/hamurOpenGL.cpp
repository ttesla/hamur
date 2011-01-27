#include "hamurOpenGL.h"
#include "hamurTexture.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"


// IMPLEMENTATION OF hamurGL
namespace hamur
{

// HamurOpenGL constructor
HamurOpenGL::HamurOpenGL()
{

}


// HamurOpenGL destructor
HamurOpenGL::~HamurOpenGL()
{
    SDL_Quit();
    HAMURLOG->WriteTerminateLog("HamurOpenGL");
}

// Initialize SDL with OpenGL support
bool HamurOpenGL::InitSDL(const string& caption, int width, int height, int bpp, Uint32 flags)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	SCREEN_BPP = bpp;

	// Initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
        HAMURLOG->WriteLogln("Error!: Can't initialize SDL", HamurLog::ALWAYS);
		return false; //If can't init, return false 
	}

	// Set openGL display attributes
	SetGLAttributes();

    // Set icon
    SDL_Surface* image = NULL; // We don't free this, its just an icon. 
    image = SDL_LoadBMP("hamurIcon.bmp");

    if(image)
    {
        // Icon with WHITE mask
        SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 255, 255, 255));              
        SDL_WM_SetIcon(image, NULL);
    }
    else
    {
        HAMURLOG->WriteLogln("Error!: Can't load icon: hamurIcon.bmp", HamurLog::ALWAYS);
    }
    
	// Create Window
	if(SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, flags) == NULL)
	{
        HAMURLOG->WriteLogln("Error!: Can't set video mode", HamurLog::ALWAYS); 
		return false;
	}

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        HAMURLOG->WriteLog("Error!: Can't initialize SDL_ttf :", HamurLog::ALWAYS);
        string errorStr = TTF_GetError();
        HAMURLOG->WriteLogln(errorStr, HamurLog::ALWAYS);
        return false;
    }
    
	// Set caption
	SDL_WM_SetCaption(caption.c_str(), "Hamur Engine");

	HAMURLOG->WriteInitLog("SDL");
	return true;
}


// Initialize OpenGL and set OpenGL attributes
bool HamurOpenGL::InitGL()
{	
	glEnable(GL_TEXTURE_2D);				// Enable 2D textures
	glShadeModel(GL_SMOOTH);				// Enable smooth shading
	glClearColor(0, 0, 0, 0);               // Clear color -- Black background
	glClearDepth(1.0f);						// Depth buffer setup
	glEnable(GL_DEPTH_TEST);				// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);					// The Type Of Depth Test To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); // Set viewport

	// Alpha blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    //glAlphaFunc ( GL_GREATER, 0.1f ) ;
    //glEnable ( GL_ALPHA_TEST ) ;

	// Set projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set perspective
	gluPerspective(45.0f, (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
	
	// Initialize modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	// If there was any errors
	if(glGetError() != GL_NO_ERROR)
	{
        HAMURLOG->WriteLogln("Error!: Can't initialize OpenGL", HamurLog::ALWAYS);
		return false;    
	}
    
	// If everything initialized successfully
	HAMURLOG->WriteInitLog("OpenGL");
	return true;
}


// Display some primitive openGL properties to stdout
void HamurOpenGL::DisplayGLAttributes()
{
    int red, green, blue, alpha, buffer, dbuff, depth;

    SDL_GL_GetAttribute(SDL_GL_RED_SIZE, &red);
    SDL_GL_GetAttribute(SDL_GL_GREEN_SIZE, &green);
    SDL_GL_GetAttribute(SDL_GL_BLUE_SIZE, &blue);
    SDL_GL_GetAttribute(SDL_GL_ALPHA_SIZE, &alpha);
    SDL_GL_GetAttribute(SDL_GL_BUFFER_SIZE, &buffer);
    SDL_GL_GetAttribute(SDL_GL_DOUBLEBUFFER, &dbuff);
    SDL_GL_GetAttribute(SDL_GL_DEPTH_SIZE, &depth);

    cout << "GL Init - RGBA:" << red << " " << green << " "
        << blue << " " << alpha << " BUFFER:" << buffer
        << " DEPTH:" << depth << " DBUFF:" << dbuff << endl;
}


// GETTERS & SETTERS
int HamurOpenGL::GetScreenWidth() const	    { return SCREEN_WIDTH;  }
int HamurOpenGL::GetScreenHeight() const    { return SCREEN_HEIGHT; }
int HamurOpenGL::GetScreenBpp() const       { return SCREEN_BPP;    }

void HamurOpenGL::SetScreenWidth(int width)     { SCREEN_WIDTH = width;     }
void HamurOpenGL::SetScreenHeight(int height)   { SCREEN_HEIGHT = height;   }
void HamurOpenGL::SetScreenBpp(int bpp)         { SCREEN_BPP = bpp;         }


// Set GL display attributes, 
// it must be called after SDL_Init() and before SDL_SetVideoMode()
void HamurOpenGL::SetGLAttributes()
{
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);	// 5 is the minimum value 
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);	// openGL will try to set 
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);	// the maximum value for all
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);	// these attributes.
	//SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32); 
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // VERY IMPORTANT!!! MUST BE SET
	//SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16); // 16 or 24
}

} // namespace hamur
