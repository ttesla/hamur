#ifndef HAMURAUMR_H
#define HAMURAUMR_H

#include "../hamurSingleton.h"

#include <map>
#include <string>

using std::string;
using std::map;

namespace hamur
{

// Forward declarations
class HamurFX;
class HamurSong;
class HamurStream;

/**
* Hamur Audio Manager.
* Singleton class that manages the audio system.
*/
class HamurAuMR : public Singleton<HamurAuMR>
{
    public:

        friend class Singleton<HamurAuMR>;

		/**
		* Default Initialization of Audio.
		* Inits with 44100hz mixrate and 32 channels.
		* @return If initialization successful or not
		*/
		bool Init();

		/**
		* Initialization of Audio.
		* @see Init()
		* @param mixrate Output rate in hz between 4000 and 65535.
		* @param maxsoftwarechannels Maximum number of SOFTWARE channels available.
		* @param flags Controls some global or initialization time aspects of playback.
		* @return If initialization successful or not
		*/
		bool Init(int mixrate, int maxsoftwarechannels, unsigned int flags);

		/**
		* Get FX from "map" container according to given FX name.
		* @param strFxName Name of the effect file.
		*/
		HamurFX* GetFX(const string& strFxName) const;

		/**
		* Get Song from "map" container according to given Song name.
		* @param strSongName Name of the song file.
		*/
		HamurSong* GetSong(const string& strSongName) const;

		/**
		* Get Stream from "map" container according to given Stream name.
		* @param strStreamName Name of the stream file.
		*/
		HamurStream* GetStream(const string& strStreamName) const;

		/**
		* Add FX into "map" container with FX name index.
		* If the FX is already loaded, it doesn't add another copy.
		* @param strFxName Name of the effect.
        * @param strFileName Name of the path/file.
		*/
		void AddFX(const string& strFxName, const string& strFileName);

		/**
		* Add Song into "map" container with Song name index.
		* If the Song is already loaded, it doesn't add another copy.
		* @param strSongName Name of the song.
        * @param strFileName Name of the path/file.
		*/
		void AddSong(const string& strSongName, const string& strFileName);

		/**
		* Add Stream into "map" container with Stream name index.
		* If the Stream is already loaded, it doesn't add another copy.
        * @param strStreamName Name of the stream.
		* @param strFileName Name of the path/file.
		*/
		void AddStream(const string& strStreamName, const string& strFileName);

		/**
		* Deletes FX according to given FX name.
        * @param strFxName Name of the effect.
		*/
		bool DeleteFX(const string& strFxName);

        /**
        * Deletes Song according to given Song name.
        * @param strSongName Name of the song.
        */
		bool DeleteSong(const string& strSongName);

        /**
        * Deletes Stream according to given Stream name.
        * @param strStreamName Name of the stream.
        */
		bool DeleteStream(const string& strStreamName);


        /**
        * Plays effect according to given effect name.
        * @param strFxName Name of the effect.
        */
		void PlayFX(const string& strFxName);

        /**
        * Plays song according to given song name.
        * @param strSongName Name of the song.
        * @param loop Sets if song loops or not.
        */
		void PlaySong(const string& strSongName, bool loop);

        /**
        * Plays stream according to given stream name.
        * @param strStreamName Name of the stream.
        */
		void PlayStream(const string& strStreamName);

        /**
        * Clear and delete all audio objects in the Audio Manager
        */
        void ClearAll();

	protected:

        HamurAuMR();

        /**
        * Deletes all Audios in the map container.
        */
        ~HamurAuMR();

	private:
		map<string, HamurFX*> mFxMap;         /**< Store FXs according to their  names. */
		map<string, HamurSong*> mSongMap;     /**< Store Songs according to their  names. */
		map<string, HamurStream*> mStreamMap; /**< Store Streams according to their  names. */
};

} // namespace hamur

#endif	// HAMURAUMR_H
