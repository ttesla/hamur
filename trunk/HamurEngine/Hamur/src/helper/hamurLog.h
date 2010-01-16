#ifndef HAMURLOG_H
#define HAMURLOG_H

#include "../hamurSingleton.h"

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::ios;
using std::endl;

namespace hamur
{
    /**
     * Writes Logs to log file.
     * Log is cleared at the start of each execution.
     */
	class HamurLog : public Singleton<HamurLog>
	{
		public:
			HamurLog();
			~HamurLog();

			void write_log(const string &log);
            void write_log(int logValue);
            void write_log(float logValue);

            void write_logln(const string &log);
            void write_logln(int logValue);
            void write_logln(float logValue);

			// Write initialization messages
			void writeInitLog(string log);

            void closeLogFile();
            void clearLogFile();

		protected:
			
		private:
			string logFileName;
			ofstream logFile; // Log file where all the logs will be written
	};
}

#endif // HAMURLOG_H  