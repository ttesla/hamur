#include "hamurFX.h"
#include "fmod_errors.h"
#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"

namespace hamur
{

HamurFX::HamurFX()
{

}


// HamurFX constructor loads effect
HamurFX::HamurFX(const string &fileName, const string &fxName) 
: mStrFileName(fileName), mStrFxName(fxName)
{
	if(!LoadFX(fileName)) exit(1);
}


HamurFX::~HamurFX()
{
	FSOUND_Sample_Free(mEffect);
    HAMURLOG->WriteLogln("FX deleted: " + mStrFxName + ", " + mStrFileName);
}


// Loads the current effect
bool HamurFX::LoadFX(const std::string& name)
{
	// FSOUND_UNMANAGED : Do not use FSOUND's sample manager.
	// FSOUND_FREE : Selects an empty index for our effect. Do not use 0 here!
	mEffect = FSOUND_Sample_Load(FSOUND_FREE, name.c_str(), FSOUND_LOOP_OFF, 0, 0);
	
	if (!mEffect)
	{
		string tempStr = FMOD_ErrorString(FSOUND_GetError());
        HAMURLOG->WriteLogln("Error!: " + tempStr + ": " + name, HamurLog::ALWAYS);
		return false;
	}
	else
	{
		HAMURLOG->WriteLogln("FX loaded: " + name);
		return true;
	}
}


// Plays the current effect
bool HamurFX::PlayFX()
{
	if (!mEffect)
	{
		 HAMURLOG->WriteLogln(FMOD_ErrorString(FSOUND_GetError()));
		 return false;
	}
	else
	{
		FSOUND_PlaySound(FSOUND_FREE, mEffect);	
		return true;
	}
}

} // namespace hamur
