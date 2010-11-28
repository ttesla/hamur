#ifndef STORYSTATE_H
#define STORYSTATE_H

#pragma once

#include "hamur.h"
#include "hamurDefinitions.h"
#include "GUI.h"
#include <list>
#include "Level.h"

using namespace hamur;
using namespace std;

class StoryState : public HamurState
{
	public:
		StoryState();
		~StoryState();

		void Enter();
		void Update(float deltaTime);
		void Draw(float deltaTime);
		void Exit();

		//inline void SetGameFinished(const bool &isFinished) {mIsGameFinished = isFinished;}

	private:
		Panel *background;
		Button *nextButton;
		
};

#endif 