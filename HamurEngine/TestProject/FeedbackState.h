#ifndef FEEDBACKSTATE_H
#define FEEDBACKSTATE_H

#pragma once

#include "hamur.h"
#include "hamurDefinitions.h"
#include "GUI.h"
#include "FeedbackInfo.h"
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

		void SetFeedback();
		inline void SetGameFinished(const bool &isFinished) {mIsGameFinished = isFinished;}

	private:
		Text *goodText;
		Text *normalText;
		Text *badText;
		Text *shieldsText;
		Text *shieldsValueText;
		Panel *shieldsPanel;
		Text *lifeText;
		Text *lifeValueText;
		Panel *lifePanel;

		vector<Panel *> goodPanels;
		vector<Panel *> normalPanels;
		vector<Panel *> badPanels;
		Text *fbText; // The feedback message
		Button *okButton; // To exit to the menu again
		Panel *characterPanel; 
		Panel *background;

		// To generate feedback infoff
		bool mIsGameFinished;
		// Select the proper feedback according to the variables above
		string chooseFeedback();
};

#endif 