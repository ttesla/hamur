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

		inline bool IsLevelFinished() {return isLevelFinished;}

	private:
		std::vector<Wave *> mWaves;
		Wave *mActiveWave;
		Brush *mBrush;
		bool isLevelFinished;
};

#endif

