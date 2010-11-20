#include "SelectionState.h"
#include "IngameState.h"

using namespace hamur;

SelectionState::SelectionState() : HamurState("SelectionState")
{
	
}

SelectionState::~SelectionState()
{

}

void SelectionState::Enter()
{
	this->snacksNumber = 4;

	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();

	HamurVec3 c;

	// Background
	c.x = w/2; c.y = h/2;
	background = new Panel ("backgroundSelection", c, "Graphics/testbg2.png", HamurOpenGL::GetInstance()->GetScreenWidth(), HamurOpenGL::GetInstance()->GetScreenHeight());

	// Some texts
	c.x = 375; c.y = 50;
	chooseText = new Text("chooseText", "Chose what to eat", "Fonts/DejaVuSans.ttf", 40, c, HamurColorRGB::BLACK, BOLD);
	c.x = 100; c.y = 150;
	breakfastText = new Text("breakfastText", "Breakfast", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 375;
	lunchText = new Text("lunchText", "Lunch", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 650;
	dinnerText = new Text("dinnerText", "Dinner", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 375; c.y = 350;
	snacksText = new Text("snacksText", "Snacks", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);

	// Some buttons
	/*******************************/
	/** NOTE! It is important to add each button with the same name its wave has in the XML file!!! */

	c.x = 100; c.y = 230; c.z = +10.0;
	breakfastPanel = new Panel("breakfastPanel", c, "Graphics/Food/flingor.png", 64, 64);
	c.x = 375;
	lunchPanel = new Panel("lunchPanel", c, "Graphics/Food/vit_smorgas.png", 64, 64);
	c.x = 650;
	dinnerPanel = new Panel("dinnerPanel", c, "Graphics/Food/nyponsoppa.png", 64, 64);
	c.x = 100; c.y = 420;
	snackButtons.push_back(new Button("aggButton", c, "Graphics/Food/agg.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("appleButton", c, "Graphics/Food/apple.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("chipsButton", c, "Graphics/Food/chips.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("glassButton", c, "Graphics/Food/glass.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("godisButton", c, "Graphics/Food/godis.png", 64, 64));
	c.x += 70;
	snackButtons.push_back(new Button("kakorButton", c, "Graphics/Food/kakor.png", 64, 64));
	c.x += 70;
	snackButtons.push_back(new Button("laskButton", c, "Graphics/Food/lask.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("mork_smorgasButton", c, "Graphics/Food/mork_smorgas.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("smoothieButton", c, "Graphics/Food/yoghurt.png", 64, 64));
	
	/*
	HamurString str;
	string aux = "snackButton";
	for (int i = 0; i < snacksNumber; i++)
	{
		str << i;
		snackButtons.push_back(new Button(aux + str.GetString(), c, "Graphics/testbutton.png", 30,30));
	}
	*/

	c.x = 750;
	c.y = 550;

	startButton = new Button("startButton", c, "Graphics/playbutton.png", 90, 90);	
	
}

void SelectionState::Update(float deltaTime)
{
	if (startButton->isPushed())
	{
		int randomIndex = (int)((rand() % 3) + 1);
		foodSelection["breakfast"] = "Breakfast" + HamurString::ParseInt(randomIndex).GetString();
		foodSelection["lunch"] = "Lunch" + HamurString::ParseInt(randomIndex).GetString();
		foodSelection["dinner"] = "Dinner" + HamurString::ParseInt(randomIndex).GetString();

		if (foodSelection.empty() == false)
		{
			HAMURSTATEMR->ChangeState("IngameState");
			static_cast<IngameState*>(HAMURSTATEMR->GetCurrentState())->SetFoodSelection(foodSelection);
		}
	}

	vector<Button *>::iterator Iter;
	for (Iter = snackButtons.begin(); Iter != snackButtons.end(); Iter++)
	{
		if ((*Iter)->isPushed())
		{
			cout << (*Iter)->GetName() + " pushed!" << endl;
		}
	}
}

void SelectionState::Draw(float deltaTime)
{

}

void SelectionState::Exit()
{
	//HAMURWORLD->DeleteObject("backgroundSelection");
	//HAMURWORLD->DeleteObject("chooseText");
	//HAMURWORLD->DeleteObject("breakfastText"); 
	//HAMURWORLD->DeleteObject("lunchText");
	//HAMURWORLD->DeleteObject("dinnerText");
	//HAMURWORLD->DeleteObject("snacksText");

	//HAMURWORLD->DeleteObject("FlingorButton");
	//HAMURWORLD->DeleteObject("Vit_smorgasButton");
	//HAMURWORLD->DeleteObject("NyponsoppaButton");

	//HAMURWORLD->DeleteObject("startButton");

	//HamurString str;
	//string aux = "snackButton";
	//for (int i = 0; i < snacksNumber; i++)
	//{
	//	str << i;
	//	HAMURWORLD->DeleteObject(aux + str.GetString());
	//}

	HAMURWORLD->ClearAll();
}