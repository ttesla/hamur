#ifndef HAMURLOG_H
#define HAMURLOG_H

#include "../hamurSingleton.h"
#include "hamurFile.h"

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

            void writeLog(const string &input);
            void writeLog(int input);
            void writeLog(unsigned int input); 
            void writeLog(float input);
            void writeLog(double input);
            void writeLog(HamurObject &input);
            void writeLog(HamurObject *input);
            void writeLog(HamurString &input);

            void writeLogln(const string &input);
            void writeLogln(int input);
            void writeLogln(unsigned int input);
            void writeLogln(float input);
            void writeLogln(double input);
            void writeLogln(HamurObject &input);
            void writeLogln(HamurObject *input);
            void writeLogln(HamurString &input);

			// Write initialization messages
			void writeInitLog(string log);

            void closeLogFile();
            void clearLogFile();

		protected:
			
		private:

            HamurFile logFile;
            const string logFileName;
	};
    
}

#endif // HAMURLOG_H  