#ifndef FEEDBACKSTATE_H
#define FEEDBACKSTATE_H

#pragma once

#include "hamur.h"
#include "hamurDefinitions.h"
#include "GUI.h"
#include <list>

using namespace hamur;
using namespace std;

class FeedbackState : public HamurState
{
	public:
		FeedbackState();
		~FeedbackState();

		void Enter();
		void Update(float deltaTime);
		void Draw(float deltaTime);
		void Exit();

		void SetFeedBack(list<string> selection, float health, float shield, int toothBrushUses);

	private:
		Text *goodText;
		Text *normalText;
		Text *badText;
		Text *shieldsText;
		Text *lifeText;
		int goodNumber;
		int normalNumber;
		int badNumber;
		vector<Panel *> goodPanels;
		vector<Panel *> normalPanels;
		vector<Panel *> badPanels;
		Text *fbText; // The feedback message
		Button *okButton; // To exit to the menu again
		Panel *characterPanel; 
		Panel *background;

		// To generate feedback info
		list<string> foodSelection;
		float health;
		float shield;
		int toothBrushUses;
		// Select the proper feedback according to the variables above
		string chooseFeedback();
};

#endif 