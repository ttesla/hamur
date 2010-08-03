#include "hamurStream.h"
#include "fmod_errors.h"
#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"

namespace hamur
{
HamurStream::HamurStream()
{

}


// HamurStream constructor loads stream
HamurStream::HamurStream(const string& fileName, const string& streamName) 
: mStrFileName(fileName), mStrStreamName(streamName)
{

	if(!LoadStream(fileName)) exit(1);

}


HamurStream::~HamurStream()
{
	FSOUND_Stream_Close(mStream);
    HAMURLOG->WriteLogln("Stream deleted: " + mStrStreamName + ", " + mStrFileName);
}


// Loads the current stream
bool HamurStream::LoadStream(const string& name)
{
	mStream = FSOUND_Stream_Open(name.c_str(), FSOUND_NORMAL, 0, 0);
	
	if (!mStream)
	{
		string tempStr = FMOD_ErrorString(FSOUND_GetError());
        HAMURLOG->WriteLogln("Error!: " + tempStr + ": " + name, HamurLog::ALWAYS);
		return false;
	}
	else
	{
		HAMURLOG->WriteLogln("Stream loaded: " + name);
		return true;
	}
}


// Plays the current stream
bool HamurStream::PlayStream()
{
	if (!mStream)
	{
		 HAMURLOG->WriteLogln(FMOD_ErrorString(FSOUND_GetError()));
		 return false;
	}
	else
	{
		FSOUND_Stream_Play(FSOUND_FREE, mStream);	// plays stream
		return true;
	}		
}


// Stops the current stream
bool HamurStream::StopStream()
{
	if (!mStream)
	{
		 HAMURLOG->WriteLogln(FMOD_ErrorString(FSOUND_GetError()));
		 return false;
	}
	else
	{
		FSOUND_Stream_Stop(mStream);	// plays stream
		return true;
	}		
}

} // namespace hamur
