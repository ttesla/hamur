#include "hamurLog.h"

namespace hamur
{

// HamurLog constructor
HamurLog::HamurLog() : mLogFileName("hamur.log") , mDebugMode(true)
{
    // Open for writing and append
    mLogFile.OpenForWrite(mLogFileName);
}


// HamurLog destructor
HamurLog::~HamurLog()
{
    mLogFile.Close();
}


// WITHOUT LN versions...

void HamurLog::WriteLog(const string &input, bool writeMode)
{
    if(mDebugMode || writeMode)
        mLogFile.Write(input);
}

void HamurLog::WriteLog(int input, bool writeMode)
{
    if(mDebugMode || writeMode)
        mLogFile.Write(input);
}

void HamurLog::WriteLog(unsigned int input, bool writeMode)
{
    if(mDebugMode || writeMode)
        mLogFile.Write(input);
}

void HamurLog::WriteLog(float input, bool writeMode)
{
    if(mDebugMode || writeMode)
        mLogFile.Write(input);
}

void HamurLog::WriteLog(double input, bool writeMode)
{
    if(mDebugMode || writeMode)
        mLogFile.Write(input);
}

void HamurLog::WriteLog(HamurObject &input, bool writeMode)
{
    if(mDebugMode || writeMode)
        mLogFile.Write(input);
}

void HamurLog::WriteLog(HamurObject *input, bool writeMode)
{
    if(mDebugMode || writeMode)
        mLogFile.Write(input);
}

void HamurLog::WriteLog(HamurString &input, bool writeMode)
{
    if(mDebugMode || writeMode)
        mLogFile.Write(input);
}

// LN versions... 

void HamurLog::WriteLogln(const string &input, bool writeMode)
{  
    if(mDebugMode || writeMode)
    {
        mLogFile.Write(input);
        mLogFile.Write("\n");
    }
}

void HamurLog::WriteLogln(int input, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
        mLogFile.Write(input);
        mLogFile.Write("\n");
    }
}

void HamurLog::WriteLogln(unsigned int input, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
        mLogFile.Write(input);
        mLogFile.Write("\n");
    }
}

void HamurLog::WriteLogln(float input, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
        mLogFile.Write(input);
        mLogFile.Write("\n");
    }
}

void HamurLog::WriteLogln(double input, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
        mLogFile.Write(input);
        mLogFile.Write("\n");
    }
}

void HamurLog::WriteLogln(HamurObject &input, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
        mLogFile.Write(input);
        mLogFile.Write("\n");
    }
}

void HamurLog::WriteLogln(HamurObject *input, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
        mLogFile.Write(input);
        mLogFile.Write("\n");
    }
}

void HamurLog::WriteLogln(HamurString &input, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
        mLogFile.Write(input);
        mLogFile.Write("\n");
    }
}


// Write initialization message text to log file
// Makes some adjustments for a nifty printout.
void HamurLog::WriteInitLog(string log, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
	    int dotsToAdd = 15 - log.length();

	    for(int i = 0; i < dotsToAdd; i++)
		    log.append(".");

	    log.append("OK!\n");
        mLogFile.Write(log);
    }
}


// Write termination message text to log file
// Same style as WriteInitLog()
void HamurLog::WriteTerminateLog(string log, bool writeMode)
{
    if(mDebugMode || writeMode)
    {
        int dotsToAdd = 15 - log.length();

        for(int i = 0; i < dotsToAdd; i++)
            log.append(".");

        log.append("terminated!\n");
        mLogFile.Write(log);
    }
}


void HamurLog::CloseLogFile()
{
    mLogFile.Close();
}


void HamurLog::ClearLogFile()
{
    mLogFile.Close();
    mLogFile.OpenForWrite(mLogFileName);
}


// Turn on-off debug mode
void HamurLog::SetDebugMode(bool _mode)
{
    mDebugMode = _mode;
}

} // namespace hamur
