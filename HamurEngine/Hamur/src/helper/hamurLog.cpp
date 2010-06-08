#include "hamurLog.h"

namespace hamur
{
	// HamurLog constructor
    HamurLog::HamurLog() : logFileName("hamur.log") , debugMode(true)
	{
        // Open for writing and append
        logFile.openForWrite(logFileName);
	}


	// HamurLog destructor
	HamurLog::~HamurLog()
	{
        logFile.close();
	}


    // WITHOUT LN versions...

    void HamurLog::writeLog(const string &input, bool writeMode)
    {
        if(debugMode || writeMode)
            logFile.write(input);
    }

    void HamurLog::writeLog(int input, bool writeMode)
    {
        if(debugMode || writeMode)
            logFile.write(input);
    }

    void HamurLog::writeLog(unsigned int input, bool writeMode)
    {
        if(debugMode || writeMode)
            logFile.write(input);
    }

    void HamurLog::writeLog(float input, bool writeMode)
    {
        if(debugMode || writeMode)
            logFile.write(input);
    }

    void HamurLog::writeLog(double input, bool writeMode)
    {
        if(debugMode || writeMode)
            logFile.write(input);
    }

    void HamurLog::writeLog(HamurObject &input, bool writeMode)
    {
        if(debugMode || writeMode)
            logFile.write(input);
    }

    void HamurLog::writeLog(HamurObject *input, bool writeMode)
    {
        if(debugMode || writeMode)
            logFile.write(input);
    }

    void HamurLog::writeLog(HamurString &input, bool writeMode)
    {
        if(debugMode || writeMode)
            logFile.write(input);
    }

    // LN versions... 

    void HamurLog::writeLogln(const string &input, bool writeMode)
    {  
        if(debugMode || writeMode)
        {
            logFile.write(input);
            logFile.write("\n");
        }
    }

    void HamurLog::writeLogln(int input, bool writeMode)
    {
        if(debugMode || writeMode)
        {
            logFile.write(input);
            logFile.write("\n");
        }
    }

    void HamurLog::writeLogln(unsigned int input, bool writeMode)
    {
        if(debugMode || writeMode)
        {
            logFile.write(input);
            logFile.write("\n");
        }
    }

    void HamurLog::writeLogln(float input, bool writeMode)
    {
        if(debugMode || writeMode)
        {
            logFile.write(input);
            logFile.write("\n");
        }
    }

    void HamurLog::writeLogln(double input, bool writeMode)
    {
        if(debugMode || writeMode)
        {
            logFile.write(input);
            logFile.write("\n");
        }
    }

    void HamurLog::writeLogln(HamurObject &input, bool writeMode)
    {
        if(debugMode || writeMode)
        {
            logFile.write(input);
            logFile.write("\n");
        }
    }

    void HamurLog::writeLogln(HamurObject *input, bool writeMode)
    {
        if(debugMode || writeMode)
        {
            logFile.write(input);
            logFile.write("\n");
        }
    }

    void HamurLog::writeLogln(HamurString &input, bool writeMode)
    {
        if(debugMode || writeMode)
        {
            logFile.write(input);
            logFile.write("\n");
        }
    }
    

	// Write initialization message text to log file
	// Makes some adjustments for a nifty printout.
	void HamurLog::writeInitLog(string log, bool writeMode)
	{
        if(debugMode || writeMode)
        {
		    int dotsToAdd = 15 - log.length();

		    for(int i = 0; i < dotsToAdd; i++)
			    log.append(".");

		    log.append("OK!\n");
            logFile.write(log);
        }
	}


    // Write termination message text to log file
    // Same style as writeInitLog()
    void HamurLog::writeTerminateLog(string log, bool writeMode)
    {
        if(debugMode || writeMode)
        {
            int dotsToAdd = 15 - log.length();

            for(int i = 0; i < dotsToAdd; i++)
                log.append(".");

            log.append("terminated!\n");
            logFile.write(log);
        }
    }


    void HamurLog::closeLogFile()
    {
        logFile.close();
    }


    void HamurLog::clearLogFile()
    {
        logFile.close();
        logFile.openForWrite(logFileName);
    }


    // Turn on-off debug mode
    void HamurLog::setDebugMode(bool _mode)
    {
        debugMode = _mode;
    }
}
