#ifndef HAMURSONG_H
#define HAMURSONG_H

#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"

#include "fmod.h"
#include "fmod_errors.h"

#include <string>

using std::string;

namespace hamur
{	
	/**
    * Loads and plays sequenced music files
    * such as .MOD, .S3M, .XM, .IT or .MID as songs.
    */
	class HamurSong
	{
		public:

			HamurSong();
			~HamurSong();
   
            /**
            * HamurSong constructor.
            * Loads song.
            * @see loadSong
            * @param fileName Name of the path/file.
            * @param songName Name of the song.
            */
			HamurSong(const string& fileName, const string& songName);
			
            /**
            * Loads sequenced music files
            * such as .MOD, .S3M, .XM, .IT or .MID as songs.
            * @param name Name of the song.
            * @return If loading successful or not.
            */ 
			bool loadSong(const string& name);
			
            /**
            * Plays sequenced music files as song.
            * @param loop Sets if the song looping or not.
            * @return If playing successful or not.
            */ 
			bool playSong(bool loop);

            /**
            * Stops sequenced music file.
            * @return If stopping successful or not.
            */ 
			bool stopSong();

		private:
			FMUSIC_MODULE* mod;  /**< Handle for the sequenced music files. */

			string strSongName;	 /**< Name of the song. */
			string strFileName;  /**< Name of the path/file. */
	};
}

#endif	// HAMURSONG_H
