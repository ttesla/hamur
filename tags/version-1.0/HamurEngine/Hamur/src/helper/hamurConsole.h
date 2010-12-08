#ifndef HAMUR_CONSOLE_H
#define HAMUR_CONSOLE_H

#include <iostream>
#include <string>

#include "../game/hamurObject.h"
#include "hamurString.h"
#include "hamurVec2.h"
#include "hamurVec3.h"

using std::string;
using std::cout;
using std::endl;


namespace hamur
{

/**
 * Writes given text to console.
 * Used as a "cout" wrapper
 */
class HamurConsole
{
	public:

        // This can't use Singleton template because
        // some operator overloading makes some conflicts...
        static HamurConsole& GetInstance()
        {
            static HamurConsole hamurConsole;
            return hamurConsole;
        }

        HamurConsole& operator<<(int input);
        HamurConsole& operator<<(unsigned int input);
        HamurConsole& operator<<(float input);
        HamurConsole& operator<<(double input);
        HamurConsole& operator<<(char input);
        HamurConsole& operator<<(const string &input);
        HamurConsole& operator<<(HamurObject &input);
        HamurConsole& operator<<(HamurObject *input);
        HamurConsole& operator<<(HamurString &input);
        HamurConsole& operator<<(const HamurVec2 &input);
        HamurConsole& operator<<(const HamurVec3 &input);

        static string Endl();

	private:
        HamurConsole() {};
};

// Other Function Definitions //

inline HamurConsole& HamurConsole::operator<<(int input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(unsigned int input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(float input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(double input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(char input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(const string &input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(HamurObject &input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(HamurObject *input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(HamurString &input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(const HamurVec2 &input)
{
    cout << input;
    return *this;
}

inline HamurConsole& HamurConsole::operator<<(const HamurVec3 &input)
{
    cout << input;
    return *this;
}

inline string HamurConsole::Endl()
{
    string tempStr = "";
    cout << endl;
    return tempStr;
}

} // namespace hamur

#endif // HAMUR_CONSOLE_H
