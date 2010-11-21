#include "FeedbackState.h"

using namespace hamur;

FeedbackState::FeedbackState() : HamurState("FeedbackState")
{
	// Get the values from the game
	goodNumber = badNumber = normalNumber = 3;
}

FeedbackState::~FeedbackState()
{
	
}

void FeedbackState::Enter()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();

	HamurVec3 c;
	c.x = 75; c.y = 75;
	goodText = new Text ("goodfbText", "Good", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
	c.y += 75;
	normalText = new Text ("normalfbText", "Not so good", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
	c.y += 75;
	badText = new Text ("badfbText", "Bad", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
	c.y += 125;
	lifeText = new Text ("lifefbText", "Life", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
	c.y += 50;
	shieldsText = new Text ("shieldsfbText", "Shields", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);

	c.y += 150;

	okButton = new Button("okfbButton", c, "Graphics/testButton.png", 200, 200);
	c.y = 200; c.x = 600;
	characterPanel = new Panel("characterfbPanel", c, "Graphics/testChar.png", 10, 10); 
}

void FeedbackState::Update(float deltaTime)
{

}

void FeedbackState::Draw(float deltaTime)
{

}

void FeedbackState::Exit()
{
	HAMURWORLD->ClearAll();

	/*
	HAMURWORLD->DeleteObject("titleMenuPanel");
	HAMURWORLD->DeleteObject("playMenuButton");
	HAMURWORLD->DeleteObject("howToPlayMenuButton");
	HAMURWORLD->DeleteObject("exitMenuButton");*/

}

void FeedbackState::SetFeedback(map<string, string> sel, float h, float s, int tBU)
{
	foodSelection = sel;
	health = h;
	shield = s;
	toothBrushUses = tBU;

	for (int i = 0; i < goodNumber; i++)
	{
		//goodPanels.push_back(new Panel(""));
	}
	for (int i = 0; i < normalNumber; i++)
	{
		//normalPanels.push_back(new Panel(""));
	}
	for (int i = 0; i < badNumber; i++)
	{
		//badPanels.push_back(new Panel(""));
	}

	HamurVec3 c;
	HamurString str;
	string font = "Fonts/DejaVuSans.ttf";

	c.x = 300; c.y = 350;

	// The bars indicating levels of shields and life
	lifePanel = new Panel("lifefbPanel", c, "", 300, 10, HamurColor::RED);
	c.x = 600;
	str << h;
	str << "%";
	lifeValueText = new Text("lifeValueText", str.GetString(), font, 14, c, HamurColorRGB::BLACK); 
	c.x = 300; c.y += 50;
	shieldsPanel = new Panel("shieldsfbPanel", c, "", 300, 10, HamurColor::BLUE);
	c.x = 600;
	str.Clear();
	str << s;
	str << "%";
	shieldsValueText = new Text("shieldValueText", str.GetString(), font, 14, c, HamurColorRGB::BLACK);
	// We apply the values
	lifePanel->SetWidth(h*3);
	shieldsPanel->SetWidth(s*3);

	// The panels


}

string FeedbackState::chooseFeedback()
{
	return "";
}