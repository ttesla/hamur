#ifndef HAMURAUMR_H
#define HAMURAUMR_H

#include "hamurFx.h"
#include "hamurSong.h"
#include "hamurStream.h"
#include "../hamurSingleton.h"

#include <map>

using std::map;

namespace hamur
{
    /**
    * Hamur Audio Manager.
    * Singleton class that manages the audio system.
    */
	class HamurAuMR : public Singleton<HamurAuMR>
	{
		public:

            friend Singleton<HamurAuMR>;

			/** 
			* Default Initialization of Audio.
			* Inits with 44100hz mixrate and 32 channels.
			* @return If initialization successful or not
			*/
			bool init();

			/**
			* Initialization of Audio.
			* @see init()
			* @param mixrate Output rate in hz between 4000 and 65535.
			* @param maxsoftwarechannels Maximum number of SOFTWARE channels available.
			* @param flags Controls some global or initialization time aspects of playback.
			* @return If initialization successful or not
			*/ 
			bool init(int mixrate, int maxsoftwarechannels, unsigned int flags);

			/**
			* Get FX from "map" container according to given FX name.
			* @param strFxName Name of the effect file.
			*/
			HamurFX* getFX(const string& strFxName);

			/**
			* Get Song from "map" container according to given Song name.
			* @param strSongName Name of the song file.
			*/
			HamurSong* getSong(const string& strSongName);

			/**
			* Get Stream from "map" container according to given Stream name.
			* @param strStreamName Name of the stream file.
			*/
			HamurStream* getStream(const string& strStreamName);

			/**
			* Add FX into "map" container with FX name index.
			* If the FX is already loaded, it doesn't add another copy.
			* @param strFileName Name of the path/file.
			* @param strFxName Name of the effect.
			*/
			void addFX(const string& strFileName, const string& strFxName);

			/**
			* Add Song into "map" container with Song name index.
			* If the Song is already loaded, it doesn't add another copy.
			* @param strFileName Name of the path/file.
			* @param strSongName Name of the song.
			*/
			void addSong(const string& strFileName, const string& strSongName);

			/**
			* Add Stream into "map" container with Stream name index.
			* If the Stream is already loaded, it doesn't add another copy.
			* @param strFileName Name of the path/file.
			* @param strStreamName Name of the stream.
			*/
			void addStream(const string& strFileName, const string& strSongName);

			/**
			* Deletes FX according to given FX name.
            * @param strFxName Name of the effect.
			*/
			bool deleteFX(const string& strFxName);

            /**
            * Deletes Song according to given Song name.
            * @param strSongName Name of the song.
            */
			bool deleteSong(const string& strSongName);

            /**
            * Deletes Stream according to given Stream name.
            * @param strStreamName Name of the stream.
            */
			bool deleteStream(const string& strStreamName);

			
            /**
            * Plays effect according to given effect name.
            * @param strFxName Name of the effect.
            */
			void playFX(const string& strFxName);

            /**
            * Plays song according to given song name.
            * @param strSongName Name of the song.
            * @param loop Sets if song loops or not.
            */
			void playSong(const string& strSongName, bool loop);

            /**
            * Plays stream according to given stream name.
            * @param strStreamName Name of the stream.
            */
			void playStream(const string& strStreamName);

		protected:

            HamurAuMR();

            /**
            * Deletes all Audios in the map container.
            */
            ~HamurAuMR();

		private:
			map<string, HamurFX*> fxMap;         /**< Store FX's according to their  names. */
			map<string, HamurSong*> songMap;     /**< Store Song's according to their  names. */
			map<string, HamurStream*> streamMap; /**< Store Song's according to their  names. */
	};
}

#endif	// HAMURAUMR_H
