#ifndef HAMURSTRING_H
#define HAMURSTRING_H

#include <sstream>
#include <string>

using std::stringstream;
using std::string;

namespace hamur
{
// Forward declarations
class HamurObject;
class HamurVec2;
class HamurVec3;

// TODO: Make Hamur string competable with + as well and join with Boost str
class HamurString
{
    public:
		static HamurString ParseInt(const int &value);


        HamurString& operator<<(int input);
        HamurString& operator<<(float input);
        HamurString& operator<<(double input);
        HamurString& operator<<(const string& input);
        HamurString& operator<<(HamurObject& input);
        HamurString& operator<<(HamurObject* input);
        HamurString& operator<<(const HamurVec2& input);
        HamurString& operator<<(const HamurVec3& input);

        HamurString operator=(int input);
        HamurString operator=(float input);
        HamurString operator=(double input);
        HamurString operator=(const string& input);
        HamurString operator=(HamurObject& input);
        HamurString operator=(HamurObject* input);
        HamurString operator=(const HamurVec2& input);
        HamurString operator=(const HamurVec3& input);

        string GetString();
        void Clear();

    private:
        string mCustomString;
};

/** Writes the HamurString to the stream */
inline std::ostream &operator<<(std::ostream &os, HamurString &str)
{
    os << str.GetString();
    return os;
}

} // namespace hamur

#endif // HAMURSTRING_H
