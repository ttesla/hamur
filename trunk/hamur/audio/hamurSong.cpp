#include "hamurSong.h"

namespace hamur
{
	HamurSong::HamurSong()
	{

	}


	// HamurSong constructor loads song
	HamurSong::HamurSong(const string &fileName, const string &SongName) 
	: strFileName(fileName), strSongName(SongName)
	{
		if(!load_song(fileName)) exit(1);
	}


	HamurSong::~HamurSong()
	{
		FMUSIC_FreeSong(mod);
	}


	// Loads the current song
	bool HamurSong::load_song(const string& name)
	{
		mod = FMUSIC_LoadSong(name.c_str());
		
		if (!mod)
		{
			string tempStr = FMOD_ErrorString(FSOUND_GetError());
			HAMURLOG->write_log(tempStr + ": " + name);
			return false;
		}
		else
		{
			HAMURLOG->write_log("Song loaded: " + name);
			return true;
		}
	}


	// Plays the current song
	bool HamurSong::play_song(bool loop)
	{
		if (!mod)
		{
			 HAMURLOG->write_log(FMOD_ErrorString(FSOUND_GetError()));
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
	bool HamurSong::stop_song()
	{
		if (!mod)
		{
			 HAMURLOG->write_log(FMOD_ErrorString(FSOUND_GetError()));
			 return false;
		}
		else
		{
			FMUSIC_StopSong(mod);	// stops song
			return true;
		}		
	}

}
