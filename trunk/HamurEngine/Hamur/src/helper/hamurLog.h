#ifndef HAMURLOG_H
#define HAMURLOG_H

#include "../hamurSingleton.h"
#include "hamurFile.h"

#include <iostream>
#include <string>


using std::string;



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


			// Write initialization messages
			void writeInitLog(string log);

            void closeLogFile();
            void clearLogFile();

		protected:
			
		private:
            HamurFile logFile;
	};
    
}

#endif // HAMURLOG_H  