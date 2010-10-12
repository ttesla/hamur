#include "IngameState.h"
#include "Math.h"
#include "Base.h"
#include "Wave.h"

using namespace hamur;

IngameState::IngameState() : HamurState("IngameState")
{

}

IngameState::~IngameState()
{
}

void IngameState::Enter()
{
	mPrevTickCount = 0;
	spawnedEnemyCount = 0;

	/**************
	*	BASE	**
	***************/
	base = new Base("Base");
	//activeObjList.push_front(base);
	
	/**************
	*	TEETH	**
	***************/
	//allocatedTeeth = new Tooth*[MAXTEETH];
	float xInc, yInc, xBase, yBase;
	float a = 2*PI/MAXTEETH;
	xBase = base->GetPosition().x;
	yBase = base->GetPosition().y;
	xInc = 275;
	yInc = 200;

	for(int i = 0; i < MAXTEETH; i++)
	{
		string indexStr = "Tooth";
		HamurString str;
		str << i;
		Tooth *t = new Tooth(indexStr + str.GetString());
		t->SetPosition((xBase-xInc)*cos(i*a) + xBase, (yBase-yInc)*sin(i*a) + yBase);
		allocatedTeeth.push_back(t);
		//activeObjList.push_front(allocatedTeeth[i]);
	}
	Tooth::SetTeeth(&allocatedTeeth);


	Wave *w = new Wave("Wave", base->GetPosition(), 3, 3, 3, 3, 3);
	w->StartWave();
}

void IngameState::Update(float deltaTime)
{
	if(HAMUREVENT->IsMousePressed(Keys::Mouse::LeftButton))
	{
		base->Fire(HamurVec3(HAMUREVENT->GetMouseX(), HAMUREVENT->GetMouseY(), 0));
	}

	if(HAMUREVENT->IsKeyPressed(Keys::Escape))
	{
		HAMURENGINE->Stop();
	}

}

void IngameState::Draw(float deltaTime)
{

}

void IngameState::Exit()
{

}