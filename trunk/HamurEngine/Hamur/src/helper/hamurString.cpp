#include "hamurString.h"
#include <iostream>

using std::cout;

namespace hamur
{
    HamurString& HamurString::operator<<(int input)
    {
        stringstream ss;
        ss << input;
        customString.append(ss.str());

        cout << "sonuc: " << customString;
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

    string HamurString::getString()
    {
        return customString;
    }

    void HamurString::clear()
    {
        customString.clear();
    }


}