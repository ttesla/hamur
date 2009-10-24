#include "hamurLog.h"

namespace hamur
{
	// HamurLog constructor
	HamurLog::HamurLog() : logFileName("hamur.log")
	{
		// To clear out the log file.
		logFile.open(logFileName.c_str(), ios::out);
		logFile.close();
	}


	// HamurLog destructor
	HamurLog::~HamurLog()
	{

	}
	

	
	// Return HamurLog singleton object
	/*
	HamurLog* HamurLog::getInstance()
	{
		static HamurLog instance;
		return &instance;
	}
	*/


	// Write given text to log file
	void HamurLog::write_log(const string &log)
	{
		// Append the text at the end of the file
		logFile.open(logFileName.c_str(), ios::out | ios::app);
		logFile << log << endl;
		logFile.close();
	}

	
	// Write initialization message text to log file
	// Makes some adjustments for a nifty printout.
	void HamurLog::write_init_log(string log)
	{
		int dotsToAdd = 15 - log.length();

		for(int i = 0; i < dotsToAdd; i++)
			log.append(".");

		log.append("OK!");
	
		write_log(log);
	}
}
