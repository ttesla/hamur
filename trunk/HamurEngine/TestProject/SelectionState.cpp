#include "SelectionState.h"
#include "IngameState.h"

using namespace hamur;

SelectionState::SelectionState() : HamurState("SelectionState"), mSelectedSnackCount(0)
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
	breakfastPanel = new Panel("breakfastPanel", c, "Graphics/Food/Flingor.png", 64, 64);
	c.x = 375;
	lunchPanel = new Panel("lunchPanel", c, "Graphics/Food/Vit_smorgas.png", 64, 64);
	c.x = 650;
	dinnerPanel = new Panel("dinnerPanel", c, "Graphics/Food/Nyponsoppa.png", 64, 64);
	c.x = 100; c.y = 420;
	snackButtons.push_back(new Button("EggButton", c, "Graphics/Food/Agg.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("AppleButton", c, "Graphics/Food/Apple.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("ChipsButton", c, "Graphics/Food/Chips.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("GlassButton", c, "Graphics/Food/Glass.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("GodisButton", c, "Graphics/Food/Godis.png", 64, 64));
	c.x += 70;
	snackButtons.push_back(new Button("KakorButton", c, "Graphics/Food/Kakor.png", 64, 64));
	c.x += 70;
	snackButtons.push_back(new Button("LaskButton", c, "Graphics/Food/Lask.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("Mork_smorgasButton", c, "Graphics/Food/Mork_smorgas.png", 64, 64));
	c.x += 70; 
	snackButtons.push_back(new Button("SmoothieButton", c, "Graphics/Food/Yoghurt.png", 64, 64));
	
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

	//Reset values;
	foodSelection["snack1"] = "";
	foodSelection["snack2"] = "";
	foodSelection["snack3"] = "";
	foodSelection["snack4"] = "";
	foodSelection["snack5"] = "";
	foodSelection["snack6"] = "";

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
		if ((*Iter)->isPushed() && mSelectedSnackCount < 6)
		{
			cout << (*Iter)->GetName() + " pushed!" << endl;
			(*Iter)->SetSprite("Graphics/Food/foodselected.png");
			string foodKey = "snack" + HamurString::ParseInt(++mSelectedSnackCount).GetString();
			string waveName = (*Iter)->GetName();
			foodSelection[foodKey] = waveName.substr(0, waveName.find("Button"));
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