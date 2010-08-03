#include "hamurString.h"
#include "../game/hamurObject.h"

namespace hamur
{
    HamurString& HamurString::operator<<(int input)
    {
        stringstream ss;
        ss << input;
        mCustomString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(float input)
    {
        stringstream ss;
        ss << input;
        mCustomString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(double input)
    {
        stringstream ss;
        ss << input;
        mCustomString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(const string& input)
    {
        stringstream ss;
        ss << input;
        mCustomString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(HamurObject& input)
    {
        stringstream ss;
        ss << input;
        mCustomString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(HamurObject* input)
    {
        stringstream ss;
        ss << input;
        mCustomString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(const HamurVec2& input)
    {
        stringstream ss;
        ss << input;
        mCustomString.append(ss.str());

        return *this;
    }

    HamurString& HamurString::operator<<(const HamurVec3& input)
    {
        stringstream ss;
        ss << input;
        mCustomString.append(ss.str());

        return *this;
    }

    HamurString HamurString::operator=(int input)
    {
        stringstream ss;
        ss << input;
        mCustomString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(float input)
    {
        stringstream ss;
        ss << input;
        mCustomString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(double input)
    {
        stringstream ss;
        ss << input;
        mCustomString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(const string& input)
    {
        stringstream ss;
        ss << input;
        mCustomString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(HamurObject& input)
    {
        stringstream ss;
        ss << input;
        mCustomString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(HamurObject* input)
    {
        stringstream ss;
        ss << input;
        mCustomString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(const HamurVec2& input)
    {
        stringstream ss;
        ss << input;
        mCustomString = ss.str();

        return *this;
    }

    HamurString HamurString::operator=(const HamurVec3& input)
    {
        stringstream ss;
        ss << input;
        mCustomString = ss.str();

        return *this;
    }

    string HamurString::GetString()
    {
        return mCustomString;
    }

    void HamurString::Clear()
    {
        mCustomString.clear();
    }

}
