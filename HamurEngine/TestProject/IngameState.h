#pragma once

#include "hamur.h"
#include "hamurDefinitions.h"
#include "Teeth.h"
#include "Tooth.h" // TO BE CHANGED
#include "Math.h"
#include "Base.h"
#include "Wave.h"
#include "Level.h"
#include "WaveDataReader.h"
#include "Bullet.h"
#include "GUI.h"
#include <list>
#include "FeedbackState.h"

using namespace hamur;
using namespace std;

class Bacteria;
class Base;

#define MAXBACT 16
#define MAXTEETH 25

class IngameState : public HamurState
{
public:
	IngameState();
	~IngameState();

	void Enter();
	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Exit();

	void SetFoodSelection(const map<string, string> &l);
	void GoToFeedbackState();

private:
	Bacteria **allocatedBacterias;
	list<Tooth *> allocatedTeeth;
	float mTeethHealth;
	float mTeethShield;
	int mPrevTickCount;
	int spawnedEnemyCount;
	Base *base;
	Teeth *teeth;

	/****************
		INGAME GUI  *
	*****************/
	Panel *currentFoodPanel;
	Panel *timeLeftPanel;
	Panel *lifePanel;
	Panel *shieldPanel;
	Button *waterButton;
	Button *brushButton;

	//Levels
	Level *mondayLevel;
	Level *thursdayLevel;
	Level *saturdayLevel;
	string activeLevel;
	
	void startBase();
	void startTeeth();
	void createLevel();
	void startGUI();

	map<string, string> foodSelection;
	int toothBrushUses;
};