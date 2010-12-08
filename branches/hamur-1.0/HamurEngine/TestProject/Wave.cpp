#include "Wave.h"
#include "BacteriaNorm.h"
#include "BacteriaFattie.h"
#include "BacteriaStrayer.h"
#include "BacteriaShooter.h"
#include "BacteriaSlim.h"
#include "Teeth.h"

using namespace std;
using namespace hamur; 

Wave *Wave::mActiveWave = NULL;
list<Wave *> *Wave::mCreatedWaves = NULL;
list<Bacteria *> *Wave::mAllSpawnedBacterias = NULL;

Wave::Wave( const string& name, const int &totalWaveTime, int fattieCount, int normCount, int shooterCount, 
		   int slimCount, int strayerCount ) : HamurObject(name), mTimeCounter(0), mStarted(false)
{
	if(mCreatedWaves == NULL)
		mCreatedWaves = new list<Wave *>;

	if(mAllSpawnedBacterias == NULL)
		mAllSpawnedBacterias = new list<Bacteria *>;

	int totalBactCount = fattieCount + normCount + shooterCount + slimCount + strayerCount;
	mTotalTimeOfWave = totalWaveTime;
	mSpawningInterval = mTotalTimeOfWave / totalBactCount;

	FillBacterias(fattieCount, normCount, shooterCount, slimCount, strayerCount);
	
	mTeeth = static_cast<Teeth *>(HAMURWORLD->GetHamurObject("teeth"));

	mCreatedWaves->push_back(this);
}

Wave::~Wave()
{
	/*if(mAllSpawnedBacterias != NULL)
	{
		delete mAllSpawnedBacterias;
		mAllSpawnedBacterias = NULL;
	}

	if(mCreatedWaves != NULL)
	{
		delete mCreatedWaves;
		mCreatedWaves = NULL;
	}*/

	std::list<Bacteria *>::iterator Iter;
	for(Iter = mBacteriaList.begin(); Iter != mBacteriaList.end(); Iter++)
		HAMURWORLD->DeleteObject((*Iter)->GetName());
}

void Wave::StartWave()
{
	Wave::mActiveWave = this;
	mStarted = true;
	mIsWaveFinished = false;
}

void Wave::Update( float deltaTime )
{
	if(mStarted)
	{
		if(mTimeCounter >= mSpawningInterval)
		{
			if (!mBacteriaList.empty())
			{
				std::list<Bacteria *>::iterator Iter = mBacteriaList.begin();
				(*Iter)->SetActive(true);
				(*Iter)->SetVisible(true);
				mAllSpawnedBacterias->push_back((*Iter));
				mBacteriaList.erase(Iter);
				mTimeCounter = 0;

				mTeeth->DecreaseShield(mSpawningInterval * 1000 / (12 * mTotalTimeOfWave));
			}
			else
				mIsWaveFinished = true;
		}

		mTimeCounter += deltaTime;
	}

}

void Wave::DeleteBacteria()
{
	list<Bacteria *>::iterator Iter;

	if(!mBacteriaList.empty())
	{
		for (Iter = mBacteriaList.begin(); Iter != mBacteriaList.end(); Iter++)
		{
			HAMURWORLD->DeleteObject((*Iter)->GetName());
		}

		mBacteriaList.clear();
	}
	/*if(!mSpawnedBacterias.empty())
	{

		for (Iter = mSpawnedBacterias.begin(); Iter != mSpawnedBacterias.end(); Iter++)
		{
			HAMURWORLD->DeleteObject((*Iter)->GetName());
		}
	}*/
}

void Wave::FillBacterias(int fattieCount, 
						 int normCount, int shooterCount, int slimCount, int strayerCount)
{
	int totalBactCount = fattieCount + normCount + shooterCount + slimCount + strayerCount;
	string name = GetName();
	HamurVec3 basePos = HAMURWORLD->GetHamurObject("Base")->GetPosition();

	for(int i = 0; i < totalBactCount; i++)
	{
		Bacteria *b = NULL;

		HamurString str;
		str << i;
		int randNumber = (int)(rand() % 5);

		if(fattieCount > 0 && randNumber == 0)
		{
			b = new BacteriaFattie(name + "/" + "FattieBact" + str.GetString(), "Graphics/Bact1/bact1", 3, basePos, 20);
			fattieCount--;
		}
		else if(normCount > 0 && randNumber == 1)
		{
			b = new BacteriaNorm(name + "/" + "NormBact" + str.GetString(), "Graphics/bact_normal/bact_norm", 3, basePos, 40);
			normCount--;
		}
		else if(shooterCount > 0 && randNumber == 2)
		{
			b = new BacteriaShooter(name + "/" + "ShooterBact" + str.GetString(), "Graphics/Bact_shooter/bact_shooter", 3, basePos, 40);
			shooterCount--;
		}
		else if(slimCount > 0 && randNumber == 3)
		{
			b = new BacteriaSlim(name + "/" + "SlimBact" + str.GetString(), "Graphics/slim", 1, basePos, 70);
			slimCount--;
		}
		else if(strayerCount > 0 && randNumber == 4)
		{
			b = new BacteriaStrayer(name + "/" + "StrayerBact" + str.GetString(), "Graphics/bact_strayer/bact_strayer", 4, basePos, 30);
			strayerCount--;
		}

		if(b != NULL)
		{
			b->SetActive(false);
			b->SetVisible(false);
			mBacteriaList.push_back(b);
		}
	}
}
/*

void Wave::DeleteAllWaveBacterias()
{
	std::list<Wave *>::iterator Iter;

	for(Iter = mCreatedWaves->begin(); Iter != mCreatedWaves->end(); Iter++)
		(*Iter)->DeleteBacteria();

	std::list<Bacteria *>::iterator Iter2;
	for(Iter2 = mAllSpawnedBacterias->begin(); Iter2 != mAllSpawnedBacterias->end(); Iter2++)
	{
		HAMURWORLD->DeleteObject((*Iter2)->GetName());
	}

	mAllSpawnedBacterias->clear();
}
*/
