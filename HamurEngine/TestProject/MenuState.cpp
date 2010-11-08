#include "MenuState.h"

using namespace hamur;

MenuState::MenuState() : HamurState("MenuState")
{
	
}

MenuState::~MenuState()
{
	
}

void MenuState::Enter()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();

	HamurVec3 c;

	// Background
	c.x = w/2; c.y = h/2;
	HAMURENGINE->SetBackgroundColor(HamurColor::WHITE);
	//background = new Panel ("backgroundSelection", c, "Graphics/testbg2.png", HamurOpenGL::GetInstance()->GetScreenWidth(), HamurOpenGL::GetInstance()->GetScreenHeight());
	c.y = 75;
	// Title
	title = new Panel("titleMenuPanel", c, "Graphics/menutitle.png", 700, 105);
	// Some buttons
	c.y = 250;
	playButton = new Button("playMenuButton", c, "Graphics/menuplay.png", 200, 50);
	c.y += 50;
	howToPlayButton = new Button("howToPlayMenuButton", c, "Graphics/menuhowtoplay.png", 200, 50);
	c.y += 50;
	exitButton = new Button("exitMenuButton", c, "Graphics/menuexit.png", 200, 50);
}

void MenuState::Update(float deltaTime)
{
	if (this->playButton->isPushed())
	{
		HAMURSTATEMR->ChangeState("SelectionState");
	}
	if (this->exitButton->isPushed())
	{
		HAMURENGINE->Stop();	
	}
}

void MenuState::Draw(float deltaTime)
{

}

void MenuState::Exit()
{
	HAMURWORLD->DeleteObject("titleMenuPanel");
	HAMURWORLD->DeleteObject("playMenuButton");
	HAMURWORLD->DeleteObject("howToPlayMenuButton");
	HAMURWORLD->DeleteObject("exitMenuButton");
}