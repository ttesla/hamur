#ifndef HAMURSTRING_H
#define HAMURSTRING_H

#include <sstream>
#include <string>

using std::stringstream;
using std::string;

namespace hamur
{
    // Forward declaration
    class HamurObject;
    class HamurVec2;
    class HamurVec3;

    class HamurString
    {
        public:

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

            string getString();
            void clear();

        private:

            string customString;
    };

    /** Writes the HamurString to the stream */
    inline std::ostream &operator<<(std::ostream &os, HamurString &str)
    {
        os << str.getString();
        return os;
    }
}

#endif
