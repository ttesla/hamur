#ifndef HAMUREVENT_H
#define HAMUREVENT_H

#include "SDL.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"
#include "hamurSingleton.h"

namespace hamur
{
	// Handles all events: Keyboard, Mouse and other events. 
	class HamurEvent : public Singleton<HamurEvent>
	{
		public:

			HamurEvent();
			~HamurEvent();

			//static HamurEvent* getInstance();  // Return HamurEvent singleton object.
			bool is_key_pressed(int keyName);  // Check given key is pressed or not.
			bool is_mouse_pressed(int button); // Check given mouse button pressed or not. 
			bool is_quit_performed();		   // If Quit action performed or not.
			int get_mouseX(); // Get X coordinate of mouse cursor
			int get_mouseY(); // Get Y coordinate of mouse cursor
			void handle_events(); // This is the main method of the class which handles events.

		protected:

		private:

			SDL_Event events; // SDL_Events are accessed from here.
			bool quit;		  // If Quit action is performed on the window frame. 
			int mouseX, mouseY;
	};
}

#endif // HAMUREVENT_H  