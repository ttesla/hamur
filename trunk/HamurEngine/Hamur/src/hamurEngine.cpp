#include "hamurEngine.h"
#include "hamurGL.h"
#include "hamurEvent.h"
#include "hamurTexMR.h"
#include "hamurGP.h"
#include "hamurFont.h"
#include "audio/hamurAuMR.h"
#include "game/hamurWorld.h"
#include "game/hamurStateMR.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"

namespace hamur
{
    HamurEngine::HamurEngine()
    {
        HAMURLOG->writeLogln("Initializing Hamur Engine...");
    }


    // Do all remaining cleanups here...
    HamurEngine::~HamurEngine()
    {
        // TODO: Add remaining cleaups here...
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


    // Core of the engine
    void HamurEngine::run()
    {
        runEngine = true;

        while(runEngine)
        {
            // Handle all events
            HAMUREVENT->handleEvents();

            //Clear the screen & reset identity matrix
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();

            // Run state machine
            HAMURSTATEMR->getCurrentState()->update();
            HAMURSTATEMR->getCurrentState()->draw();

            // Check if game window closed by user
            if(HAMUREVENT->isQuitPerformed()) 
                runEngine = false;

            //Update screen
            SDL_GL_SwapBuffers();   
        }
    }


    // Stop Hamur engine, quit main loop
    void HamurEngine::stop()
    {
        runEngine = false;
    }


    // Delete all objects in all Hamur managers... 
    void HamurEngine::terminate()
    {
        runEngine = false;

        // TODO: Add "clean" method to all managers
        HAMURGL->quit();
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
