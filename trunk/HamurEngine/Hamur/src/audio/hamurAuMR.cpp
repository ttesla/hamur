#include "hamurFX.h"
#include "hamurStream.h"
#include "hamurSong.h"
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
	ClearAll();

	// Shuts down the WHOLE FMOD Sound System.
	// This also closes down the sample management system, freeing all MANAGED samples loaded 
	// (unless they were allocated with the FSOUND_UNMANAGED flag).
	// Streams are not freed. You must close them yourself.
	// CD Tracks are stopped.
	FSOUND_Close();

    HAMURLOG->writeTerminateLog("HamurAudio");
}


// Default Initialization of Audio
bool HamurAuMR::Init()
{
	return Init(44100, 32, 0);
}


// Initialization of Audio
bool HamurAuMR::Init(int mixrate, int maxsoftwarechannels, unsigned int flags)
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
HamurFX* HamurAuMR::GetFX(const string& strFxName)
{
	//Look in the map if the FX is already loaded.
	map<string, HamurFX*>::iterator iter = mFxMap.find(strFxName);
	
	if(iter != mFxMap.end())
		return iter->second;

	else
		return 0; // Return NULL, FX not found.
}


// Get Song from "map" container according to given Song name
HamurSong* HamurAuMR::GetSong(const string& strSongName)
{
	//Look in the map if the Song is already loaded.
	map<string, HamurSong*>::iterator iter = mSongMap.find(strSongName);
	
	if(iter != mSongMap.end())
		return iter->second;

	else
		return 0; // Return NULL, Song not found.
}


// Get Stream from "map" container according to given Stream name
HamurStream* HamurAuMR::GetStream(const string& strStreamName)
{
	//Look in the map if the Stream is already loaded.
	map<string, HamurStream*>::iterator iter = mStreamMap.find(strStreamName);
	
	if(iter != mStreamMap.end())
		return iter->second;

	else
		return 0; // Return NULL, Stream not found.
}


// Add FX into "map" container with FX name index.
// If the FX is already loaded, it doesn't add another copy
void HamurAuMR::AddFX(const string& strFxName, const string& strFileName)
{
	// Look in the map if the FX is already loaded.
	map<string, HamurFX*>::iterator iter = mFxMap.find(strFxName);
	
	if(iter == mFxMap.end())
	{
		HamurFX *newFX = new HamurFX(strFileName, strFxName);
		mFxMap[strFxName] = newFX;
	}
}


// Add Song into "map" container with Song name index.
// If the Song is already loaded, it doesn't add another copy
void HamurAuMR::AddSong(const string& strSongName, const string& strFileName)
{
	// Look in the map if the FX is already loaded.
	map<string, HamurSong*>::iterator iter = mSongMap.find(strSongName);
	
	if(iter == mSongMap.end())
	{
		HamurSong *newSong = new HamurSong(strFileName, strSongName);
		mSongMap[strSongName] = newSong;
	}
}


// Add Stream into "map" container with Stream name index.
// If the Stream is already loaded, it doesn't add another copy
void HamurAuMR::AddStream(const string& strStreamName, const string& strFileName)
{
	// Look in the map if the Stream is already loaded.
	map<string, HamurStream*>::iterator iter = mStreamMap.find(strStreamName);
	
	if(iter == mStreamMap.end())
	{
		HamurStream *newStream = new HamurStream(strFileName, strStreamName);
		mStreamMap[strStreamName] = newStream;
	}
}


// Deletes FX according to given FX name. 
bool HamurAuMR::DeleteFX(const string& strFxName)
{
	// Get FX from the map
	bool bFound = false;
	map<string, HamurFX*>::iterator iter = mFxMap.find(strFxName);

	if(iter != mFxMap.end())
	{
		// If it was found, delete it then
		bFound = true;

		if(iter->second)
			delete iter->second;
		
		mFxMap.erase(iter);
	}

	return bFound;
}


// Deletes Song according to given Song name. 
bool HamurAuMR::DeleteSong(const string& strSongName)
{
	// Get Song from the map
	bool bFound = false;
	map<string, HamurSong*>::iterator iter = mSongMap.find(strSongName);

	if(iter != mSongMap.end())
	{
		// If it was found, delete it then
		bFound = true;

		if(iter->second)
		{
			delete iter->second;
		}
		
		mSongMap.erase(iter);
	}

	return bFound;
}


// Deletes Stream according to given Stream name. 
bool HamurAuMR::DeleteStream(const string& strStreamName)
{
	// Get Stream from the map
	bool bFound = false;
	map<string, HamurStream*>::iterator iter = mStreamMap.find(strStreamName);

	if(iter != mStreamMap.end())
	{
		// If it was found, delete it then
		bFound = true;

		if(iter->second)
		{
			iter->second->stopStream();
			delete iter->second;
		}
		
		mStreamMap.erase(iter);
	}

	return bFound;
}


// Play FX
void HamurAuMR::PlayFX(const string& strFxName)
{
	GetFX(strFxName)->PlayFX();
}

// Play Song
void HamurAuMR::PlaySong(const string& strSongName, bool loop)
{
	GetSong(strSongName)->PlaySong(loop);
}

// Play Stream
void HamurAuMR::PlayStream(const string& strStreamName)
{
	GetStream(strStreamName)->PlayStream();
}


// Clear and delete all objects in Audio Manager
void HamurAuMR::ClearAll()
{
    map<string, HamurFX*>::iterator iterFX;
    map<string, HamurSong*>::iterator iterSong;
    map<string, HamurStream*>::iterator iterStream;

    // Deletes all FXs in the map container
    for(iterFX = mFxMap.begin(); iterFX != mFxMap.end(); iterFX++)
    {
        if(iterFX->second)
            delete iterFX->second;
    }

    // Deletes all Songs in the map container
    for(iterSong = mSongMap.begin(); iterSong != mSongMap.end(); iterSong++)
    {
        if(iterSong->second)
            delete iterSong->second;
    }

    // Deletes all Streams in the map container
    for(iterStream = mStreamMap.begin(); iterStream != mStreamMap.end(); iterStream++)
    {
        if(iterStream->second)
            delete iterStream->second;
    }

    HAMURLOG->writeLogln("All audio objects deleted.");
}

} // namespace hamur
