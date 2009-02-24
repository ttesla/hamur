#ifndef HAMURFX_H
#define HAMURFX_H

#include "../hamurLog.h"
#include "../hamurDefinition.h"
#include "Fmod/fmod.h"
#include "FMOD/fmod_errors.h"
#include <string>

using std::string;

namespace hamur
{
	// Loads and plays PCM based or compressed file such as .WAV, .MP2, .MP3, .OGG or .RAW  as sound effects
	class HamurFX
	{
		public:

			HamurFX();
			~HamurFX();

			HamurFX(const string& fileName, const string& FxName);
			
			// Loads PCM based or compressed file such as .WAV, .MP2, .MP3, .OGG or .RAW  as sound effects 
			bool load_effect(const string& name);
			
			// Plays PCM based or compressed file such as .WAV, .MP2, .MP3, .OGG or .RAW  as sound effects
			bool play_effect();

		private:

			FSOUND_SAMPLE* effect;

			string strFxName;	 // Name of the FX
			string strFileName;  // File path name of the FX
	};
}
#endif	// HAMURFX_H  
