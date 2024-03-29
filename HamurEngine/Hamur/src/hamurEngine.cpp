#include "hamurEngine.h"
#include "hamurOpenGL.h"
#include "hamurEvent.h"
#include "hamurTextureManager.h"
#include "hamurGP.h"
#include "hamurFont.h"
#include "hamurTimer.h"

#include "helper/hamurConsole.h"
#include "helper/hamurLog.h"
#include "audio/hamurAudioManager.h"
#include "game/hamurWorld.h"
#include "game/hamurStateManager.h"
#include "game/hamurState.h"

#include "hamurDefinitions.h"


namespace hamur
{

HamurEngine::HamurEngine()
{

}


// Do all remaining cleanups here...
HamurEngine::~HamurEngine()
{
    // Add remaining cleaups here...
    HAMURLOG->WriteTerminateLog("HamurEngine");
}


// Initializes Hamur engine with the given parameters...
bool HamurEngine::Init(const string& applicationName, int screenWidth, int screenHeight)
{
    HAMURLOG->WriteLogln("Initializing Hamur Engine...", HamurLog::ALWAYS);

    // Init Hamur subsystems...
    if(!HAMURGL->InitSDL(applicationName, screenWidth, screenHeight, 32, SDL_OPENGL)) return false; // SDL
    if(!HAMURGL->InitGL())      return false; // OpenGL
    if(!HAMURTEXMR->Init())     return false; // Texture Manager
    if(!HAMURAUMR->Init())      return false; // Audio Manager
    if(!HAMURSTATEMR->Init())   return false; // State Manager
    if(!HAMURWORLD->Init())     return false; // Object manager - World
    if(!HAMUREVENT->Init())     return false; // Event handler
    if(!HAMURTIMER->Init())     return false; // Timer handler

    // Reset frame count
    mFrameCount = 0;

    HAMURLOG->WriteInitLog("HamurEngine");
    HAMURLOG->WriteLogln("", HamurLog::ALWAYS);
    
    return true; // Initialization OK!
}


// Core of the engine
void HamurEngine::Run()
{
    mRunEngine = true;

    while(mRunEngine)
    {
        float frameStartTime = HAMURTIMER->GetTimeInSeconds();
        float deltaTime = HAMURTIMER->DeltaTime();

        // Handle all events
        HAMUREVENT->HandleEvents();

        //Clear the screen & reset identity matrix
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0, 0, -1.0f); 
        
        // State Update & Draw
        HAMURSTATEMR->GetCurrentState()->Update(deltaTime); 
        HAMURSTATEMR->GetCurrentState()->Draw(deltaTime);

        // Check if game window closed by user
        if(HAMUREVENT->IsQuitPerformed()) 
            mRunEngine = false;

        //Update screen
        SDL_GL_SwapBuffers();

		// Clear all unused events
		HAMUREVENT->ClearEvents();

        // Increase frame count & Set delta time
        mFrameCount++;
        HAMURTIMER->SetDeltaTime(HAMURTIMER->GetTimeInSeconds() - frameStartTime);
    }
}


// Stop Hamur engine, quit main loop
void HamurEngine::Stop()
{
    mRunEngine = false;
}


// Delete all objects in all Hamur managers... 
void HamurEngine::Terminate()
{
    HAMURLOG->WriteLogln("\nTerminating Hamur Engine...", HamurLog::ALWAYS);

    mRunEngine = false;

    // The termination order is important !!!
    HAMURTEXMR->Drop();
    HAMURAUMR->Drop();
    HAMURWORLD->Drop();
    HAMURSTATEMR->Drop();
    HAMUREVENT->Drop();
    HAMURGL->Drop();
    HAMURENGINE->Drop();
    HAMURLOG->Drop();
}


// Shows mouse cursor on window
void HamurEngine::EnableMouseCursor()
{
    SDL_ShowCursor(SDL_ENABLE);
}


// Hides mouse cursor 
void HamurEngine::DisableMouseCursor()
{
    SDL_ShowCursor(SDL_DISABLE);
}


// Get Engine Frame count
int HamurEngine::GetFrameCount()
{
    return mFrameCount;
}

void HamurEngine::SetBackgroundColor(HamurColor backgroundColor)
{
	glClearColor(backgroundColor.R, backgroundColor.G, backgroundColor.B, 0);
}

} // namespace hamur
