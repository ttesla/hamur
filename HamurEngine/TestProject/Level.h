#ifndef LEVEL_H
#define LEVEL_H
#include "Wave.h"
#include "hamur.h"
#include <vector>
using namespace hamur;

class Brush;

class Level : public HamurObject
{
    public:
        Level(const string& name);

		void Update(float deltaTime);
		void Draw(float deltaTime){}

		void Start();
		void AddWave(Wave *w);
		void StartNextWave();
		
		Wave* GetActiveWave() {return mActiveWave;}
		inline bool IsLevelFinished() {return isLevelFinished;}

	private:
		inline void resetTimeBetweenWaves() {mTimeBetweenWaves = 10;}

		void activateBrush(const bool &isActive);

		std::vector<Wave *> mWaves;
		Wave *mActiveWave;
		float mTimeBetweenWaves;
		bool isLevelFinished;
};

#endif

