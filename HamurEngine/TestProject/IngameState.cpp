#include "IngameState.h"

using namespace hamur;

IngameState::IngameState() : HamurState("IngameState")
{
	
}

IngameState::~IngameState()
{
	//DELETE OBJECTS!
}

void IngameState::LoadGame()
{
	mPrevTickCount = 0;
	spawnedEnemyCount = 0;

	/**************
	*	BASE	**
	***************/
		
	base = new Base("Base");
	base->SetSelectedWeapon(BulletTypes::ToothPasteBulletType);
	
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
	
	/**************
	*	WAVE	**
	***************/
	//WaveDataReader dataReader("test.xml");
	WaveDataReader waveReader("Waves.xml");

	Level *l = new Level("level");
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject("Breakfast1"));
	l->Start();
}

void IngameState::Enter()
{
	LoadGame();
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

	if(HAMUREVENT->IsKeyPressed(Keys::Key1))
	{
		base->SetSelectedWeapon(BulletTypes::ToothPasteBulletType);

	}
	else if(HAMUREVENT->IsKeyPressed(Keys::Key2))
	{
		base->SetSelectedWeapon(BulletTypes::FlossingBulletType);
	}
}

void IngameState::Draw(float deltaTime)
{

}

void IngameState::Exit()
{

}