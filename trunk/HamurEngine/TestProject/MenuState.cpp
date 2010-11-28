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
	//HAMURENGINE->SetBackgroundColor(HamurColor::WHITE);
	background = new Panel ("backgroundSelection", c, "Graphics/menubg.png", HamurOpenGL::GetInstance()->GetScreenWidth(), HamurOpenGL::GetInstance()->GetScreenHeight());
	background->ScaleSprite(1.5,1.5);
	c.y = 150;
	// Title
	title = new Panel("titleMenuPanel", c, "Graphics/menutitle.png", 700, 105);
	// Some buttons
	c.y = 300;
	playButton = new Button("playMenuButton", c, "Graphics/menuplay.png", 200, 50);
	c.y += 70;
	howToPlayButton = new Button("howToPlayMenuButton", c, "Graphics/menuhowtoplay.png", 200, 50);
	c.y += 70;
	exitButton = new Button("exitMenuButton", c, "Graphics/menuexit.png", 200, 50);
}

void MenuState::Update(float deltaTime)
{
	if (playButton->isPushed())
	{
		HAMURSTATEMR->ChangeState("StoryState");
	}
	else if (howToPlayButton->isPushed())
	{
		HAMURSTATEMR->ChangeState("HowToPlayState");
	}
	else if (exitButton->isPushed())
	{
		HAMURENGINE->Stop();	
	}
}

void MenuState::Draw(float deltaTime)
{

}

void MenuState::Exit()
{
	HAMURWORLD->ClearAll();
}