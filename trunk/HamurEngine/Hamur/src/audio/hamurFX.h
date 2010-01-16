#ifndef HAMURFX_H
#define HAMURFX_H

#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"

#include "fmod.h"
#include "fmod_errors.h"

#include <string>

using std::string;

namespace hamur
{
	/** 
    * Loads and plays PCM based or compressed files
    * such as .WAV, .MP2, .MP3, .OGG or .RAW  as sound effects.
    */
	class HamurFX
	{
		public:

			HamurFX();
			~HamurFX();

            /**
            * HamurFX constructor.
            * Loads effect.
            * @see loadEffect
            * @param fileName Name of the path/file.
            * @param fxName Name of the effect.
            */
			HamurFX(const string& fileName, const string& fxName);
			
			/**
			* Loads PCM based or compressed files
            * such as .WAV, .MP2, .MP3, .OGG or .RAW  as sound effects.
            * @param name Name of the effect.
            * @return If loading successful or not.
			*/ 
			bool loadEffect(const string& name);
			
			/**
			* Plays the PCM based or compress file as sound effect.
            * @return If playing successful or not.
			*/ 
			bool playEffect();

		private:
            /**
            * Handle for variety of commands on a playing sound from the channel handle.
            */
			FSOUND_SAMPLE* effect;

			string strFxName;	 /**< Name of the effect. */
			string strFileName;  /**< Name of the path/file. */
	};
}

#endif	// HAMURFX_H
