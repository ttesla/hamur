#include "Wave.h"
#include "BacteriaNorm.h"
#include "BacteriaFattie.h"
#include "BacteriaStrayer.h"
#include "BacteriaShooter.h"
#include "BacteriaSlim.h"

using namespace std;
using namespace hamur; 

Wave *Wave::mActiveWave = NULL;
list<Wave *> *Wave::mCreatedWaves = NULL;

Wave::Wave( const string& name, const HamurVec3 &basePos, int fattieCount, int normCount, int shooterCount, 
		   int slimCount, int strayerCount ) : HamurObject(name), mTimeCounter(0), mStarted(false)
{
	mCreatedWaves = new list<Wave *>;
	int totalBactCount = fattieCount + normCount + shooterCount + slimCount + strayerCount;
	mSpawningInterval = (30 * 1000) / totalBactCount;

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

	mCreatedWaves->push_back(this);
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
		if(SDL_GetTicks() - mTimeCounter >= mSpawningInterval)
		{
			if (!mBacteriaList.empty())
			{
				std::list<Bacteria *>::iterator Iter = mBacteriaList.begin();
				(*Iter)->SetActive(true);
				(*Iter)->SetVisible(true);
				mSpawnedBacterias.push_back((*Iter));
				mBacteriaList.erase(Iter);
				mTimeCounter = SDL_GetTicks();
			}
			else
				mIsWaveFinished = true;
		}
	}
}

void Wave::DeleteBacteria()
{
	list<Bacteria *>::iterator Iter;

	for (Iter = mBacteriaList.begin(); Iter != mBacteriaList.end(); Iter++)
	{
		HAMURWORLD->DeleteObject((*Iter)->GetName());
	}
	for (Iter = mSpawnedBacterias.begin(); Iter != mSpawnedBacterias.end(); Iter++)
	{
		HAMURWORLD->DeleteObject((*Iter)->GetName());
	}
}
