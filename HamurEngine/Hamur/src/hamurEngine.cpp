#include "hamurEngine.h"
#include "hamurGL.h"
#include "helper/hamurLog.h"
#include "hamurEvent.h"
#include "hamurTexMR.h"
#include "hamurGP.h"
#include "hamurFont.h"
#include "audio/hamurAuMR.h"
#include "game/hamurWorld.h"
#include "hamurDefinitions.h"

namespace hamur
{
    HamurEngine::HamurEngine()
    {
        HAMURLOG->writeLogln("Initializing Hamur Engine...");
    }

    // Do all the cleanups here...
    HamurEngine::~HamurEngine()
    {
        HAMURGL->quit();
    }

    // Initializes Hamur engine with the given parameters...
    bool HamurEngine::init(const string& applicationName, int screenWidth, int screenHeight)
    {
        // Init Hamur subsystems...
        if(!HAMURGL->initSDL(applicationName, screenWidth, screenHeight, 32, SDL_OPENGL)) return false; // SDL
        if(!HAMURGL->initGL())          return false; // OpenGL
        if(!HAMURTEXMR->getInstance())  return false; // Texture Manager
        if(!HAMURAUMR->init())          return false; // Audio Manager
        //HAMURFONT->getInstance()      return false; // ----
        if(!HAMUREVENT->getInstance())  return false; // Event handler
        if(!HAMURGP->getInstance())     return false; // Gameplay
        if(!HAMURWORLD->getInstance())  return false; // Object manager - World

        HAMURLOG->writeInitLog("HamurEngine");
        HAMURLOG->writeLogln("");
        
        return true; // Initialization OK!
    }

    // Shows mouse cursor on window
    void HamurEngine::enableMouseCursor()
    {
        SDL_ShowCursor(SDL_ENABLE);
    }

    // Hides mouse cursor 
    void HamurEngine::disableMouseCursor()
    {
        SDL_ShowCursor(SDL_DISABLE);
    }
}
