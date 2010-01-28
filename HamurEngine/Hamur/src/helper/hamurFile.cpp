#include "hamurFile.h"
#include "hamurString.h"
#include "../game/hamurObject.h"


namespace hamur
{
    HamurFile::HamurFile() 
    {
        // Default cons.
    }

    HamurFile::~HamurFile() 
    {
        outputFile.close();
        inputFile.close();
    }

    bool HamurFile::openForWrite(const string &_fileName)
    {
        if(outputFile.is_open())
            outputFile.close();

        outputFile.open(_fileName.c_str(), ios::out);

        if(outputFile.is_open())
            return true;
        else
            return false;
    }

    bool HamurFile::openForAppend(const string &_fileName)
    {
        if(outputFile.is_open())
            outputFile.close();

        outputFile.open(_fileName.c_str(), ios::out | ios::app);

        if(outputFile.is_open())
            return true;
        else
            return false;
    }

    bool HamurFile::openForRead(const string &_fileName)
    {
        if(inputFile.is_open())
            inputFile.close();

        inputFile.open(_fileName.c_str(), ios::in);

        if(inputFile.is_open())
            return true;
        else
            return false;
    }

    void HamurFile::close()
    {
        if(outputFile.is_open()) outputFile.close();
        if(inputFile.is_open())  inputFile.close();
    }

    void HamurFile::write(const string &input)
    {
        outputFile << input;
    }

    void HamurFile::write(int input)
    {
        outputFile << input;
    }

    void HamurFile::write(unsigned int input)
    {
        outputFile << input;
    }

    void HamurFile::write(char input)
    {
        outputFile << input;
    }

    void HamurFile::write(float input)
    {
        outputFile << input;
    }

    void HamurFile::write(double input)
    {
        outputFile << input;
    }

    void HamurFile::write(HamurObject &input)
    {
        outputFile << input;
    }

    void HamurFile::write(HamurObject *input)
    {
        outputFile << input;
    }

    void HamurFile::write(HamurString &input)
    {
        outputFile << input;
    }

    int HamurFile::readInt()
    {
        int temp;
        inputFile >> temp;
        return temp;
    }

    float HamurFile::readFloat()
    {
        float temp;
        inputFile >> temp;
        return temp;
    }

    char HamurFile::readChar()
    {
        char temp;
        inputFile >> temp;
        return temp;
    }

    string HamurFile::readString()
    {
        string temp;
        inputFile >> temp;
        return temp;
    }	
	
}
