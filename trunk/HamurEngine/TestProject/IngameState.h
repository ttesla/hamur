#pragma once

#include "hamur.h"
#include "hamurDefinitions.h"
#include "Tooth.h"
#include "Math.h"
#include "Base.h"
#include "Wave.h"
#include "Level.h"
#include "WaveDataReader.h"
#include "Bullet.h"
#include "GUI.h"
#include <list>

using namespace hamur;
using namespace std;

class Bacteria;
class Base;

#define MAXBACT 16
#define MAXTEETH 16

class IngameState : public HamurState
{
public:
	IngameState();
	~IngameState();

	void Enter();
	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Exit();

private:
	Bacteria **allocatedBacterias;
	list<Tooth *> allocatedTeeth;
	int mPrevTickCount;
	int spawnedEnemyCount;
	Base *base;

	/****************
		INGAME GUI  *
	*****************/
	Panel *currentFoodPanel;
	Panel *timeLeftPanel;
	Panel *lifePanel;
	Panel *shieldPanel;
	Button *waterButton;
	
	void startBase();
	void startTeeth();
	void startWave();
	void startGUI();
};