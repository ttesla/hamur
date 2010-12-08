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

// Forward declerations
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

        bool OpenForWrite(const string &fileName);
        bool OpenForAppend(const string &fileName);
        bool OpenForRead(const string &fileName);
        void Close();

        // Write functions
        void Write(const string &input);
        void Write(int input);
        void Write(unsigned int input);
        void Write(char input);  
        void Write(float input);
        void Write(double input);
        void Write(HamurObject &input);
        void Write(HamurObject *input);
        void Write(HamurString &input);

        // Read functions
        int ReadInt();
        float ReadFloat();
        char ReadChar();
        string ReadString();

    private:

        ofstream mOutputFile; 
        ifstream mInputFile;
}; 
    
} // namespace hamur

#endif // HAMUR_FILE_H 