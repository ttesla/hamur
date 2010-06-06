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
            */
            bool init(const string& applicationName, int screenWidth, int screenHeight);

            /**< Shows mouse cursor on window */
            void enableMouseCursor();
            
            /**< Hides mouse cursor */
            void disableMouseCursor();

		protected:

            /**< Constructor */
            HamurEngine();

            /**< Makes all possible cleanups */
            ~HamurEngine();

        private:
           
	};
}

#endif //HAMURENGINE_H
