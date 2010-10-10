#pragma once

#include "hamur.h"
#include "hamurDefinitions.h"
#include "Tooth.h"
#include <list>

using namespace hamur;
using namespace std;

class Bacteria;
class Base;

#define MAXBACT 16
#define MAXTEETH 16

class IngameState : public HamurState
{
public:
	IngameState();
	~IngameState();


	void Enter();
	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Exit();


	inline list<HamurObject *> *GetActiveObjList(){return &activeObjList;}


	//When the bacteria shot, this pointers are set by bullet object.
	//Very creepy from the point of software engineering, isn' t it:D:D
	HamurObject *killObj1;
	HamurObject *killObj2;

private:
	list<HamurObject *> activeObjList;
	Bacteria **allocatedBacterias;
	Tooth **allocatedTeeth;
	int mPrevTickCount;
	int spawnedEnemyCount;
	Base *base;
};