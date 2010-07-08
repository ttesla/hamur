#ifndef HAMURSONG_H
#define HAMURSONG_H

#include "fmod.h"

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
		bool LoadSong(const string& name);
		
        /**
        * Plays sequenced music files as song.
        * @param loop Sets if the song looping or not.
        * @return If playing successful or not.
        */ 
		bool PlaySong(bool loop);

        /**
        * Stops sequenced music file.
        * @return If stopping successful or not.
        */ 
		bool StopSong();

	private:
		FMUSIC_MODULE* mMod;  /**< Handle for the sequenced music files. */

		string mStrSongName;	 /**< Name of the song. */
		string mStrFileName;  /**< Name of the path/file. */
};

} // namespace hamur

#endif	// HAMURSONG_H
