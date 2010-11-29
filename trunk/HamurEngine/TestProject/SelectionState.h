#pragma once

#ifndef SELECTIONSTATE_H
#define SELECTIONSTATE_H

#include "hamur.h"
#include "hamurDefinitions.h"
#include "FeedbackInfo.h"
#include "GUI.h"
#include <list>

using namespace hamur;
using namespace std;

class SelectionState : public HamurState
{
	public:
		SelectionState();
		~SelectionState();

		void Enter();
		void Update(float deltaTime);
		void Draw(float deltaTime);
		void Exit();

	private:
		/*
		Text *chooseText;
		Text *breakfastText;
		Text *lunchText;
		Text *dinnerText;
		Text *snacksText;
		*/

		Panel *chooseTextPanel;
		Panel *breakfastTextPanel;
		Panel *lunchTextPanel;
		Panel *dinnerTextPanel;
		Panel *snacksTextPanel;

		Panel *breakfastPanel;
		Panel *lunchPanel;
		Panel *dinnerPanel;

		vector<Button *> snackButtons;
		Button *startButton;

		int snacksNumber; // Could be removed..
		Panel *background;

		map<string, string> foodSelection;

		int mSelectedSnackCount; //SelectedSnackCount

		string mBreakfastIndex;
		string mLunchIndex;
		string mDinnerIndex;

		void createMenu();
};

#endif 