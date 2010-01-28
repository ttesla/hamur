#ifndef HAMUR_CONSOLE_H
#define HAMUR_CONSOLE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


namespace hamur
{
    class HamurObject;
    class HamurString;

    /**
     * Writes given text to console. 
     * Used as a "cout" wrapper
     */
    class HamurConsole
	{
		public:
            
            static HamurConsole &HamurConsole::getInstance()
            {
                static HamurConsole hamurConsole;
                return hamurConsole;
            }

            HamurConsole operator<<(int input);
            HamurConsole operator<<(unsigned int input);
            HamurConsole operator<<(float input);
            HamurConsole operator<<(double input);
            HamurConsole operator<<(char input);
            HamurConsole operator<<(const string &input);
            HamurConsole operator<<(HamurObject &input);
            HamurConsole operator<<(HamurObject *input);
            HamurConsole operator<<(HamurString &input);
			
		private:
            HamurConsole() {};
	};
    
}

#endif // HAMUR_CONSOLE_H