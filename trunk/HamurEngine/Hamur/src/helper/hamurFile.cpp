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
    mOutputFile.close();
    mInputFile.close();
}

bool HamurFile::OpenForWrite(const string &_fileName)
{
    if(mOutputFile.is_open())
        mOutputFile.close();

    mOutputFile.open(_fileName.c_str(), ios::out);

    if(mOutputFile.is_open())
        return true;
    else
        return false;
}

bool HamurFile::OpenForAppend(const string &_fileName)
{
    if(mOutputFile.is_open())
        mOutputFile.close();

    mOutputFile.open(_fileName.c_str(), ios::out | ios::app);

    if(mOutputFile.is_open())
        return true;
    else
        return false;
}

bool HamurFile::OpenForRead(const string &_fileName)
{
    if(mInputFile.is_open())
        mInputFile.close();

    mInputFile.open(_fileName.c_str(), ios::in);

    if(mInputFile.is_open())
        return true;
    else
        return false;
}

void HamurFile::Close()
{
    if(mOutputFile.is_open()) mOutputFile.close();
    if(mInputFile.is_open())  mInputFile.close();
}

void HamurFile::Write(const string &input)
{
    mOutputFile << input;
}

void HamurFile::Write(int input)
{
    mOutputFile << input;
}

void HamurFile::Write(unsigned int input)
{
    mOutputFile << input;
}

void HamurFile::Write(char input)
{
    mOutputFile << input;
}

void HamurFile::Write(float input)
{
    mOutputFile << input;
}

void HamurFile::Write(double input)
{
    mOutputFile << input;
}

void HamurFile::Write(HamurObject &input)
{
    mOutputFile << input;
}

void HamurFile::Write(HamurObject *input)
{
    mOutputFile << input;
}

void HamurFile::Write(HamurString &input)
{
    mOutputFile << input;
}

int HamurFile::ReadInt()
{
    int temp;
    mInputFile >> temp;
    return temp;
}

float HamurFile::ReadFloat()
{
    float temp;
    mInputFile >> temp;
    return temp;
}

char HamurFile::ReadChar()
{
    char temp;
    mInputFile >> temp;
    return temp;
}

string HamurFile::ReadString()
{
    string temp;
    mInputFile >> temp;
    return temp;
}	
	
} // namespace hamur
