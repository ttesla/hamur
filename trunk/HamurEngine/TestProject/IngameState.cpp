#include "IngameState.h"
using namespace hamur;

IngameState::IngameState() : HamurState("IngameState")
{
	toothBrushUses = 0;
}

IngameState::~IngameState()
{

}

void IngameState::startSound()
{
	HAMURAUMR->AddFX("waterGlassFX", "Sounds/WaterGlassUse.wav");
	HAMURAUMR->AddFX("brushingTeeth", "Sounds/brushing_teeth.wav");
	HAMURAUMR->AddFX("bacteriaDeath", "Sounds/bacteria_death.wav");
}

void IngameState::startBase()
{
	base = new Base("Base", "Graphics/base.png");
}

void IngameState::startTeeth()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	HamurVec3 c;
	
	c.x = w/2; c.y = h/2; c.z = -1;
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
	map<string, string> foodSelection = FeedbackInfo::GetInstance()->GetFoodSelection();

	mondayLevel = new Level("mondayLevel"); mondayLevel->SetActive(false);
	thursdayLevel = new Level("thursdayLevel"); thursdayLevel->SetActive(false);
	saturdayLevel = new Level("saturdayLevel"); saturdayLevel->SetActive(false);
			
	WaveDataReader waveReader("Waves.xml");

	string newLevelName = "mondayLevel";
	
	if(Level::mActiveLevel != "")
	{
		teeth->SetHealth(mTeethHealth);
		teeth->SetShield(mTeethShield);

		if(Level::mActiveLevel == "mondayLevel")
			newLevelName = "thursdayLevel";
		else if(Level::mActiveLevel == "thursdayLevel")
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

	Level::mActiveLevel = l->GetName();
	//activeLevel = l->GetName(); Not necessary anymore

	l->SetActive(true);
}

void IngameState::startGUI()
{
	escapeWindowShowing = false;

	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	HamurVec3 c;

	/* FOR THE TEXT SHOWING THE WAVE
	c.x = w/2; c.y = h/2; 
	currentWaveText = new Text("currentWaveText", Wave::GetActiveWave()->GetName(), "Fonts/LambadaDexter.ttf", 100, c, HamurColorRGB::GREEN);
	currentWaveText->SetTransparency(0.5);
	*/

	string root = "Graphics/";

	// Window (appears when escape is pushed)
	c.x = w/2; c.y = h/2; c.z = 5;
	ingameGUI = new Panel("ingameGUI", c, "Graphics/ingameGUI.png", 800, 600);
	ingameGUI->ScaleSprite(1.38, 1.38);
	c.z = 0;
	string s = "Graphics/Food/" + Wave::GetActiveWave()->GetName() + ".png";
	c.x = 40; c.y = 40; c.z = 10;
	currentFoodPanel = new Panel("currentFoodPanel", c, s, 120, 120);
	currentFoodPanel->ScaleSprite(1.38, 1.38);
	c.z = 10;
	coverPanel = new Panel("coverPanel", c, "Graphics/currentfoodover.png",100,100);
	coverPanel->ScaleSprite(1.38, 1.38);
	coverPanel->SetTransparency(0.5);
	c.x = 19; c.y = 312; c.z = 10;
	timeLeftPanel = new Panel("timeLeftPanel", c, root + "greenbar.png", 10, 300);
	timeLeftPanel->SetVisible(false);
	c.x += 4;
	lifePanel = new Panel("lifePanel", c, root + "redbar.png", 10, 300);
	c.x += 21;
	shieldPanel = new Panel("shieldPanel", c, root + "bluebar.png", 10, 300);
	c.x = 40; c.y = 600-40;
	waterButton = new Button("waterButton", c, "Graphics/waterbutton.png", 100, 100);
	waterButton->SetHover(false);
	c.x = 750; c.y = 600-40;
	brushButton = new Button("brushButton", c, "Graphics/brush2.png", 100, 100);
	c.x = HamurOpenGL::GetInstance()->GetScreenWidth() / 2;
	c.y = HamurOpenGL::GetInstance()->GetScreenHeight() / 2 - 100;
	brushText = new Text("brushText", "Brush Time!", "Fonts/LambadaDexter.ttf", 40, c, HamurColorRGB::BLACK);
	ActivateBrush(false);

	c.x = 750; c.y = 30; c.z = 15;
	stP = new Panel ("stPanel", c, "Graphics/bact_strayer/bact_strayer_0.png", 20, 20);
	c.x += 20;
	string font = "Fonts/LambadaDexter.ttf";
	st = new Text("stcount", HamurString::ParseInt(0).GetString(), font, 20, c, HamurColorRGB::BLACK);
	c.y += 30;
	c.x -= 20; 
	slP = new Panel ("slPanel", c, "Graphics/slim_0.png", 20, 20);
	c.x += 20;
	sl = new Text("slcount", HamurString::ParseInt(0).GetString(), font, 20, c, HamurColorRGB::BLACK);
	c.y += 30;
	c.x -= 20;
	shP = new Panel ("shPanel", c, "Graphics/bact_shooter/bact_shooter_0.png", 20, 20);
	c.x += 20;
	sh = new Text("shcount", HamurString::ParseInt(0).GetString(), font, 20, c, HamurColorRGB::BLACK);
	c.y += 30;
	c.x -= 20;
	noP = new Panel ("noPanel", c, "Graphics/bact_normal/bact_norm_0.png", 20, 20);
	c.x += 20;
	no = new Text("nocount", HamurString::ParseInt(0).GetString(), font, 20, c, HamurColorRGB::BLACK);
	c.y += 30;
	c.x -= 20;
	noP = new Panel ("faPanel", c, "Graphics/bact1/bact1_0.png", 20, 20);
	c.x += 20;
	fa = new Text("facount", HamurString::ParseInt(0).GetString(), font, 20, c, HamurColorRGB::BLACK);
}

void IngameState::Enter()
{
	toothBrushUses = 0;
	waveText = NULL;

	startSound();
	startBase();
	startTeeth();
	createLevel();
	startGUI();

	//static_cast<Level *>(HAMURWORLD->GetHamurObject(Level::mActiveLevel))->Start();
	//static_cast<Level *>(HAMURWORLD->GetHamurObject(Level::mActiveLevel))->SetActive(true);

	mWaveTextTimer = 3;
}

void IngameState::showBacteriaCount()
{
	// NUMBER OF BACTERIAS SPAWNED
	int strayerCount, slimCount, shooterCount, normCount, fattieCount;
	strayerCount = slimCount = shooterCount = normCount = fattieCount = 0;

	list<Bacteria *> *bact = Wave::GetAllSpawnedBacterias();
	list<Bacteria *>::iterator it;
	for (it = bact->begin(); it != bact->end(); it++)
	{
		if ((*it)->GetType() == "strayer")
		{
			strayerCount++;	
		}
		else if ((*it)->GetType() == "slim")
		{
			slimCount++;
		}
		else if ((*it)->GetType() == "shooter")
		{
			shooterCount++;
		}
		else if ((*it)->GetType() == "norm")
		{
			normCount++;
		}
		else if ((*it)->GetType() == "fattie")
		{
			fattieCount++;
		}
	}

	/*
	cout << "BACTERIAS: " << endl;
	cout << "strayer: " << strayerCount << endl;
	cout << "slim: " << slimCount << endl;
	cout << "shooter: " << shooterCount << endl;
	cout << "norm: " << normCount << endl;
	cout << "fattie: " << fattieCount << endl;
	cout << "--------------" << endl;
	*/

	st->SetText(HamurString::ParseInt(strayerCount).GetString());
	sh->SetText(HamurString::ParseInt(shooterCount).GetString());
	sl->SetText(HamurString::ParseInt(slimCount).GetString());
	no->SetText(HamurString::ParseInt(normCount).GetString());
	fa->SetText(HamurString::ParseInt(fattieCount).GetString());
}

void IngameState::Update(float deltaTime)
{
	showBacteriaCount();

	if (waterButton->isPushed())
	{
		HAMURAUMR->PlayFX("waterGlassFX");
		base->UseWater();
	}
	else if(brushButton->isPushed() && brushButton->IsActive())
	{
		HAMURAUMR->PlayFX("brushingTeeth");
		base->UseBrush();
		ActivateBrush(false);
		toothBrushUses++;
	}
	else if(HAMUREVENT->IsMouseDown(Keys::Mouse::LeftButton))
	{
		base->Fire(HamurVec3(HAMUREVENT->GetMouseX(), HAMUREVENT->GetMouseY(), 0), BulletTypes::ToothPasteBulletType);
	}

	if(HAMUREVENT->IsMouseDown(Keys::Mouse::RightButton))
	{
		base->Fire(HamurVec3(HAMUREVENT->GetMouseX(), HAMUREVENT->GetMouseY(), 0), BulletTypes::FlossingBulletType);
	}

	if(HAMUREVENT->IsKeyPressed(Keys::Escape))
	{
		if (!escapeWindowShowing)
		{
			openEscapeWindow();
		}
		else
		{
			closeEscapeWindow();
		}
	}
	
	if (escapeWindowShowing)
	{
		if (escapeWindow->closeButton->isPushed())
		{
			closeEscapeWindow();
		}
		else if(dynamic_cast<Button*>(HAMURWORLD->GetHamurObject("escapeWindowb1"))->isPushed()) // Quit
		{
			HAMURENGINE->Stop();
		}
		else if(dynamic_cast<Button*>(HAMURWORLD->GetHamurObject("escapeWindowb2"))->isPushed()) // BackToMenu
		{
			closeEscapeWindow();
			Level::mActiveLevel = "";
			HAMURSTATEMR->ChangeState("MenuState");
		}
		else if(dynamic_cast<Button*>(HAMURWORLD->GetHamurObject("escapeWindowb3"))->isPushed()) // Return
		{
			closeEscapeWindow();
		}
	}

	//Shield and Life levels
	float s = teeth->GetShield();
	float l = teeth->GetHealth();
	if (s > 0)
		shieldPanel->ScaleSprite(1.0, (s * 0.3 / 300));
	else
		shieldPanel->ScaleSprite(1, 0);
	if (l > 0)
		lifePanel->ScaleSprite(1.0, (l * 0.3 / 300));
	else
		lifePanel->ScaleSprite(1, 0);

	if (l < 0)
	{
		GoToGameOverState();
	}

	if (waveText != NULL)
	{
		if(waveText->IsVisible())
		{
			mWaveTextTimer -= deltaTime;
	
			if(mWaveTextTimer <= 0)
			{
				mWaveTextTimer = 3;
				waveText->SetVisible(false);
			}
		}
	}

	// Current food panel update
	string str = "Graphics/Food/" + Wave::GetActiveWave()->GetName() + ".png";
	currentFoodPanel->SetSprite(str);
}

void IngameState::Draw(float deltaTime)
{

}

void IngameState::Exit()
{
	mTeethHealth = teeth->GetHealth();
	mTeethShield = teeth->GetShield();

	// GUI
	HAMURWORLD->DeleteObject("ingameGUI");
	HAMURWORLD->DeleteObject("currentFoodPanel");
	HAMURWORLD->DeleteObject("coverPanel");
	HAMURWORLD->DeleteObject("timeLeftPanel");
	HAMURWORLD->DeleteObject("lifePanel");
	HAMURWORLD->DeleteObject("shieldPanel");
	HAMURWORLD->DeleteObject("waterButton");
	HAMURWORLD->DeleteObject("brushButton");
	HAMURWORLD->DeleteObject("brushText");
	HAMURWORLD->DeleteObject("waveText");
	
	HAMURWORLD->DeleteObject("stPanel");
	HAMURWORLD->DeleteObject("shPanel");
	HAMURWORLD->DeleteObject("slPanel");
	HAMURWORLD->DeleteObject("noPanel");
	HAMURWORLD->DeleteObject("faPanel");
	HAMURWORLD->DeleteObject("stcount");
	HAMURWORLD->DeleteObject("shcount");
	HAMURWORLD->DeleteObject("slcount");
	HAMURWORLD->DeleteObject("nocount");
	HAMURWORLD->DeleteObject("facount");
	
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

void IngameState::GoToFeedbackState()
{
	//fbState->SetFeedback(foodSelection, teeth->GetHealth(), teeth->GetShield(), toothBrushUses);

	if (Level::mActiveLevel == "mondayLevel")
	{
		FeedbackInfo::GetInstance()->SetHealth(0, teeth->GetHealth());
		FeedbackInfo::GetInstance()->SetShield(0, teeth->GetShield());
	}	
	else if (Level::mActiveLevel == "thursdayLevel")
	{
		FeedbackInfo::GetInstance()->SetHealth(1, teeth->GetHealth());
		FeedbackInfo::GetInstance()->SetShield(1, teeth->GetShield());
	}
	else if (Level::mActiveLevel == "saturdayLevel")
	{
		FeedbackInfo::GetInstance()->SetHealth(2, teeth->GetHealth());
		FeedbackInfo::GetInstance()->SetShield(2, teeth->GetShield());
	}

	FeedbackInfo::GetInstance()->SetToothBrushUses(toothBrushUses);

	HAMURSTATEMR->ChangeState("FeedbackState");
	FeedbackState *fbState = static_cast<FeedbackState*>(HAMURSTATEMR->GetCurrentState());

	if(Level::mActiveLevel == "saturdayLevel")
		fbState->SetGameFinished(true);
	else
		fbState->SetGameFinished(false);
}

void IngameState::GoToGameOverState()
{
	Level::mActiveLevel = "";
	HAMURSTATEMR->ChangeState("GameOverState");
}

void IngameState::openEscapeWindow()
{
	HamurVec3 c; string root = "Graphics/";
	c.x = HAMURGL->GetScreenWidth()/2; c.y = HAMURGL->GetScreenHeight()/2; 

	escapeWindow = new Window("escapeWindow", c, 400, 300);
	escapeWindow->SetTitle("PAUSED");
	escapeWindow->AddButton(new Button("escapeWindowb1", c, root + "Window/windowquit.png", 140, 40));
	escapeWindow->AddButton(new Button("escapeWindowb2", c, root + "Window/windowbtm.png", 140, 40));
	escapeWindow->AddButton(new Button("escapeWindowb3", c, root + "Window/windowret.png", 140, 40));
	
	escapeWindowShowing = true;
}

void IngameState::closeEscapeWindow()
{
	escapeWindow->DeleteWindow();
	HAMURWORLD->DeleteObject("escapeWindow");
	escapeWindowShowing = false;
}

void IngameState::ActivateBrush(const bool &isActive)
{
	if (isActive)
	{
		brushButton->SetSprite("Graphics/brush.png");
	}
	else
	{
		brushButton->SetSprite("Graphics/brush2.png");
	}
	//brushButton->SetVisible(isActive);
	brushButton->SetActive(isActive);
	brushText->SetVisible(isActive);
}

void IngameState::ShowWaveText( const string &waveName )
{
	if(waveText == NULL)
	{
		HamurVec3 c;
		c.x = HamurOpenGL::GetInstance()->GetScreenWidth()/2;
		c.y = 15;

		waveText = new Text("waveText", Wave::GetActiveWave()->GetName() + " Wave Started", "Fonts/LambadaDexter.ttf", 40, c, HamurColorRGB::BLACK);
		waveText->SetVisible(true);
	}

	waveText->SetText(waveName + " Wave Started");
	waveText->SetVisible(true);
}