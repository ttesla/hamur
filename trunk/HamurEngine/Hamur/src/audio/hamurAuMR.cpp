#include "hamurAuMR.h"
#include <assert.h>

namespace hamur
{
	HamurAuMR::HamurAuMR()
	{

	}


	// Deletes all Audios in the map container
	HamurAuMR::~HamurAuMR()
	{
        // Delete all
		clearAll();

		// Shuts down the WHOLE FMOD Sound System.
		// This also closes down the sample management system, freeing all MANAGED samples loaded 
		// (unless they were allocated with the FSOUND_UNMANAGED flag).
		// Streams are not freed. You must close them yourself.
		// CD Tracks are stopped.
		FSOUND_Close();
	}

	// Default Initialization of Audio
	bool HamurAuMR::init()
	{
		return init(44100, 32, 0);
	}


	// Initialization of Audio
	bool HamurAuMR::init(int mixrate, int maxsoftwarechannels, unsigned int flags)
	{
		if(!FSOUND_Init(mixrate, maxsoftwarechannels, flags))
		{
			HAMURLOG->writeLogln(FMOD_ErrorString(FSOUND_GetError()));
			return false;
		}
		else
		{
			HAMURLOG->writeInitLog("HamurAudio");
			return true;
		}
	}


	// Get FX from "map" container according to given FX name
	HamurFX* HamurAuMR::getFX(const string& strFxName)
	{
		//Look in the map if the FX is already loaded.
		map<string, HamurFX*>::iterator iter = fxMap.find(strFxName);
		
		if(iter != fxMap.end())
			return iter->second;

		else
			return 0; // Return NULL, FX not found.
	}


	// Get Song from "map" container according to given Song name
	HamurSong* HamurAuMR::getSong(const string& strSongName)
	{
		//Look in the map if the Song is already loaded.
		map<string, HamurSong*>::iterator iter = songMap.find(strSongName);
		
		if(iter != songMap.end())
			return iter->second;

		else
			return 0; // Return NULL, Song not found.
	}


	// Get Stream from "map" container according to given Stream name
	HamurStream* HamurAuMR::getStream(const string& strStreamName)
	{
		//Look in the map if the Stream is already loaded.
		map<string, HamurStream*>::iterator iter = streamMap.find(strStreamName);
		
		if(iter != streamMap.end())
			return iter->second;

		else
			return 0; // Return NULL, Stream not found.
	}


	// Add FX into "map" container with FX name index.
	// If the FX is already loaded, it doesn't add another copy
	void HamurAuMR::addFX(const string& strFxName, const string& strFileName)
	{
		// Look in the map if the FX is already loaded.
		map<string, HamurFX*>::iterator iter = fxMap.find(strFxName);
		
		if(iter == fxMap.end())
		{
			HamurFX *newFX = new HamurFX(strFileName, strFxName);
			fxMap[strFxName] = newFX;
		}
	}


	// Add Song into "map" container with Song name index.
	// If the Song is already loaded, it doesn't add another copy
	void HamurAuMR::addSong(const string& strSongName, const string& strFileName)
	{
		// Look in the map if the FX is already loaded.
		map<string, HamurSong*>::iterator iter = songMap.find(strSongName);
		
		if(iter == songMap.end())
		{
			HamurSong *newSong = new HamurSong(strFileName, strSongName);
			songMap[strSongName] = newSong;
		}
	}


	// Add Stream into "map" container with Stream name index.
	// If the Stream is already loaded, it doesn't add another copy
	void HamurAuMR::addStream(const string& strStreamName, const string& strFileName)
	{
		// Look in the map if the Stream is already loaded.
		map<string, HamurStream*>::iterator iter = streamMap.find(strStreamName);
		
		if(iter == streamMap.end())
		{
			HamurStream *newStream = new HamurStream(strFileName, strStreamName);
			streamMap[strStreamName] = newStream;
		}
	}


	// Deletes FX according to given FX name. 
	bool HamurAuMR::deleteFX(const string& strFxName)
	{
		// Get FX from the map
		bool bFound = false;
		map<string, HamurFX*>::iterator iter = fxMap.find(strFxName);

		if(iter != fxMap.end())
		{
			// If it was found, delete it then
			bFound = true;

			if(iter->second)
				delete iter->second;
			
			fxMap.erase(iter);
		}

		return bFound;
	}


	// Deletes Song according to given Song name. 
	bool HamurAuMR::deleteSong(const string& strSongName)
	{
		// Get Song from the map
		bool bFound = false;
		map<string, HamurSong*>::iterator iter = songMap.find(strSongName);

		if(iter != songMap.end())
		{
			// If it was found, delete it then
			bFound = true;

			if(iter->second)
			{
				delete iter->second;
			}
			
			songMap.erase(iter);
		}

		return bFound;
	}


	// Deletes Stream according to given Stream name. 
	bool HamurAuMR::deleteStream(const string& strStreamName)
	{
		// Get Stream from the map
		bool bFound = false;
		map<string, HamurStream*>::iterator iter = streamMap.find(strStreamName);

		if(iter != streamMap.end())
		{
			// If it was found, delete it then
			bFound = true;

			if(iter->second)
			{
				iter->second->stopStream();
				delete iter->second;
			}
			
			streamMap.erase(iter);
		}

		return bFound;
	}


	// Play FX
	void HamurAuMR::playFX(const string& strFxName)
	{
		getFX(strFxName)->playEffect();
	}
	
	// Play Song
	void HamurAuMR::playSong(const string& strSongName, bool loop)
	{
		getSong(strSongName)->playSong(loop);
	}

	// Play Stream
	void HamurAuMR::playStream(const string& strStreamName)
	{
		getStream(strStreamName)->playStream();
	}


    // Clear and delete all objects in Audio Manager
    void HamurAuMR::clearAll()
    {
        map<string, HamurFX*>::iterator iterFX;
        map<string, HamurSong*>::iterator iterSong;
        map<string, HamurStream*>::iterator iterStream;

        // Deletes all FXs in the map container
        for(iterFX = fxMap.begin(); iterFX != fxMap.end(); iterFX++)
        {
            if(iterFX->second)
                delete iterFX->second;
        }

        // Deletes all Songs in the map container
        for(iterSong = songMap.begin(); iterSong != songMap.end(); iterSong++)
        {
            if(iterSong->second)
                delete iterSong->second;
        }

        // Deletes all Streams in the map container
        for(iterStream = streamMap.begin(); iterStream != streamMap.end(); iterStream++)
        {
            if(iterStream->second)
                delete iterStream->second;
        }

        HAMURLOG->writeLogln("Hamur Audio Manager cleared.");
    }

}
