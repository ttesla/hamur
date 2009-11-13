#ifndef HAMUREVENT_H
#define HAMUREVENT_H

#include "helper/hamurLog.h"
#include "hamurDefinitions.h"
#include "hamurSingleton.h"

#include "SDL.h"

namespace hamur
{
    /**
    * Hamur Event Manager.
    * Singleton class that manages the event system.
    */ 
	class HamurEvent : public Singleton<HamurEvent>
	{
		public:
			HamurEvent();
			~HamurEvent();

            /**
            * Checks if given key is pressed or not.
            * @param keyName Name of the key defined by SDL.
            * @return Given key is pressed or not.
            */
			bool is_key_pressed(int keyName);

            /**
            * Checks if given mouse button is pressed or not.
            * @param button Name of the button defined by SDL.
            * @return Given button is pressed or not.
            */
			bool is_mouse_pressed(int button); // Check given mouse button pressed or not. 

            /**
            * Checks if quit action performed or not.
            * @return Quit action performed or not.
            */
			bool is_quit_performed();

            /**
            * Gets the X coordinate of mouse cursor.
            * @return X coordinate of mouse cursor.
            */
			int get_mouseX();

            /**
            * Gets the Y coordinate of mouse cursor.
            * @return Y coordinate of mouse cursor.
            */
			int get_mouseY();

            /**
            * Main method that handles all events.
            */
			void handle_events();

		protected:

		private:

			SDL_Event events; /**< SDL_Events are accessed from this handle. */
			bool quit;		  /**< If Quit action is performed on the window frame. */
			int mouseX;       /**< X coordinate of the mouse. */
            int mouseY;       /**< Y coordinate of the mouse. */
	};
}

#endif // HAMUREVENT_H
