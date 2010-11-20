#include "IngameState.h"
using namespace hamur;

IngameState::IngameState() : HamurState("IngameState")
{

}

IngameState::~IngameState()
{
}

void IngameState::startBase()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	HamurVec3 c;
	
	c.x = w/2; c.y = h/2;
	base = new Base("Base");
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

void IngameState::createLevel()
{
	mondayLevel = new Level("mondayLevel"); mondayLevel->SetActive(false);
	thursdayLevel = new Level("thursdayLevel"); thursdayLevel->SetActive(false);
	saturdayLevel = new Level("saturdayLevel"); saturdayLevel->SetActive(false);
	activeLevel = NULL;

	WaveDataReader waveReader("Waves.xml");

	string newLevelName = "mondayLevel";
	
	if(activeLevel != NULL)
	{
		if(activeLevel->GetName() == "mondayLevel")
			newLevelName = "thursdayLevel";
		else if(activeLevel->GetName() == "thursdayLevel")
			newLevelName = "saturdayLevel";
	}

	Level *l = (Level *)HAMURWORLD->GetHamurObject(newLevelName);

	//Breakfast wave
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["breakfast"]));
	
	//Snack waves between breakfast and lunch
	if(foodSelection["snack2"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack2"]));
	if(foodSelection["snack5"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack5"]));

	//Lunch wave
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["lunch"]));

	//Snack waves between lunch and dinner
	if(foodSelection["snack1"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack1"]));
	if(foodSelection["snack4"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack4"]));

	//Dinner wave
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["dinner"]));

	//Snack waves after dinner wave
	if(foodSelection["snack3"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack3"]));
	if(foodSelection["snack6"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack6"]));

	l->Start();

	activeLevel = l;
	activeLevel->SetActive(true);
}

void IngameState::startGUI()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	HamurVec3 c;

	c.x = 50; c.y = 50; c.z = +10.0;
	currentFoodPanel = new Panel("currentFoodPanel", c, "Graphics/testfood.png", 120, 120);
	c.x = 20; c.y = 300; 
	timeLeftPanel = new Panel("timeLeftPanel", c, "", 10, 300, HamurColor::GREEN);
	c.x += 10;
	lifePanel = new Panel("lifePanel", c, "", 10, 300, HamurColor::RED);	
	c.x += 10;
	shieldPanel = new Panel("shieldPanel", c, "", 10, 300, HamurColor::BLUE);
	c.x = 40; c.y = 600-40;
	waterButton = new Button("waterButton", c, "Graphics/testwater.png", 100, 100);
}

void IngameState::Enter()
{
	startBase();
	startTeeth();
	startGUI();
}

void IngameState::Update(float deltaTime)
{
	if (Teeth::GetHealth() <= 0)
	{
		HAMURSTATEMR->ChangeState("GameOverState");		
	}
	if (waterButton->isPushed())
	{
		base->UseWater();	
	}
	if(HAMUREVENT->IsMousePressed(Keys::Mouse::LeftButton))
	{
		base->Fire(HamurVec3(HAMUREVENT->GetMouseX(), HAMUREVENT->GetMouseY(), 0), BulletTypes::ToothPasteBulletType);
	}

	if(HAMUREVENT->IsMousePressed(Keys::Mouse::RightButton))
	{
		base->Fire(HamurVec3(HAMUREVENT->GetMouseX(), HAMUREVENT->GetMouseY(), 0), BulletTypes::FlossingBulletType);
	}

	if(HAMUREVENT->IsKeyPressed(Keys::Escape))
	{
		HAMURENGINE->Stop();
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
	// GUI
	HAMURWORLD->DeleteObject("currentFoodPanel");
	HAMURWORLD->DeleteObject("timeLeftPanel");
	HAMURWORLD->DeleteObject("lifePanel");
	HAMURWORLD->DeleteObject("shieldPanel");
	HAMURWORLD->DeleteObject("waterButton");
	
	{
		list<Tooth *>::iterator Iter;
		for (Iter = allocatedTeeth.begin(); Iter != allocatedTeeth.end(); Iter++)
		{
			HAMURWORLD->DeleteObject((*Iter)->GetName());
		}
	}

	// OBJECTS
	HAMURWORLD->DeleteObject(base->GetName());
	HAMURWORLD->DeleteObject(teeth->GetName());
	HAMURWORLD->DeleteObject(mondayLevel->GetName());
	HAMURWORLD->DeleteObject(thursdayLevel->GetName());
	HAMURWORLD->DeleteObject(saturdayLevel->GetName());

	std::list<Wave *> *waves = Wave::CreatedWaves();
	std::list<Wave *>::iterator Iter;
	for(Iter = waves->begin(); Iter != waves->end(); Iter++)
		HAMURWORLD->DeleteObject((*Iter)->GetName());
	waves->clear();

	std::list<Bacteria *> *bact = Wave::GetAllSpawnedBacterias();
	std::list<Bacteria *>::iterator Iter2;
	for(Iter2 = bact->begin(); Iter2 != bact->end(); Iter2++)
		HAMURWORLD->DeleteObject((*Iter2)->GetName());
	bact->clear();

}

void IngameState::SetFoodSelection(map<string, string> l)
{
	foodSelection = l;
	createLevel();
}