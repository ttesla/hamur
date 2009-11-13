#include "hamurFX.h"

namespace hamur
{
	HamurFX::HamurFX()
	{

	}


	// HamurFX constructor loads effect
	HamurFX::HamurFX(const string &fileName, const string &fxName) 
	: strFileName(fileName), strFxName(fxName)
	{
		if(!loadEffect(fileName)) exit(1);
	}


	HamurFX::~HamurFX()
	{
		FSOUND_Sample_Free(effect);
	}


	// Loads the current effect
	bool HamurFX::loadEffect(const std::string &name)
	{
		// FSOUND_UNMANAGED : Do not use FSOUND's sample manager.
		// FSOUND_FREE : Selects an empty index for our effect. Do not use 0 here!
		effect = FSOUND_Sample_Load(FSOUND_FREE, name.c_str(), FSOUND_LOOP_OFF, 0, 0);
		
		if (!effect)
		{
			string tempStr = FMOD_ErrorString(FSOUND_GetError());
			HAMURLOG->write_log(tempStr + ": " + name);
			return false;
		}
		else
		{
			HAMURLOG->write_log("FX loaded: " + name);
			return true;
		}
	}


	// Plays the current effect
	bool HamurFX::playEffect()
	{
		if (!effect)
		{
			 HAMURLOG->write_log(FMOD_ErrorString(FSOUND_GetError()));
			 return false;
		}
		else
		{
			FSOUND_PlaySound(FSOUND_FREE, effect);	
			return true;
		}
	}

}
