#include "hamurConsole.h"
#include "../game/hamurObject.h"
#include "hamurString.h"


namespace hamur
{
    HamurConsole HamurConsole::operator<<(int input)
    {
        cout << input;
        return *this;
    }

    HamurConsole HamurConsole::operator<<(unsigned int input)
    {
        cout << input;
        return *this;
    }

    HamurConsole HamurConsole::operator<<(float input)
    {
        cout << input;
        return *this;
    } 

    HamurConsole HamurConsole::operator<<(double input)
    {
        cout << input;
        return *this;
    } 

    HamurConsole HamurConsole::operator<<(char input)
    {
        cout << input;
        return *this;
    } 

    HamurConsole HamurConsole::operator<<(const string &input)
    {
        cout << input;
        return *this;
    } 

    HamurConsole HamurConsole::operator<<(HamurObject &input)
    {
        cout << input;
        return *this;
    }

    HamurConsole HamurConsole::operator<<(HamurObject *input)
    {
        cout << input;
        return *this;
    }

    HamurConsole HamurConsole::operator<<(HamurString &input)
    {
        cout << input;
        return *this;
    }

    HamurConsole HamurConsole::operator<<(const HamurVec2 &input)
    {
        cout << input;
        return *this;
    }

    HamurConsole HamurConsole::operator<<(const HamurVec3 &input)
    {
        cout << input;
        return *this;
    }

}
