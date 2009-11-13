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

			void writeLog(const string &log);
            void writeLog(int logValue);
            void writeLog(float logValue);

            void writeLogln(const string &log);
            void writeLogln(int logValue);
            void writeLogln(float logValue);

			// Write initialization messages
			void writeInitLog(string log);

		protected:
			
		private:
			string logFileName;
			ofstream logFile; // Log file where all the logs will be written
	};
}

#endif // HAMURLOG_H  