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
            
            void writeLog(const string &input, bool writeMode = DEBUG_ONLY); 
            void writeLog(int input,           bool writeMode = DEBUG_ONLY);
            void writeLog(unsigned int input,  bool writeMode = DEBUG_ONLY); 
            void writeLog(float input,         bool writeMode = DEBUG_ONLY);
            void writeLog(double input,        bool writeMode = DEBUG_ONLY);
            void writeLog(HamurObject &input,  bool writeMode = DEBUG_ONLY);
            void writeLog(HamurObject *input,  bool writeMode = DEBUG_ONLY);
            void writeLog(HamurString &input,  bool writeMode = DEBUG_ONLY);

            void writeLogln(const string &input, bool writeMode = DEBUG_ONLY);
            void writeLogln(int input,           bool writeMode = DEBUG_ONLY);
            void writeLogln(unsigned int input,  bool writeMode = DEBUG_ONLY);
            void writeLogln(float input,         bool writeMode = DEBUG_ONLY);
            void writeLogln(double input,        bool writeMode = DEBUG_ONLY);
            void writeLogln(HamurObject &input,  bool writeMode = DEBUG_ONLY);
            void writeLogln(HamurObject *input,  bool writeMode = DEBUG_ONLY);
            void writeLogln(HamurString &input,  bool writeMode = DEBUG_ONLY);

			// Write initialization messages
			void writeInitLog(string log, bool writeMode = ALWAYS);

            // Write termination log
            void writeTerminateLog(string log, bool writeMode = ALWAYS);

            void closeLogFile();
            void clearLogFile();

            /**
            * Turn on-off debug mode.
            * If True passed, all massages will be written to log file,
            * If False passed, only messages with ALWAYS flag will be written.
            * @param mode True-False
            */
            void setDebugMode(bool mode);

            /**
            * Flag for function to write always, whether Debug mode on or off. 
            * Error logs should use this flag.
            */
            const static bool ALWAYS = true;

            /**< Flag for function to write in Debug mode only. */
            const static bool DEBUG_ONLY = false;

		protected:
			
		private:

            HamurFile logFile;
            const string logFileName;
            bool debugMode;
	};
    
}

#endif // HAMURLOG_H  
