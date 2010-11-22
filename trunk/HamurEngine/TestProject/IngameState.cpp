#include "IngameState.h"
using namespace hamur;

IngameState::IngameState() : HamurState("IngameState")
{
	toothBrushUses = 0;
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
	teeth = new Teeth("teeth", "Graphics/teeth.png", 1000, 1000);
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

	WaveDataReader waveReader("Waves.xml");

	string newLevelName = "mondayLevel";
	
	if(activeLevel != "")
	{
		teeth->SetHealth(mTeethHealth);
		teeth->SetShield(mTeethShield);

		if(activeLevel == "mondayLevel")
			newLevelName = "thursdayLevel";
		else if(activeLevel == "thursdayLevel")
			newLevelName = "saturdayLevel";
	}

	Level *l = (Level *)HAMURWORLD->GetHamurObject(newLevelName);

	//Snack waves after dinner wave
	if(foodSelection["snack6"] != "")
	{
		Wave *w = (Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack6"]);
		l->AddWave(w);
	}
	if(foodSelection["snack3"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack3"]));

	//Dinner wave
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["dinner"]));

	//Snack waves between lunch and dinner
	if(foodSelection["snack4"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack4"]));
	if(foodSelection["snack1"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack1"]));

	//Lunch wave
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["lunch"]));

	//Snack waves between breakfast and lunch
	if(foodSelection["snack5"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack5"]));
	if(foodSelection["snack2"] != "")
		l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["snack2"]));

	//Breakfast wave
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject(foodSelection["breakfast"]));

	l->Start();

	activeLevel = l->GetName();
	activeLevelPointer = l;

	l->SetActive(true);
}

void IngameState::startGUI()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	HamurVec3 c;

	c.x = 50; c.y = 50; //c.z = +10.0;
	
	HamurString s;

	/* EDU: needs to be checked if Level's active wave works properly 
	//Level *l = (Level*)HAMURWORLD->GetHamurObject(activeLevel);
	//Wave *wave = l->GetActiveWave(); 
	Wave *wave = Wave::GetActiveWave();
	cout << "---" << wave->GetName() << endl;
	*/

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
	//if (teeth->GetHealth() <= 0)
	//{
	//	HAMURSTATEMR->ChangeState("GameOverState");		
	//}
	//cout << "WAVE: " << Wave::GetActiveWave()->GetName() << endl;

	if (waterButton->isPushed())
	{
		base->UseWater();
	}
	else if(HAMUREVENT->IsMousePressed(Keys::Mouse::LeftButton))
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
	
	// Edu: Maybe we can save the pointer to the active level to avoid all this stuff 
	if (activeLevelPointer->IsLevelFinished())
	{
		HAMURSTATEMR->ChangeState("FeedbackState");
		static_cast<FeedbackState*>(HAMURSTATEMR->GetCurrentState())->SetFeedback(foodSelection, teeth->GetHealth(), teeth->GetShield(), toothBrushUses);
	}

	// Shield and Life levels
	this->shieldPanel->SetHeight(teeth->GetShield() / 1000 * 300);
	this->lifePanel->SetHeight(teeth->GetHealth() / 1000 * 300);
}

void IngameState::Draw(float deltaTime)
{

}

void IngameState::Exit()
{
	mTeethHealth = teeth->GetHealth();
	mTeethShield = teeth->GetShield();

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