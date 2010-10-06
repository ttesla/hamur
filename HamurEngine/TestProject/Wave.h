#ifndef WAVE_H
#define WAVE_H

#include "hamur.h"
using namespace hamur;

#define MAXLEVEL 5

class Wave
{
    public:
        Wave(const string& name, int level);
		virtual void Start();

		int GetLevel(){return mLevel;}
		void SetLevel(int level){if (level < MAXLEVEL && level > 0) mLevel = level; else exit(-1);}

	private:
		string mName;
		// Level of difficulty of each wave
		int mLevel;
		/**
		* It is needed to erase the enemies from game state and bring them to each Wave of each Level
		//HamurObject** enemies; 
		*/
};

#endif

