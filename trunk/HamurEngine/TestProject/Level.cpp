#include "Level.h"
#include "Wave.h"
#include "Brush.h"

using namespace std;

Level::Level(const string& name) : HamurObject(name), isLevelFinished(false)
{
	mBrush = new Brush("BrushBullet", 1);
}

void Level::Start()
{
	StartNextWave();
	isLevelFinished = false;
}

void Level::AddWave( Wave *w )
{
	mWaves.push_back(w);
}

void Level::Update( float deltaTime )
{
	if(mActiveWave->IsFinished())
	{
		//TODO:This section will be removed from here, and toothbrushing will be done manually by
		//player
		if(mActiveWave->GetName().compare(0, 9, "Breakfast") == 0 ||
			mActiveWave->GetName().compare(0, 6, "Dinner"))
			mBrush->Explode();

		StartNextWave();
	}
}

void Level::StartNextWave()
{
	if (!mWaves.empty())
	{
		mActiveWave = *(mWaves.end() - 1);
		mActiveWave->StartWave();
		mWaves.pop_back();
	}
	else
	{
		isLevelFinished = true;
		mWaves.clear();
		SetActive(false);
		HAMURSTATEMR->ChangeState("FeedbackState");
	}
}