#include "GameOverState.h"

using namespace hamur;

GameOverState::GameOverState() : HamurState("GameOverState")
{
	
}

GameOverState::~GameOverState()
{
	
}

void GameOverState::Enter()
{
	string font = "Fonts/DejaVuSans.ttf";
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();

	HamurVec3 c;

	// Background
	c.x = w/2; c.y = h/2 - 100;
	//HAMURENGINE->SetBackgroundColor(HamurColor::WHITE);
	//background = new Panel ("backgroundSelection", c, "Graphics/testbg2.png", HamurOpenGL::GetInstance()->GetScreenWidth(), HamurOpenGL::GetInstance()->GetScreenHeight());
	//gameOverText = new Text("gameOverText", "GAME OVER", font, 40, c, HamurColorRGB::BLACK, BOLD);
	gameOverPanel = new Panel("gameOverTitle", c, "Graphics/gameover.png", 500, 250);
	c.y += 150;
	okButton = new Button("gameOverButton", c, "Graphics/backToMenu.png", 90, 90);
}

void GameOverState::Update(float deltaTime)
{
	if (okButton->isPushed())
	{
		HAMURSTATEMR->ChangeState("MenuState");
	}
}

void GameOverState::Draw(float deltaTime)
{

}

void GameOverState::Exit()
{
	HAMURWORLD->ClearAll();

	//HAMURWORLD->DeleteObject("gameOverText");
	//HAMURWORLD->DeleteObject("gameOverButton");
}