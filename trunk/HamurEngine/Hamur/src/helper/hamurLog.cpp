#include "hamurLog.h"

namespace hamur
{
	// HamurLog constructor
	HamurLog::HamurLog()
	{
        // Open for writing and append
        logFile.openForWrite("hamur.log");
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
       //logFile.clearFile();
       // TODO: fix here
    }
}
