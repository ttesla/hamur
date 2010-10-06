#include "IngameState.h"
#include "Math.h"

using namespace hamur;

IngameState::IngameState() : HamurState("IngameState")
{
	killObj1 = NULL;
	killObj2 = NULL;
}

IngameState::~IngameState()
{
}

void IngameState::Enter()
{
	mPrevTickCount = 0;
	spawnedEnemyCount = 0;

	/**************
	*	BASE	**
	***************/
	Base* base = new Base("Base", this);
	activeObjList.push_front(base);
	
	/**************
	*	TEETH	**
	***************/
	allocatedTeeth = new Tooth*[MAXTEETH];
	float xInc, yInc, xBase, yBase;
	float a = 2*PI/MAXTEETH;
	xBase = base->GetPosition().x;
	yBase = base->GetPosition().y;
	xInc = 275;
	yInc = 200;

	for(int i = 0; i < MAXTEETH; i++)
	{
		string indexStr = "Tooth";
		HamurString str;
		str << i;
		allocatedTeeth[i] = new Tooth(indexStr + str.GetString());
		allocatedTeeth[i]->SetPosition((xBase-xInc)*cos(i*a) + xBase, (yBase-yInc)*sin(i*a) + yBase);
		activeObjList.push_front(allocatedTeeth[i]);
	}

	/*****************
	*	BACTERIAS	**
	******************/
	//We' re allocating all the enemies at the beginning of state for performance stuff:D
	//When the time comes, they will start to get update callback
	allocatedBacterias = new Bacteria*[MAXBACT];

	for(int i = 0; i < MAXBACT; i++)
	{
		string indexStr = "Bacteria";
		HamurString str;
		str << i;
		// We are going te allocate some different type bacterias
		if (i < MAXBACT / 5)
		{
			allocatedBacterias[i] = new BacteriaNorm(indexStr + str.GetString(), base->GetPosition());
		}
		else if (i < 2*MAXBACT / 5)
		{
			allocatedBacterias[i] = new BacteriaFattie(indexStr + str.GetString(), base->GetPosition());
		}
		else if (i < 3*MAXBACT / 5)
		{
			allocatedBacterias[i] = new BacteriaSlim(indexStr + str.GetString(), base->GetPosition());
		}
		else if (i < 4*MAXBACT / 5)
		{
			allocatedBacterias[i] = new BacteriaShooter(indexStr + str.GetString(), base->GetPosition());
		}
		else
		{
			allocatedBacterias[i] = new BacteriaStrayer(indexStr + str.GetString(), base->GetPosition());
		}

		//activeObjList.push_front(allocatedBacterias[i]);
		base->GetEnemiesList()->push_back(allocatedBacterias[i]);
	}
}

void IngameState::Update()
{
	//Time interval can be changed due to level difficulty. It' s the time interval between 
	//bacteria spawn
	if((SDL_GetTicks() - mPrevTickCount) >= 4000)
	{
		mPrevTickCount = SDL_GetTicks();
		activeObjList.push_front(allocatedBacterias[spawnedEnemyCount]);
		allocatedBacterias[spawnedEnemyCount]->SetActive(true);
		spawnedEnemyCount++;
	}

	//Iterating through the objects active in that state and update
	list<HamurObject *>::iterator Iter;
	for(Iter = activeObjList.begin(); Iter != activeObjList.end(); ++Iter)
	{
		(*Iter)->Update();
	}

	if(killObj1 != NULL)
	{
		activeObjList.remove(killObj1);
		HAMURWORLD->DeleteObject(killObj1->GetName());
		killObj1 = NULL;
	}
	if(killObj2 != NULL)
	{
		activeObjList.remove(killObj2);
		HAMURWORLD->DeleteObject(killObj2->GetName());
		killObj2 = NULL;
	}

}

void IngameState::Draw()
{

}

void IngameState::Exit()
{

}