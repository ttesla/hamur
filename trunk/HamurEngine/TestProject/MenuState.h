#pragma once

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "hamur.h"
#include "hamurDefinitions.h"
#include "GUI.h"

using namespace hamur;
using namespace std;

class MenuState : public HamurState
{
	public:
		MenuState();
		~MenuState();

		void Enter();
		void Update(float deltaTime);
		void Draw(float deltaTime);
		void Exit();

	private:
		Button *playButton;
		Button *optionsButton;
		Button *exitButton;
		Button *howToPlayButton;
		Panel *background;
};

#endif 