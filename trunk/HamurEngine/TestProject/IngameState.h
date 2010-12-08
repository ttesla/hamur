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
#include "FeedbackInfo.h"
#include "Window.h"

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

	void GoToFeedbackState();
	void GoToGameOverState();
	void ActivateBrush(const bool &isActive);
	void ShowWaveText(const string &waveName);

private:
	Bacteria **allocatedBacterias;
	list<Tooth *> allocatedTeeth;
	float mTeethHealth;
	float mTeethShield;
	int mPrevTickCount;
	int spawnedEnemyCount;
	Base *base;
	Teeth *teeth;
	float mWaveTextTimer;

	/****************
		INGAME GUI  *
	*****************/
	Panel *ingameGUI;

	Window *escapeWindow;
	Panel *currentFoodPanel;
	Panel *coverPanel;
	Panel *timeLeftPanel;
	Panel *lifePanel;
	Panel *shieldPanel;
	Button *waterButton;
	Button *brushButton;
	Text *brushText;
	Text *waveText;

	Text *currentWaveText;

	// For the bacteria count
	Panel *stP; Text *st;
	Panel *slP; Text *sl;
	Panel *shP; Text *sh;
	Panel *noP; Text *no;
	Panel *faP; Text *fa;

	//Levels
	Level *mondayLevel;
	Level *thursdayLevel;
	Level *saturdayLevel;
	//string activeLevel;
	
	void startSound();
	void startBase();
	void startTeeth();
	void createLevel();
	void startGUI(); 
		void showBacteriaCount();
	void openEscapeWindow();
	void closeEscapeWindow();

	int toothBrushUses;

	bool escapeWindowShowing;
};