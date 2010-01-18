#ifndef HAMURSTRING_H
#define HAMURSTRING_H

#include <sstream>
#include <string>

using std::stringstream;
using std::string;

namespace hamur
{
    class HamurString
    {
        public:

            HamurString& HamurString::operator<<(int input);
            HamurString& HamurString::operator<<(float input);
            HamurString& HamurString::operator<<(double input);
            HamurString& HamurString::operator<<(const string& input);

            HamurString HamurString::operator=(int input);
            HamurString HamurString::operator=(float input);
            HamurString HamurString::operator=(double input);
            HamurString HamurString::operator=(const string& input);

            string getString();
            void clear();

        private:

            string customString;
    };
}

#endif
