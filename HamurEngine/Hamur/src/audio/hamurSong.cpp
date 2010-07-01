#include "hamurSong.h"

namespace hamur
{
	HamurSong::HamurSong()
	{

	}


	// HamurSong constructor loads song
	HamurSong::HamurSong(const string &fileName, const string &songName) 
	: strFileName(fileName), strSongName(songName)
	{
		if(!loadSong(fileName)) exit(1);
	}


	HamurSong::~HamurSong()
	{
		FMUSIC_FreeSong(mod);
        HAMURLOG->writeLogln("Song deleted: " + strSongName + ", " + strFileName);
	}


	// Loads the current song
	bool HamurSong::loadSong(const string& name)
	{
		mod = FMUSIC_LoadSong(name.c_str());
		
		if (!mod)
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
		if (!mod)
		{
			 HAMURLOG->writeLogln(FMOD_ErrorString(FSOUND_GetError()));
			 return false;
		}
		else
		{
			FMUSIC_SetLooping(mod, loop);
			FMUSIC_PlaySong(mod);	// plays song
			return true;
		}		
	}


	// Stops the current song
	bool HamurSong::stopSong()
	{
		if (!mod)
		{
			 HAMURLOG->writeLogln(FMOD_ErrorString(FSOUND_GetError()));
			 return false;
		}
		else
		{
			FMUSIC_StopSong(mod);	// stops song
			return true;
		}		
	}

}
