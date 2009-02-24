#ifndef HAMURSTREAM_H
#define HAMURSTREAM_H

#include "../hamurLog.h"
#include "../hamurDefinition.h"
#include "Fmod/fmod.h"
#include "FMOD/fmod_errors.h"
#include <string>

using std::string;

namespace hamur
{	
	// Loads and plays PCM based or compressed file such as .WAV, .MP2, .MP3, .OGG or .RAW  as music/stream
	class HamurStream
	{
		public:

			HamurStream();
			~HamurStream();

			HamurStream(const string& fileName, const string& StreamName);
			
			// Loads PCM based or compressed file such as .WAV, .MP2, .MP3, .OGG or .RAW  as music/stream
			bool load_stream(const string& name);
			
			// Plays PCM based or compressed file such as .WAV, .MP2, .MP3, .OGG or .RAW  as music/stream
			bool play_stream();

			// Stops PCM based or compressed file such as .WAV, .MP2, .MP3, .OGG or .RAW  as music/stream
			bool stop_stream();


		private:

			FSOUND_STREAM*  stream;

			string strStreamName;		// Name of the stream
			string strFileName;			// File path name of the stream
	};
}
#endif	// HAMURSTREAM_H
