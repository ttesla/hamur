#pragma once

#include "hamur.h"

class Teeth;

class IngameState : public hamur::HamurState
{
public:
	IngameState() : hamur::HamurState("IngameState"){}
	~IngameState();

	void Enter();
	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Exit();

private:
	Teeth *playerTeeth;
};