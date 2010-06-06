#ifndef HAMURENGINE_H
#define HAMURENGINE_H

#include "hamurSingleton.h"

#include <string>

using std::string;

namespace hamur
{
    /**
    * HamurEngine controls the entire Hamur engine
    */
	class HamurEngine : public Singleton<HamurEngine>
	{
		public:
            friend Singleton<HamurEngine>;

            /** 
            * Initializes Hamur engine 
            * @param applicationName The text written in the window bar.
            * @param screenWidth Width of the application window
            * @param screenHeight Height of the application window
            * @return True if initialization is successful else return False.
            */
            bool init(const string& applicationName, int screenWidth, int screenHeight);

            /**< Runs Hamur engine, starts main loop */
            void run();

            /**
            * Stops Hamur engine, exits from main loop. 
            * @see terminate()
            */
            void stop();

            /**
            * Terminates Hamur Engine and deallocates memory consumed by all Managers.
            * It should be called to terminate the Hamur Engine entirely and quit the program.
            * @see stop()
            */
            void terminate();

            /**< Shows mouse cursor on window */
            void enableMouseCursor();
            
            /**< Hides mouse cursor */
            void disableMouseCursor();

		protected:

            /**< Constructor */
            HamurEngine();

            /**< Makes all possible remaining cleanups */
            ~HamurEngine();

        private:

            /**< Shows status of engine, running or not */
            bool runEngine;
           
	};
}

#endif //HAMURENGINE_H
