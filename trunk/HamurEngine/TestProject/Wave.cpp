#include "Wave.h"
#include "BacteriaNorm.h"
#include "BacteriaFattie.h"
#include "BacteriaStrayer.h"
#include "BacteriaShooter.h"
#include "BacteriaSlim.h"


using namespace std;
using namespace hamur; 

Wave *Wave::mActiveWave = NULL;

Wave::Wave( const string& name, const HamurVec3 &basePos, int fattieCount, int normCount, int shooterCount, 
		   int slimCount, int strayerCount ) : HamurObject(name), mTimeCounter(0)
{
	int totalBactCount = fattieCount + normCount + shooterCount + slimCount + strayerCount;

	for(int i = 0; i < totalBactCount; i++)
	{
		Bacteria *b = NULL;

		HamurString str;
		str << i;

		if(fattieCount > 0)
		{
			b = new BacteriaFattie("FattieBact" + str.GetString(), basePos, 50);
			fattieCount--;
		}
		else if(normCount > 0)
		{
			b = new BacteriaNorm("NormBact" + str.GetString(), basePos, 50);
			normCount--;
		}
		else if(shooterCount > 0)
		{
			b = new BacteriaShooter("ShooterBact" + str.GetString(), basePos, 50);
			shooterCount--;
		}
		else if(slimCount > 0)
		{
			b = new BacteriaSlim("SlimBact" + str.GetString(), basePos, 50);
			slimCount--;
		}
		else if(strayerCount > 0)
		{
			b = new BacteriaStrayer("StrayerBact" + str.GetString(), basePos, 50);
			strayerCount--;
		}

		if(b != NULL)
		{
			b->SetActive(false);
			mBacteriaList.push_back(b);
		}
	}
}

void Wave::StartWave()
{
	Wave::mActiveWave = this;
	mStarted = true;
}

void Wave::Update( float deltaTime )
{
	if(mStarted)
	{
/*
		mTimeCounter += deltaTime;

		if(mTimeCounter >= 3000)
		{
			
		}
*/

		if(SDL_GetTicks() - mTimeCounter >= 3000)
		{
			if (!mBacteriaList.empty())
			{
				std::list<Bacteria *>::iterator Iter = mBacteriaList.begin();
				(*Iter)->SetActive(true);
				mSpawnedBacterias.push_back((*Iter));
				mBacteriaList.erase(Iter);
				mTimeCounter = SDL_GetTicks();
			}
		}

	}
}