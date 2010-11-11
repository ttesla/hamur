#include "IngameState.h"
using namespace hamur;

IngameState::IngameState() : HamurState("IngameState")
{
	
}

IngameState::~IngameState()
{
	//DELETE OBJECTS!
}

void IngameState::startBase()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	HamurVec3 c;
	
	c.x = w/2; c.y = h/2;
	base = new Base("Base");
	base->SetSelectedWeapon(BulletTypes::ToothPasteBulletType);
	base->SetPosition(c);
}

void IngameState::startTeeth()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	HamurVec3 c;
	
	c.x = w/2; c.y = h/2, c.z = -2.0;
	teeth = new Teeth("teeth", "Graphics/teeth.png", 100, 100);
	teeth->SetPosition(c);

	/****** TO BE CHANGED ******/
	
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
		t->SetVisible(false);
		allocatedTeeth.push_back(t);
		//activeObjList.push_front(allocatedTeeth[i]);
	}
	Tooth::SetTeeth(&allocatedTeeth);
	
}

void IngameState::startWave()
{
	//WaveDataReader dataReader("test.xml");
	WaveDataReader waveReader("Waves.xml");

	Level *l = new Level("level");
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject("Breakfast1"));
	l->Start();
}

void IngameState::startGUI()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	HamurVec3 c;

	c.x = 50; c.y = 50;
	currentFoodPanel = new Panel("currentFoodPanel", c, "Graphics/testfood.png", 120, 120);
	c.x = 0; c.y = 300; c.z = -2;
	timeLeftPanel = new Panel("timeLeftPanel", c, "", 10, 600, HamurColor::GREEN);
	c.x += 10;
	lifePanel = new Panel("lifePanel", c, "", 10, 600, HamurColor::RED);	
	c.x += 10;
	shieldPanel = new Panel("shieldPanel", c, "", 10, 600, HamurColor::BLUE);
	c.x = 40; c.y = 600-40; c.z = 0;
	waterButton = new Button("waterButton", c, "Graphics/testwater.png", 100, 100);
}

void IngameState::Enter()
{
	startBase();
	startTeeth();
	startWave();
	startGUI();
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

	// Shield and Life levels
	this->shieldPanel->SetHeight(Teeth::GetShield()*6);
	this->lifePanel->SetHeight(Teeth::GetHealth()*6);

}

void IngameState::Draw(float deltaTime)
{

}

void IngameState::Exit()
{

}