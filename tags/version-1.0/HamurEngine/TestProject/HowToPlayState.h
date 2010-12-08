#pragma once

#ifndef HOWTOPLAYSTATE_H
#define HOWTOPLAYSTATE_H

#include "hamur.h"
#include "hamurDefinitions.h"
#include "GUI.h"

using namespace hamur;
using namespace std;

class HowToPlayState : public HamurState
{
	public:
		HowToPlayState();
		~HowToPlayState();

		void Enter();
		void Update(float deltaTime);
		void Draw(float deltaTime);
		void Exit();

		void GoToNext();

	private:
		TextDataReader *tdr;
		Panel *background;
		Button *nextButton;
		int slide;

		void SetBackground(string path);
		//Text *titleText;
		//Text **mainText;
		//Button *doneButton;
		//Panel *titlePanel;
		//Panel *background;
};

#endif 