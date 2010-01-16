#include "hamurEvent.h"

namespace hamur
{
	// HamurEvent constructor
	HamurEvent::HamurEvent()
	{
		quit = false;
		HAMURLOG->writeInitLog("HamurEvent");
	}


	// HamurLog destructor
	HamurEvent::~HamurEvent()
	{

	}


	// Check keystate to see given key is pressed or not
	bool HamurEvent::isKeyPressed(int keyName)
	{
		if(SDL_GetKeyState(NULL)[keyName])
			return true; // given key is pressed
		
		else 
			return false; // given key is not pressed
	}


	// Check given mouse button pressed or not. 
	bool HamurEvent::isMousePressed(int button)
	{
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button))
			return true;
		
		else
			return false;
	}


    // If Quit action performed or not
    bool HamurEvent::isQuitPerformed()
    {
        return quit;
    }


	// Get X coordinate of mouse cursor
	int HamurEvent::getMouseX()
	{
		return mouseX;
	}


	// Get Y coordinate of mouse cursor
	int HamurEvent::getMouseY()
	{
		return mouseY;
	}


	// Handle all events within this method
	void HamurEvent::handleEvents()
	{
		//While there are events to handle
		while(SDL_PollEvent(&events))
		{   
			if(events.type == SDL_QUIT)
			{
                quit = true;
            }

			else if(events.type == SDL_MOUSEMOTION)
			{
				mouseX = events.motion.x;
				mouseY = events.motion.y;
			}
		}
	}
}
