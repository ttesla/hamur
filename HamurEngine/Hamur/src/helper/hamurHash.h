#ifndef HAMUR_HASH_H
#define HAMUR_HASH_H

#include <string>

using std::string;


namespace hamur
{
	/** Hamur hash number generator class (string to integer). */
	class HamurHash
	{
	    public:

            static unsigned int hashFunction(const string& str)
            {
                unsigned int hash = 5381;
                int c;

                for(unsigned int i = 0; i < str.length(); i++)
                {
                    c = str[i];
                    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
                }

                return hash;
            }
	};

}

#endif // HAMUR_HASH_H
