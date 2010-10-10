#ifndef WAVE_H
#define WAVE_H

#include "hamur.h"
#include "Bacteria.h"
#include <list>

class Wave : public hamur::HamurObject
{
    public:
		static Wave *GetActiveWave() {if(mActiveWave != NULL)return mActiveWave;}

		Wave(const string& name, const hamur::HamurVec3 &basePos, int fattieCount, int normCount, int shooterCount, int slimCount, 
			int strayerCount);

		void Update(float deltaTime);
		void Draw(float deltaTime){};

		void StartWave();

		inline std::list<Bacteria *> GetBacteriaList() {return mBacteriaList;}
		inline std::list<Bacteria *> *GetSpawnedBacterias() {return &mSpawnedBacterias;}

	private:
		static Wave *mActiveWave;

		std::list<Bacteria *> mBacteriaList;
		std::list<Bacteria *> mSpawnedBacterias;
		bool mStarted;
		float mTimeCounter;
		//int mFattieCount;
		//int mNormCount;
		//int mShooterCount;
		//int mSlimCount;
		//int mStrayerCount;
};

#endif

