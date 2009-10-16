#include "hamurEvent.h"

namespace hamur
{
	// HamurEvent constructor
	HamurEvent::HamurEvent()
	{
		quit = false;
		HAMURLOG->write_init_log("HamurEvent");
	}


	// HamurLog destructor
	HamurEvent::~HamurEvent()
	{
		//delete keystate;
	}

	
	// Return HamurEvent singleton object
	/*
	HamurEvent* HamurEvent::getInstance()
	{
		static HamurEvent instance;
		return &instance;
	}
	*/


	// Check keystate to see given key is pressed or not
	bool HamurEvent::is_key_pressed(int keyName)
	{
		if(SDL_GetKeyState(NULL)[keyName])
			return true; // given key is pressed
		
		else 
			return false; // given key is not pressed
	}


	// Check given mouse button pressed or not. 
	bool HamurEvent::is_mouse_pressed(int button)
	{
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button))
			return true;
		
		else
			return false;
	}


	// Get X coordinate of mouse cursor
	int HamurEvent::get_mouseX()
	{
		return mouseX;
	}


	// Get Y coordinate of mouse cursor
	int HamurEvent::get_mouseY()
	{
		return mouseY;
	}


	// If Quit action performed or not
	bool HamurEvent::is_quit_performed()
	{
		return quit;
	}


	// Handle all events within this method
	void HamurEvent::handle_events()
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
