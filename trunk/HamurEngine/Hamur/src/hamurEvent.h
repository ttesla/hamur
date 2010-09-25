#ifndef HAMUREVENT_H
#define HAMUREVENT_H

#include "SDL.h"
#include "hamurSingleton.h"


namespace hamur
{

/**
* Hamur Event Manager.
* Singleton class that manages the event system.
*/
class HamurEvent : public Singleton<HamurEvent>
{
	public:

        friend class Singleton<HamurEvent>;

        /**
        * Initialize Hamur Event
        * @return True if initialization is successful, else return False
        */
        bool Init();

        /**
        * Checks if given key is pressed or not.
        * @param keyName Name of the key defined by SDL.
        * @return Given key is pressed or not.
        */
		bool IsKeyPressed(int keyName) const;

        /**
        * Checks if given mouse button is pressed or not.
        * @param button Name of the button defined by SDL.
        * @return Given button is pressed or not.
        */
		bool IsMousePressed(int button) const;

        /**
        * Checks if quit action performed or not.
        * @return Quit action performed or not.
        */
		bool IsQuitPerformed() const;

        /**
        * Gets the X coordinate of mouse cursor.
        * @return X coordinate of mouse cursor.
        */
		int GetMouseX() const;

        /**
        * Gets the Y coordinate of mouse cursor.
        * @return Y coordinate of mouse cursor.
        */
		int GetMouseY() const;

        /**
        * Main method that handles all events.
        */
		void HandleEvents();

	protected:

        HamurEvent();
        ~HamurEvent();

	private:

		SDL_Event mEvents; /**< SDL_Events are accessed from this handle. */
		bool mQuit;		  /**< If Quit action is performed on the window frame. */
		int mMouseX;       /**< X coordinate of the mouse. */
        int mMouseY;       /**< Y coordinate of the mouse. */
};

} // namespace hamur

#endif // HAMUREVENT_H
