#ifndef HAMURSONG_H
#define HAMURSONG_H

#include "../hamurLog.h"
#include "../hamurDefinitions.h"
#include "fmod.h"
#include "fmod_errors.h"
#include <string>


using std::string;

namespace hamur
{	
	// Loads and plays sequenced music file such as .MOD, .S3M, .XM, .IT or .MID
	class HamurSong
	{
		public:

			HamurSong();
			~HamurSong();

			HamurSong(const string& fileName, const string& SongName);
			
			// Loads sequenced music file such as .MOD, .S3M, .XM, .IT or .MID
			bool load_song(const string& name);
			
			// Plays sequenced music file such as .MOD, .S3M, .XM, .IT or .MID
			bool play_song(bool loop);

			// Stops sequenced music file such as .MOD, .S3M, .XM, .IT or .MID
			bool stop_song();


		private:

			FMUSIC_MODULE* mod;

			string strSongName;	 // Name of the song
			string strFileName;  // File path name of the song
	};
}
#endif	// HAMURSONG_H  
