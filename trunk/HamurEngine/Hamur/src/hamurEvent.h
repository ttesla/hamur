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

            friend Singleton<HamurEvent>;

            /**
            * Initialize Hamur Event
            * @return True if initialization is successfull, else return False
            */
            bool init();
			
            /**
            * Checks if given key is pressed or not.
            * @param keyName Name of the key defined by SDL.
            * @return Given key is pressed or not.
            */
			bool isKeyPressed(int keyName);

            /**
            * Checks if given mouse button is pressed or not.
            * @param button Name of the button defined by SDL.
            * @return Given button is pressed or not.
            */
			bool isMousePressed(int button); // Check given mouse button pressed or not. 

            /**
            * Checks if quit action performed or not.
            * @return Quit action performed or not.
            */
			bool isQuitPerformed();

            /**
            * Gets the X coordinate of mouse cursor.
            * @return X coordinate of mouse cursor.
            */
			int getMouseX();

            /**
            * Gets the Y coordinate of mouse cursor.
            * @return Y coordinate of mouse cursor.
            */
			int getMouseY();

            /**
            * Main method that handles all events.
            */
			void handleEvents();

		protected:

            HamurEvent();
            ~HamurEvent();

		private:

			SDL_Event events; /**< SDL_Events are accessed from this handle. */
			bool quit;		  /**< If Quit action is performed on the window frame. */
			int mouseX;       /**< X coordinate of the mouse. */
            int mouseY;       /**< Y coordinate of the mouse. */
	};
}

#endif // HAMUREVENT_H