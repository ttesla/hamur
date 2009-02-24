#include "hamurStream.h"

namespace hamur
{
	HamurStream::HamurStream()
	{

	}


	// HamurStream constructor loads stream
	HamurStream::HamurStream(const string &fileName, const string &StreamName) 
	: strFileName(fileName), strStreamName(StreamName)
	{

		if(!load_stream(fileName)) exit(1);

	}


	HamurStream::~HamurStream()
	{
		FSOUND_Stream_Close(stream);
	}


	// Loads the current stream
	bool HamurStream::load_stream(const string& name)
	{
		stream = FSOUND_Stream_Open(name.c_str(), FSOUND_NORMAL, 0, 0);
		
		if (!stream)
		{
			string tempStr = FMOD_ErrorString(FSOUND_GetError());
			HAMURLOG->write_log(tempStr + ": " + name);
			return false;
		}
		else
		{
			HAMURLOG->write_log("Stream loaded: " + name);
			return true;
		}
	}


	// Plays the current stream
	bool HamurStream::play_stream()
	{
		if (!stream)
		{
			 HAMURLOG->write_log(FMOD_ErrorString(FSOUND_GetError()));
			 return false;
		}
		else
		{
			FSOUND_Stream_Play(FSOUND_FREE, stream);	// plays stream
			return true;
		}		
	}


	// Stops the current stream
	bool HamurStream::stop_stream()
	{
		if (!stream)
		{
			 HAMURLOG->write_log(FMOD_ErrorString(FSOUND_GetError()));
			 return false;
		}
		else
		{
			FSOUND_Stream_Stop(stream);	// plays stream
			return true;
		}		
	}

}
