#include "IngameState.h"
#include "Math.h"
#include "Base.h"
#include "Wave.h"

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
	base = new Base("Base");
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
/*
	allocatedBacterias = new Bacteria*[MAXBACT];

	for(int i = 0; i < MAXBACT; i++)
	{
		string indexStr = "Bacteria";
		HamurString str;
		str << i;
		// We are going te allocate some different type bacterias
		if (i < MAXBACT / 5)
		{
			allocatedBacterias[i] = new BacteriaNorm(indexStr + str.GetString(), base->GetPosition(), 50);
		}
		else if (i < 2*MAXBACT / 5)
		{
			allocatedBacterias[i] = new BacteriaFattie(indexStr + str.GetString(), base->GetPosition(), 50);
		}
		else if (i < 3*MAXBACT / 5)
		{
			allocatedBacterias[i] = new BacteriaSlim(indexStr + str.GetString(), base->GetPosition(), 50);
		}
		else if (i < 4*MAXBACT / 5)
		{
			allocatedBacterias[i] = new BacteriaShooter(indexStr + str.GetString(), base->GetPosition(), 50);
		}
		else
		{
			allocatedBacterias[i] = new BacteriaStrayer(indexStr + str.GetString(), base->GetPosition(), 50);
		}

		allocatedBacterias[i]->SetActive(false);
		//activeObjList.push_front(allocatedBacterias[i]);
		base->GetEnemiesList()->push_back(allocatedBacterias[i]);
	}*/


	Wave *w = new Wave("Wave", base->GetPosition(), 3, 3, 3, 3, 3);
	w->StartWave();
}

void IngameState::Update(float deltaTime)
{
	//Time interval can be changed due to level difficulty. It' s the time interval between 
	//bacteria spawn
/*
	if((SDL_GetTicks() - mPrevTickCount) >= 4000)
	{
		mPrevTickCount = SDL_GetTicks();
		activeObjList.push_front(allocatedBacterias[spawnedEnemyCount]);
		allocatedBacterias[spawnedEnemyCount]->SetActive(true);
		spawnedEnemyCount++;
	}*/


	
	if(HAMUREVENT->IsMousePressed(Keys::Mouse::LeftButton))
	{
		base->Fire(HamurVec3(HAMUREVENT->GetMouseX(), HAMUREVENT->GetMouseY(), 0));
	}

	if(HAMUREVENT->IsKeyPressed(Keys::Escape))
	{
		HAMURENGINE->Stop();
	}

	//if(killObj1 != NULL)
	//{
	//	activeObjList.remove(killObj1);
	//	HAMURWORLD->DeleteObject(killObj1->GetName());
	//	killObj1 = NULL;
	//}
	//if(killObj2 != NULL)
	//{
	//	activeObjList.remove(killObj2);
	//	HAMURWORLD->DeleteObject(killObj2->GetName());
	//	killObj2 = NULL;
	//}

}

void IngameState::Draw(float deltaTime)
{

}

void IngameState::Exit()
{

}