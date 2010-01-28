#include "hamurLog.h"

namespace hamur
{
	// HamurLog constructor
    HamurLog::HamurLog() : logFileName("hamur.log")
	{
        // Open for writing and append
        logFile.openForWrite(logFileName);
	}


	// HamurLog destructor
	HamurLog::~HamurLog()
	{
        logFile.close();
	}


	// Write given text to log file
	void HamurLog::write_log(const string &log)
	{	
		logFile.write(log);
	}


    // Write given int value to log file
    void HamurLog::write_log(int log)
    {
        logFile.write(log);
    }


    // Write given float value to log file
    void HamurLog::write_log(float log)
    {
        logFile.write(log);
    }

    void HamurLog::writeLog(const string &input)
    {
        logFile.write(input);
    }

    void HamurLog::writeLog(int input)
    {
        logFile.write(input);
    }

    void HamurLog::writeLog(unsigned int input)
    {
        logFile.write(input);
    }

    void HamurLog::writeLog(float input)
    {
        logFile.write(input);
    }

    void HamurLog::writeLog(double input)
    {
        logFile.write(input);
    }

    void HamurLog::writeLog(HamurObject &input)
    {
        logFile.write(input);
    }

    void HamurLog::writeLog(HamurObject *input)
    {
        logFile.write(input);
    }

    void HamurLog::writeLog(HamurString &input)
    {
        logFile.write(input);
    }


    // LN versions... 

    void HamurLog::writeLogln(const string &input)
    {
        logFile.write(input);
        logFile.write("\n");
    }

    void HamurLog::writeLogln(int input)
    {
        logFile.write(input);
        logFile.write("\n");
    }

    void HamurLog::writeLogln(unsigned int input)
    {
        logFile.write(input);
        logFile.write("\n");
    }

    void HamurLog::writeLogln(float input)
    {
        logFile.write(input);
        logFile.write("\n");
    }

    void HamurLog::writeLogln(double input)
    {
        logFile.write(input);
        logFile.write("\n");
    }

    void HamurLog::writeLogln(HamurObject &input)
    {
        logFile.write(input);
        logFile.write("\n");
    }

    void HamurLog::writeLogln(HamurObject *input)
    {
        logFile.write(input);
        logFile.write("\n");
    }

    void HamurLog::writeLogln(HamurString &input)
    {
        logFile.write(input);
        logFile.write("\n");
    }


	// Write initialization message text to log file
	// Makes some adjustments for a nifty printout.
	void HamurLog::writeInitLog(string log)
	{
		int dotsToAdd = 15 - log.length();

		for(int i = 0; i < dotsToAdd; i++)
			log.append(".");

		log.append("OK!\n");
        logFile.write(log);
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
}
