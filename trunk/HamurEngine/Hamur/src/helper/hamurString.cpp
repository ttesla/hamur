#include "hamurString.h"
#include "../game/hamurObject.h"

namespace hamur
{
    HamurString& HamurString::operator<<(int input)
    {
        stringstream ss;
        ss << input;
        customString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(float input)
    {
        stringstream ss;
        ss << input;
        customString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(double input)
    {
        stringstream ss;
        ss << input;
        customString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(const string& input)
    {
        stringstream ss;
        ss << input;
        customString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(HamurObject& input)
    {
        stringstream ss;
        ss << input;
        customString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(HamurObject* input)
    {
        stringstream ss;
        ss << input;
        customString.append(ss.str());

        return *this;
    }

    HamurString HamurString::operator=(int input)
    {
        stringstream ss;
        ss << input;
        customString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(float input)
    {
        stringstream ss;
        ss << input;
        customString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(double input)
    {
        stringstream ss;
        ss << input;
        customString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(const string& input)
    {
        stringstream ss;
        ss << input;
        customString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(HamurObject& input)
    {
        stringstream ss;
        ss << input;
        customString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(HamurObject* input)
    {
        stringstream ss;
        ss << input;
        customString = ss.str();

        return *this;
    }

    string HamurString::getString()
    {
        return customString;
    }

    void HamurString::clear()
    {
        customString.clear();
    }

}
