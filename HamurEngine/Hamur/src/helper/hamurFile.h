#ifndef HAMUR_FILE_H
#define HAMUR_FILE_H

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;


namespace hamur
{
    class HamurObject;
    class HamurString;

    /**
     * Handles file operations.
     * File writing and reading.
     * Can handle 1 file at a time.
     */
    class HamurFile
	{
		public:
            HamurFile();
			~HamurFile();

            bool openForWrite(const string &fileName);
            bool openForAppend(const string &fileName);
            bool openForRead(const string &fileName);
            void close();

            // Write functions
            void write(const string &input);
            void write(int input);
            void write(unsigned int input);
            void write(char input);  
            void write(float input);
            void write(double input);
            void write(HamurObject &input);
            void write(HamurObject *input);
            void write(HamurString &input);

            // Read functions
            int readInt();
            float readFloat();
            char readChar();
            string readString();


        private:
            ofstream outputFile; 
            ifstream inputFile;
	};
    
}

#endif // HAMUR_FILE_H 