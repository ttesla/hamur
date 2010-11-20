#include "hamurEvent.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"
#include "helper/hamurConsole.h"


namespace hamur
{

// HamurEvent constructor
HamurEvent::HamurEvent()
{
	
}


// HamurLog destructor
HamurEvent::~HamurEvent()
{
    HAMURLOG->WriteTerminateLog("HamurEvent");
}


// Initialize Hamur Event
bool HamurEvent::Init()
{
    mQuit = false;
    mKeyPressed = -1;
	mMousePressed = -1;
    HAMURLOG->WriteInitLog("HamurEvent");
    return true;
}


// Check keyState to see given key is down or not
bool HamurEvent::IsKeyDown(Keys::Keyboard keyState) const
{
	if(SDL_GetKeyState(NULL)[keyState])
		return true; // given key is down
	else 
		return false; // given key is not down
}

// Check keyState to see given key is pressed or not
bool HamurEvent::IsKeyPressed(Keys::Keyboard keyState) 
{
    if(mKeyPressed == keyState)
        return true; // given key is pressed

    else 
        return false; // given key is not pressed
}

bool HamurEvent::IsMousePressed(Keys::Mouse mouseState)
{
    if(mMousePressed == mouseState)
        return true; // given button is pressed
    else 
        return false; // given button is not pressed
}


// Check given mouse button pressed or not. 
bool HamurEvent::IsMouseDown(Keys::Mouse mouseState) const
{
	if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(mouseState))
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

        else if(mEvents.type == SDL_KEYDOWN)
        {
            mKeyPressed = mEvents.key.keysym.sym;
        }

        else if(mEvents.type == SDL_MOUSEBUTTONDOWN)
        {
            mMousePressed = mEvents.button.button;
        }
	}
}


// Clear all events and set them to their original state
void HamurEvent::ClearEvents()
{
    mKeyPressed = -1;
    mMousePressed = -1;
}

} // namespace hamur
