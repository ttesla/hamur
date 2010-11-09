#ifndef FEEDBACKSTATE_H
#define FEEDBACKSTATE_H

#pragma once

#include "hamur.h"
#include "hamurDefinitions.h"
#include "GUI.h"

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
};

#endif 