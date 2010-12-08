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
	slide = 1;

	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();

	HamurVec3 c;
	string font = "Fonts/DejaVuSans.ttf";

	// Background
	c.x = w/2; c.y = h/2;
	
	background = new Panel ("backgroundHTP", c, "Graphics/HowToPlay/htpslide1.png", HamurOpenGL::GetInstance()->GetScreenWidth(), HamurOpenGL::GetInstance()->GetScreenHeight());
	//background->ScaleSprite(1.5,1.5);
	
	c.x = 700; c.y = 575;
	nextButton = new Button("doneHTPButton", c, "Graphics/nextbutton.png", 300, 50);
}

void HowToPlayState::Update(float deltaTime)
{
	if (this->nextButton->isPushed())
	{
		GoToNext();
	}
}

void HowToPlayState::Draw(float deltaTime)
{

}

void HowToPlayState::Exit()
{
	HAMURWORLD->ClearAll();
}

void HowToPlayState::GoToNext()
{
	switch (slide)
	{
		case 1:
			slide = 2;
			SetBackground("Graphics/HowToPlay/htpslide2.png");
			break;
		case 2:
			slide = 3;
			SetBackground("Graphics/HowToPlay/htpslide3.png");
			break;
		case 3:
			slide = 4;
			SetBackground("Graphics/HowToPlay/htpslide4.png");
			break;
		case 4:
			HAMURSTATEMR->ChangeState("MenuState");
			break;
		default:
			break;
	}
}

void HowToPlayState::SetBackground(string path)
{
	background->SetSprite(path);
}