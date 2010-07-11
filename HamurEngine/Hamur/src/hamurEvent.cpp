#include "hamurEvent.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"


namespace hamur
{

// HamurEvent constructor
HamurEvent::HamurEvent()
{
	
}


// HamurLog destructor
HamurEvent::~HamurEvent()
{
    HAMURLOG->writeTerminateLog("HamurEvent");
}


// Initialize Hamur Event
bool HamurEvent::Init()
{
    mQuit = false;
    HAMURLOG->writeInitLog("HamurEvent");
    return true;
}


// Check keystate to see given key is pressed or not
bool HamurEvent::IsKeyPressed(int keyName) const
{
	if(SDL_GetKeyState(NULL)[keyName])
		return true; // given key is pressed
	
	else 
		return false; // given key is not pressed
}


// Check given mouse button pressed or not. 
bool HamurEvent::IsMousePressed(int button) const
{
	if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button))
		return true;
	
	else
		return false;
}


// If Quit action performed or not
bool HamurEvent::IsQuitPerformed() const
{
    return mQuit;
}


// Get X coordinate of mouse cursor
int HamurEvent::GetMouseX() const
{
	return mMouseX;
}


// Get Y coordinate of mouse cursor
int HamurEvent::GetMouseY() const
{
	return mMouseY;
}


// Handle all events within this method
void HamurEvent::HandleEvents()
{
	//While there are events to handle
	while(SDL_PollEvent(&mEvents))
	{   
		if(mEvents.type == SDL_QUIT)
		{
            mQuit = true;
        }

		else if(mEvents.type == SDL_MOUSEMOTION)
		{
			mMouseX = mEvents.motion.x;
			mMouseY = mEvents.motion.y;
		}
	}
}

}// namespace hamur
