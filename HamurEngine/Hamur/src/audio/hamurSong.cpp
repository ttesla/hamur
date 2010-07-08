#include "hamurSong.h"
#include "fmod_errors.h"
#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"

namespace hamur
{

HamurSong::HamurSong()
{

}


// HamurSong constructor loads song
HamurSong::HamurSong(const string& fileName, const string& songName) 
: mStrFileName(fileName), mStrSongName(songName)
{
	if(!LoadSong(fileName)) exit(1);
}


HamurSong::~HamurSong()
{
	FMUSIC_FreeSong(mMod);
    HAMURLOG->writeLogln("Song deleted: " + mStrSongName + ", " + mStrFileName);
}


// Loads the current song
bool HamurSong::LoadSong(const string& name)
{
	mMod = FMUSIC_LoadSong(name.c_str());
	
	if (!mMod)
	{
		string tempStr = FMOD_ErrorString(FSOUND_GetError());
		HAMURLOG->writeLogln(tempStr + ": " + name);
		return false;
	}
	else
	{
		HAMURLOG->writeLogln("Song loaded: " + name);
		return true;
	}
}


// Plays the current song
bool HamurSong::PlaySong(bool loop)
{
	if (!mMod)
	{
		 HAMURLOG->writeLogln(FMOD_ErrorString(FSOUND_GetError()));
		 return false;
	}
	else
	{
		FMUSIC_SetLooping(mMod, loop);
		FMUSIC_PlaySong(mMod);	// plays song
		return true;
	}		
}


// Stops the current song
bool HamurSong::StopSong()
{
	if (!mMod)
	{
		 HAMURLOG->writeLogln(FMOD_ErrorString(FSOUND_GetError()));
		 return false;
	}
	else
	{
		FMUSIC_StopSong(mMod);	// stops song
		return true;
	}		
}

} // namespace hamur
