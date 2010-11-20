#ifndef WAVE_H
#define WAVE_H

#include "hamur.h"
#include "Bacteria.h"
#include <list>

using namespace std;

class Wave : public hamur::HamurObject
{
    public:
		static Wave *GetActiveWave() {if(mActiveWave != NULL)return mActiveWave;}
		static std::list<Wave *> *CreatedWaves() {return mCreatedWaves;}

		Wave(const string& name, const hamur::HamurVec3 &basePos, int fattieCount, int normCount, int shooterCount, int slimCount, 
			int strayerCount);

		void Update(float deltaTime);
		void Draw(float deltaTime){};

		//Starts the wave and register it to the static mActiveWave variable. 
		void StartWave();

		//Deletes all the bacterias for the hamurworld
		void DeleteBacteria();

		inline std::list<Bacteria *> GetBacteriaList() {return mBacteriaList;}
		inline std::list<Bacteria *> *GetSpawnedBacterias() {return &mSpawnedBacterias;}
		inline bool IsFinished() {return mIsWaveFinished;}


	private:
		static Wave *mActiveWave;
		static std::list<Wave *> *mCreatedWaves;

		//All bacterias which will be spawned during the wave. If this list is empty, it means
		//all bacterias in this wave has been spawned
		list<Bacteria *> mBacteriaList;

		//Spawned bacterias
		list<Bacteria *> mSpawnedBacterias;

		bool mStarted;

		//Time counter which is used for activating bacterias
		float mTimeCounter;

		//Spawning interval between every bacteria. It' s been found by deviding the total wave time, which is 30, by bacteria amount
		float mSpawningInterval;
		bool mIsWaveFinished;
};

#endif

