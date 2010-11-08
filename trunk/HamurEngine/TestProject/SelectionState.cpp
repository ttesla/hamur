#include "SelectionState.h"

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
	chooseText = new Text("chooseText", "Chose what to eat", "Fonts/DejaVuSans.ttf", 40, c, HamurColorRGB::BLACK);
	c.x = 100; c.y = 150;
	breakfastText = new Text("breakfastText", "Breakfast", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 375;
	lunchText = new Text("lunchText", "Lunch", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 650;
	dinnerText = new Text("dinnerText", "Dinner", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 375; c.y = 350;
	snacksText = new Text("snacksText", "Snacks", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);

	// Some buttons
	c.x = 100; c.y = 230;
	breakfastButton = new Button("breakfastButton", c, "Graphics/testbutton.png", 40, 40);
	c.x = 375;
	lunchButton = new Button("lunchButton", c, "Graphics/testbutton.png", 40, 40);
	c.x = 650;
	dinnerButton = new Button("dinnerButton", c, "Graphics/testbutton.png", 40, 40);

	HamurString str;
	string aux = "snackButton";
	for (int i = 0; i < snacksNumber; i++)
	{
		str << i;
		snackButtons.push_back(new Button(aux + str.GetString(), c, "Graphics/testbutton.png", 30,30));
	}

	c.x = 750;
	c.y = 550;

	startButton = new Button("startButton", c, "Graphics/playbutton.png", 90, 90);	
	
}

void SelectionState::Update(float deltaTime)
{
	if (startButton->isPushed())
	{
		HAMURSTATEMR->ChangeState("IngameState");
	}
}

void SelectionState::Draw(float deltaTime)
{

}

void SelectionState::Exit()
{
	HAMURWORLD->DeleteObject("backgroundSelection");
	HAMURWORLD->DeleteObject("chooseText");
	HAMURWORLD->DeleteObject("breakfastText");
	HAMURWORLD->DeleteObject("lunchText");
	HAMURWORLD->DeleteObject("dinnerText");
	HAMURWORLD->DeleteObject("snacksText");
	HAMURWORLD->DeleteObject("breakfastButton");
	HAMURWORLD->DeleteObject("lunchButton");
	HAMURWORLD->DeleteObject("dinnerButton");
	HAMURWORLD->DeleteObject("startButton");

	HamurString str;
	string aux = "snackButton";
	for (int i = 0; i < snacksNumber; i++)
	{
		str << i;
		HAMURWORLD->DeleteObject(aux + str.GetString());
	}
}