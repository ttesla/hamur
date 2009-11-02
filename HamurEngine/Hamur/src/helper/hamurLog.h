#ifndef HAMURLOG_H
#define HAMURLOG_H

#include <iostream>
#include <fstream>
#include <string>

#include "../hamurSingleton.h"

using std::string;
using std::ofstream;
using std::ios;
using std::endl;

namespace hamur
{
    /**
     * Writes Logs to log file
     * Log is cleared at the start of each execution.
     */
	class HamurLog : public Singleton<HamurLog>
	{
		public:
			//static HamurLog* getInstance(); // Return HamurLog singleton object.
			HamurLog();
			~HamurLog();

			// Log write functions
			void write_log(const string &log);
            void write_log(int logValue);
            void write_log(float logValue);

			// Write initialization messages
			void write_init_log(string log);

		protected:
			

		private:
			string logFileName;
			ofstream logFile; // Log file where all the logs will be written
	};
}

#endif // HAMURLOG_H  