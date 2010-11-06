#include "IngameState.h"

using namespace hamur;

IngameState::IngameState() : HamurState("IngameState")
{
	playing = false;
}

IngameState::~IngameState()
{
}

void IngameState::UnloadSelection()
{
	HAMURWORLD->DeleteObject("Text1");
	HAMURWORLD->DeleteObject("Text2");
	HAMURWORLD->DeleteObject("Text3");
	HAMURWORLD->DeleteObject("Text4");
	HAMURWORLD->DeleteObject("Text5");
	HAMURWORLD->DeleteObject("Button1");
	HAMURWORLD->DeleteObject("Button2");
	HAMURWORLD->DeleteObject("Button3");
	HAMURWORLD->DeleteObject("Button4");
}

void IngameState::LoadSelection()
{
	/*************
	*	GUI		*
	*************/
	HamurVec3 c;
	c.x = 375;
	c.y = 50;
	c.z = 0;
	// Some texts
	Text *text1 = new Text("Text1", "Chose what to eat", "Fonts/DejaVuSans.ttf", 40, c, HamurColorRGB::BLACK);
	c.x = 100;
	c.y = 150;
	Text *text2 = new Text("Text2", "Breakfast", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 375;
	Text *text3 = new Text("Text3", "Lunch", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 650;
	Text *text4 = new Text("Text4", "Dinner", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 375;
	c.y = 350;
	Text *text5 = new Text("Text5", "Snacks", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	// Some buttons
	c.x = 100;
	c.y = 230;
	Button *button1 = new Button("Button1", c, "Graphics/testbutton.png", 40, 40);
	c.x = 375;
	Button *button2 = new Button("Button2", c, "Graphics/testbutton.png", 40, 40);
	c.x = 650;
	Button *button3 = new Button("Button3", c, "Graphics/testbutton.png", 40, 40);

	c.x = 750;
	c.y = 550;

	startButton = new Button("Button4", c, "Graphics/playbutton.png", 90, 90);
}

void IngameState::LoadGame()
{
	playing = true;

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
	
	WaveDataReader dataReader("test.xml");

	Level *l = new Level("level");
	l->AddWave((Wave *)HAMURWORLD->GetHamurObject("Breakfast1"));
	l->Start();
	
}

void IngameState::Enter()
{
	LoadSelection();
}

void IngameState::Update(float deltaTime)
{
	if (!playing)
	{	
		if (startButton->isPushed())
		{
			UnloadSelection();
			LoadGame();
			playing = true;
		}
	}
	else
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
}

void IngameState::Draw(float deltaTime)
{

}

void IngameState::Exit()
{

}