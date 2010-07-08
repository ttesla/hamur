#ifndef HAMURFX_H
#define HAMURFX_H

#include "fmod.h"

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
		bool LoadFX(const string& name);
		
		/**
		* Plays the PCM based or compress file as sound effect.
        * @return If playing successful or not.
		*/ 
		bool PlayFX();

	private:
        /**
        * Handle for variety of commands on a playing sound from the channel handle.
        */
		FSOUND_SAMPLE* mEffect;

		string mStrFxName;	 /**< Name of the effect. */
		string mStrFileName;  /**< Name of the path/file. */
};

} // namespace hamur

#endif	// HAMURFX_H
