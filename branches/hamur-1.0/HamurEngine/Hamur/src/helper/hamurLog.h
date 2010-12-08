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
        
        void WriteLog(const string &input, bool writeMode = DEBUG); 
        void WriteLog(int input,           bool writeMode = DEBUG);
        void WriteLog(unsigned int input,  bool writeMode = DEBUG); 
        void WriteLog(float input,         bool writeMode = DEBUG);
        void WriteLog(double input,        bool writeMode = DEBUG);
        void WriteLog(HamurObject &input,  bool writeMode = DEBUG);
        void WriteLog(HamurObject *input,  bool writeMode = DEBUG);
        void WriteLog(HamurString &input,  bool writeMode = DEBUG);

        void WriteLogln(const string &input, bool writeMode = DEBUG);
        void WriteLogln(int input,           bool writeMode = DEBUG);
        void WriteLogln(unsigned int input,  bool writeMode = DEBUG);
        void WriteLogln(float input,         bool writeMode = DEBUG);
        void WriteLogln(double input,        bool writeMode = DEBUG);
        void WriteLogln(HamurObject &input,  bool writeMode = DEBUG);
        void WriteLogln(HamurObject *input,  bool writeMode = DEBUG);
        void WriteLogln(HamurString &input,  bool writeMode = DEBUG);

		// Write initialization messages
		void WriteInitLog(string log, bool writeMode = ALWAYS);

        // Write termination log
        void WriteTerminateLog(string log, bool writeMode = ALWAYS);

        void CloseLogFile();
        void ClearLogFile();

        /**
        * Turn on-off debug mode.
        * If True passed, all massages will be written to log file,
        * If False passed, only messages with ALWAYS flag will be written.
        * @param mode True-False
        */
        void SetDebugMode(bool mode);

        /**
        * Flag for function to write always, whether Debug mode on or off. 
        * Error logs should use this flag.
        */
        const static bool ALWAYS = true;

        /**< Flag for function to write in Debug mode only. */
        const static bool DEBUG = false;

	protected:
		
	private:

        HamurFile mLogFile;
        const string mLogFileName;
        bool mDebugMode;

        const int initLogLength; /**< Length of: ".....OK!" string in the log file */
};
    
} // namespace hamur

#endif // HAMURLOG_H  
