#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#pragma once

#include "hamur.h"
#include "hamurDefinitions.h"
#include "GUI.h"

using namespace hamur;
using namespace std;

class GameOverState : public HamurState
{
	public:
		GameOverState();
		~GameOverState();

		void Enter();
		void Update(float deltaTime);
		void Draw(float deltaTime);
		void Exit();

	private:
		Panel *gameOverPanel;
		Button *okButton; 
		Panel *background;
};

#endif 