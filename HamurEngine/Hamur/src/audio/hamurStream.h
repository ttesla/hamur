#ifndef HAMURSTREAM_H
#define HAMURSTREAM_H

#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"
#include "fmod.h"
#include "fmod_errors.h"
#include <string>

using std::string;

namespace hamur
{
    /**
    * Loads and plays PCM based or compressed files
    * such as .WAV, .MP2, .MP3, .OGG or .RAW as music/stream.
    */
	class HamurStream
	{
		public:

			HamurStream();
			~HamurStream();

            /**
            * HamurStream constructor.
            * Loads stream.
            * @see loadStream
            * @param fileName Name of the path/file.
            * @param streamName Name of the stream.
            */
			HamurStream(const string& fileName, const string& streamName);
			
            /**
            * Loads PCM based or compressed files
            * such as .WAV, .MP2, .MP3, .OGG or .RAW  as music/stream.
            * @param name Name of the stream.
            * @return If loading successful or not.
            */ 
			bool loadStream(const string& name);
			
            /**
            * Plays PCM based or compressed file as music/stream.
            * @return If playing successful or not.
            */
			bool PlayStream();

            /**
            * Stops PCM based or compressed file.
            * @return If stopping successful or not.
            */ 
			bool stopStream();

		private:

            /**
            * Handles variety of commands on a playing stream from channel handle.
            */
			FSOUND_STREAM*  stream;

			string strStreamName; /**< Name of the stream. */
			string strFileName;	  /**< Name of the path/file. */
	};
}

#endif	// HAMURSTREAM_H
