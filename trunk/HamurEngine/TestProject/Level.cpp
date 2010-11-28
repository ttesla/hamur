#include "Level.h"
#include "Wave.h"
#include "Brush.h"
#include "IngameState.h"

using namespace std;

string Level::mActiveLevel = "";

Level::Level(const string& name) : HamurObject(name), isLevelFinished(false)
{
	resetTimeBetweenWaves();
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
			mWaves.empty()) //mActiveWave == *(mWaves.begin()))
		{
			activateBrush(true);
			static_cast<IngameState *>(HAMURSTATEMR->GetCurrentState())->ActivateBrush(true);
		}

		mTimeBetweenWaves = mTimeBetweenWaves - deltaTime;
		
		if(mTimeBetweenWaves <= 0)
		{
			static_cast<IngameState *>(HAMURSTATEMR->GetCurrentState())->ActivateBrush(false);
			StartNextWave();
			activateBrush(false);
			resetTimeBetweenWaves();
		}
	}
}

void Level::StartNextWave()
{
	if (!mWaves.empty())
	{
		mActiveWave = *(mWaves.end() - 1);
		mActiveWave->StartWave();
		mWaves.pop_back();
		static_cast<IngameState *>(HAMURSTATEMR->GetCurrentState())->ShowWaveText(mActiveWave->GetName());
	}
	else if(mWaves.empty() && Wave::GetAllSpawnedBacterias()->empty())
	{
		isLevelFinished = true;
		mWaves.clear();
		SetActive(false);
		//HAMURSTATEMR->ChangeState("FeedbackState");
		static_cast<IngameState *>(HAMURSTATEMR->GetCurrentState())->GoToFeedbackState();
	}
}

void Level::activateBrush( const bool &isActive )
{
	Brush *b = static_cast<Brush *>(HAMURWORLD->GetHamurObject("BrushBullet"));
	b->SetActive(isActive);
}

