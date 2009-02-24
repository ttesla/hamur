#ifndef HAMURLOG_H
#define HAMURLOG_H

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::ios;
using std::endl;

namespace hamur
{
	// Writes Logs to log file...
	// Log is cleared at the start of each execution.
	class HamurLog
	{
		public:
			static HamurLog* getInstance(); // Return HamurLog singleton object.

			// Log write function
			void write_log(const string &log);

			// Write initialization messages
			void write_init_log(string log);

		protected:
			HamurLog();
			~HamurLog();

		private:
			string logFileName;
			ofstream logFile; // Log file where all the logs will be written
	};
}

#endif // HAMURLOG_H  