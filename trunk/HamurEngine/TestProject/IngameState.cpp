#include "IngameState.h"
#include "Math.h"
#include "Base.h"
#include "Wave.h"
#include "Button.h"
#include "Level.h"
#include "WaveDataReader.h"
#include "Bullet.h"

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
	base->SetSelectedWeapon(BulletTypes::FlossingBulletType);
	
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
	WaveDataReader dataReader("Waves.xml");

	Level *l = new Level("level");
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject("Breakfast1"));
	l->Start();

	/**************
	*	BUTTONS	**
	**************/
	GUIElement *button1 = new Button("Button1");
	button1->SetHeight(40.0);
	button1->SetWidth(80.0);
	button1->SetPosition(100, 100);
	//button1->SetSprite("../WorkingDir/button.bmp", 200, 100, 20);

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