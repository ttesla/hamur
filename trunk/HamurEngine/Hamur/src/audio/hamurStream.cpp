#include "hamurStream.h"

namespace hamur
{
	HamurStream::HamurStream()
	{

	}


	// HamurStream constructor loads stream
	HamurStream::HamurStream(const string &fileName, const string &streamName) 
	: strFileName(fileName), strStreamName(streamName)
	{

		if(!loadStream(fileName)) exit(1);

	}


	HamurStream::~HamurStream()
	{
		FSOUND_Stream_Close(stream);
	}


	// Loads the current stream
	bool HamurStream::loadStream(const string& name)
	{
		stream = FSOUND_Stream_Open(name.c_str(), FSOUND_NORMAL, 0, 0);
		
		if (!stream)
		{
			string tempStr = FMOD_ErrorString(FSOUND_GetError());
            HAMURLOG->writeLogln("Error!: " + tempStr + ": " + name);
			return false;
		}
		else
		{
			HAMURLOG->writeLogln("Stream loaded: " + name);
			return true;
		}
	}


	// Plays the current stream
	bool HamurStream::playStream()
	{
		if (!stream)
		{
			 HAMURLOG->writeLogln(FMOD_ErrorString(FSOUND_GetError()));
			 return false;
		}
		else
		{
			FSOUND_Stream_Play(FSOUND_FREE, stream);	// plays stream
			return true;
		}		
	}


	// Stops the current stream
	bool HamurStream::stopStream()
	{
		if (!stream)
		{
			 HAMURLOG->writeLogln(FMOD_ErrorString(FSOUND_GetError()));
			 return false;
		}
		else
		{
			FSOUND_Stream_Stop(stream);	// plays stream
			return true;
		}		
	}

}
