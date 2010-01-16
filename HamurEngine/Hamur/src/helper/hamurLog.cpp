#include "hamurLog.h"

namespace hamur
{
	// HamurLog constructor
	HamurLog::HamurLog() : logFileName("hamur.log")
	{
		// To clear out the log file.
		logFile.open(logFileName.c_str(), ios::out);
		logFile.close();

        // Open for writing and append
        logFile.open(logFileName.c_str(), ios::out | ios::app);
	}


	// HamurLog destructor
	HamurLog::~HamurLog()
	{
        logFile.close();
	}


	// Write given text to log file
	void HamurLog::write_log(const string &log)
	{	
		logFile << log << endl;
	}


    // Write given int value to log file
    void HamurLog::write_log(int logValue)
    {
        logFile << logValue << endl;
    }


    // Write given float value to log file
    void HamurLog::write_log(float logValue)
    {
        logFile << logValue << endl;
    }


	// Write initialization message text to log file
	// Makes some adjustments for a nifty printout.
	void HamurLog::writeInitLog(string log)
	{
		int dotsToAdd = 15 - log.length();

		for(int i = 0; i < dotsToAdd; i++)
			log.append(".");

		log.append("OK!");
	
		write_log(log);
	}


    void HamurLog::closeLogFile()
    {
        if(logFile.is_open())
            logFile.close();
    }


    void HamurLog::clearLogFile()
    {
        // To clear out the log file.
        logFile.open(logFileName.c_str(), ios::out);
        logFile.close();
    }
}
