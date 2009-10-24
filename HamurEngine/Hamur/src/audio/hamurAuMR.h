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
	class HamurAuMR : public Singleton<HamurAuMR>
	{
		public:
			HamurAuMR();
			~HamurAuMR();

			// Default Initialization of Audio
			bool init();

			// Initialization of FX
			bool init(int mixrate, int maxsoftwarechannels, unsigned int flags);

			HamurFX* getFX(const string& strFxName);	//Gets Effect
			HamurSong* getSong(const string& strSongName);	//Gets Song
			HamurStream* getStream(const string& strStreamName);	//Gets Stream

			bool deleteFX(const string& strFxName);		//Deletes Effect
			bool deleteSong(const string& strSongName);	//Deletes Song
			bool deleteStream(const string& strStreamName);	//Deletes Song

			void addFX(const string& strFileName, const string& strFxName);	//Add FX
			void addSong(const string& strFileName, const string& strSongName); //Add Song
			void addStream(const string& strFileName, const string& strSongName); //Add Stream

			void play_FX(const string& strFxName);				  /// Play FX
			void play_song(const string& strSongName, bool loop); // Play Song
			void play_stream(const string& strStreamName);		  // Play Stream

		protected:

		private:
			map<string, HamurFX*> fxMap; //Store FX's according to their  names
			map<string, HamurSong*> songMap; //Store Song's according to their  names
			map<string, HamurStream*> streamMap; //Store Song's according to their  names

	};
}
#endif	// HAMURAUMR_H



