#include "HowToPlayState.h"

using namespace hamur;

int lines = 18;

HowToPlayState::HowToPlayState() : HamurState("HowToPlayState")
{
	
}

HowToPlayState::~HowToPlayState()
{
	
}

void HowToPlayState::Enter()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();

	HamurVec3 c;
	string font = "Fonts/DejaVuSans.ttf";

	// Background
	c.x = w/2; c.y = h/2;
	HAMURENGINE->SetBackgroundColor(HamurColor::WHITE);
	//background = new Panel ("backgroundHTP", c, "Graphics/testbg2.png", HamurOpenGL::GetInstance()->GetScreenWidth(), HamurOpenGL::GetInstance()->GetScreenHeight());
	c.y = 50;
	// Title
	titleText = new Text("titleHTPText", "How to play", font, 40, c, HamurColorRGB::BLUE, BOLD);
	
	// Main text
	HamurString s;
	tdr = new TextDataReader("test.xml");

	string t = tdr->GetHowToPlay();
	string* textLines = tdr->FormatText(t, lines);
	mainText = new Text* [lines];

	c.y += 30 ;
	for (int i = 0; i < lines && textLines[i] != ""; i++)
	{
		cout << textLines[i] << endl;
		s << i; 
		c.y += 20;
		mainText[i] = new Text ("mainTextHTP" + s.GetString(), textLines[i], font, 15, c, HamurColorRGB::BLACK);
	}

	c.y += 100;
	doneButton = new Button("doneHTPButton", c, "Graphics/testbutton.png", 90, 90);
}

void HowToPlayState::Update(float deltaTime)
{
	if (this->doneButton->isPushed())
	{
		HAMURSTATEMR->ChangeState("MenuState");
	}
}

void HowToPlayState::Draw(float deltaTime)
{

}

void HowToPlayState::Exit()
{
	HAMURWORLD->ClearAll();


/*
	//Delete objects
	HAMURWORLD->DeleteObject("doneHTPButton");
	HAMURWORLD->DeleteObject("titleHTPText");
	HamurString s;
	for (int i = 0; i < lines; i++)
	{
		s << i;
		HAMURWORLD->DeleteObject("mainTextHTP" + s.GetString());
	}*/

}