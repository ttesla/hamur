#ifndef HAMUREVENT_H
#define HAMUREVENT_H

#include "SDL.h"
#include "hamurSingleton.h"


namespace hamur
{
    // This is a nested namespace because of C++ :)
    namespace Keys
    {
        enum Keyboard
        {
            Unknown		    = 0,
            First		    = 0,
            BackSpace		= 8,
            Tab		        = 9,
            Clear		    = 12,
            Return		    = 13,
            Pause		    = 19,
            Escape		    = 27,
            Space		    = 32,
            Exclaim		    = 33,
            Quotedbl		= 34,
            Hash		    = 35,
            Dollar		    = 36,
            Ampersand		= 38,
            Quate		    = 39,
            LeftParen		= 40,
            RightParen		= 41,
            Asterisk		= 42,
            Plus		    = 43,
            Comma		    = 44,
            Minus		    = 45,
            Period		    = 46,
            Slash		    = 47,
            Key0			= 48,
            Key1			= 49,
            Key2			= 50,
            Key3			= 51,
            Key4			= 52,
            Key5			= 53,
            Key6			= 54,
            Key7			= 55,
            Key8			= 56,
            Key9			= 57,
            Colon		    = 58,
            SemiColon		= 59,
            Less		    = 60,
            Equals		    = 61,
            Greater		    = 62,
            Question		= 63,
            At			    = 64,
            LeftBracket	    = 91,
            BackSlash		= 92,
            RightBracket	= 93,
            Caret		    = 94,
            UnderScore		= 95,
            BackQuate		= 96,
            KeyA			= 97,
            KeyB			= 98,
            KeyC			= 99,
            KeyD			= 100,
            KeyE			= 101,
            KeyF			= 102,
            KeyG			= 103,
            KeyH			= 104,
            KeyI			= 105,
            KeyJ			= 106,
            KeyK			= 107,
            KeyL			= 108,
            KeyM			= 109,
            KeyN			= 110,
            KeyO			= 111,
            KeyP			= 112,
            KeyQ			= 113,
            KeyR			= 114,
            KeyS			= 115,
            KeyT			= 116,
            KeyU			= 117,
            KeyV			= 118,
            KeyW			= 119,
            KeyX			= 120,
            KeyY			= 121,
            KeyZ			= 122,
            Delete		    = 127,
            NumPad0		    = 256,
            NumPad1		    = 257,
            NumPad2		    = 258,
            NumPad3		    = 259,
            NumPad4		    = 260,
            NumPad5		    = 261,
            NumPad6		    = 262,
            NumPad7		    = 263,
            NumPad8		    = 264,
            NumPad9		    = 265,
            NumPadPeriod    = 266,
            NumPadDivide	= 267,
            NumPadMultiply  = 268,
            NumPadMinus     = 269,
            NumPadPlus	    = 270,
            NumPadEnter	    = 271,
            NumPadEquals	= 272,
            Up			    = 273,
            Down		    = 274,
            Right		    = 275,
            Left		    = 276,
            Insert		    = 277,
            Home		    = 278,
            End		        = 279,
            PageUp		    = 280,
            PageDown		= 281,
            F1			    = 282,
            F2			    = 283,
            F3			    = 284,
            F4			    = 285,
            F5			    = 286,
            F6			    = 287,
            F7			    = 288,
            F8			    = 289,
            F9			    = 290,
            F10		        = 291,
            F11		        = 292,
            F12		        = 293,
            F13		        = 294,
            F14		        = 295,
            F15		        = 296,
            NumLock		    = 300,
            CapsLock		= 301,
            ScrollLock		= 302,
            RightShift		= 303,
            LeftShift		= 304,
            RightControl    = 305,
            LeftControl		= 306,
            RightAlt		= 307,
            LeftAlt		    = 308,
            RightMeta		= 309,
            LeftMeta		= 310,
            LeftWindows		= 311,		/* Left "Windows" key */
            RightWindows	= 312,		/* Right "Windows" key */
            Mode		    = 313,		/* "Alt Gr" key */
            Compose		    = 314,
            Help		    = 315,
            Print		    = 316,
            SysReq		    = 317,
            Break		    = 318,
            Menu		    = 319,
            Power		    = 320,		/* Power Macintosh power key */
            Euro		    = 321,		/* Some european keyboards */
            Undo		    = 322,		/* Atari keyboard has Undo */

        };

        enum Mouse
        {
            LeftButton	    =	1,
            MiddleButton    =	2,
            RightButton	    =   3,
            WheelUp	        =   4,
            WheelDown	    =   5,
            X1Button	    =	6,
            X2Button	    =	7,
        };
    }


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
        * Checks if given key is currently down or not.
        * @param keyState Name of the key defined by Keyboard.
        * @return Given key is down or not.
        */
		bool IsKeyDown(Keys::Keyboard keyState) const;

        /**
        * Checks if given key is currently pressed or not.
        * @param keyState Name of the key defined by Keyboard.
        * @return Given key is pressed or not.
        */
        bool IsKeyPressed(Keys::Keyboard keyState);

        /**
        * Checks if given mouse button is currently down or not.
        * @param mouseState Name of the button defined by Mouse.
        * @return Given button is down or not.
        */
		bool IsMouseDown(Keys::Mouse mouseState) const;

        /**
        * Checks if given mouse button is currently pressed or not.
        * @param mouseState Name of the button defined by Mouse.
        * @return Given button is pressed or not.
        */
		bool IsMousePressed(Keys::Mouse mouseState);

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

		/**
		* Clears all events, set them to initial states
		*/
		void ClearEvents();


	protected:

        HamurEvent();
        ~HamurEvent();

	private:

		SDL_Event mEvents; /**< SDL_Events are accessed from this handle. */
		bool mQuit;		  /**< If Quit action is performed on the window frame. */
		int mMouseX;       /**< X coordinate of the mouse. */
        int mMouseY;       /**< Y coordinate of the mouse. */

        int mKeyPressed;    /**< Keycode of the pressed key */
        int mMousePressed;  /**< Mousecode of the pressed button */
};

} // namespace hamur

#endif // HAMUREVENT_H
