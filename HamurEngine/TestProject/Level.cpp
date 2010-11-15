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
}

void Level::AddWave( Wave *w )
{
	mWaves.push_back(w);
}

void Level::Update( float deltaTime )
{
	if(mActiveWave->IsFinished())
	{
		//TODO:Add brush explosion after breakfast and dinner
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
		cout<<mActiveWave->GetName() + "wave started";
		mWaves.pop_back();
	}
	else
	{
		isLevelFinished = true;
	}
}