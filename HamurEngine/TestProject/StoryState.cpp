#include "StoryState.h"

using namespace hamur;

StoryState::StoryState() : HamurState("StoryState")
{
}

StoryState::~StoryState()
{
	
}

void StoryState::Enter()
{
	string root = "Graphics/Story/";
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();

	HamurVec3 c;
	c.x = w/2; c.y = h/2;

	if (Level::mActiveLevel == "")
	{
		background = new Panel("storystatebg", c, root + "Story0.png", 800, 600);
	}
	else if (Level::mActiveLevel == "mondayLevel")
	{
		background = new Panel("storystatebg", c, root + "Story1.png", 800, 600);
	}
	else if (Level::mActiveLevel == "thursdayLevel")
	{
		background = new Panel("storystatebg", c, root + "Story2.png", 800, 600);
	}
	else if (Level::mActiveLevel == "saturdayLevel")
	{
		background = new Panel("storystatebg", c, root + "Story3.png", 800, 600);
	}
	c.x = 700; c.y = 575;
	nextButton = new Button("nextButton", c, "Graphics/nextbutton.png", 250, 75);
}

void StoryState::Update(float deltaTime)
{
	if(nextButton->isPushed())
	{
		if (Level::mActiveLevel == "saturdayLevel")
		{
			HAMURSTATEMR->ChangeState("MenuState");
		}
		else
		{
			HAMURSTATEMR->ChangeState("SelectionState");
		}
	}
}

void StoryState::Draw(float deltaTime)
{

}

void StoryState::Exit()
{
	HAMURWORLD->ClearAll();
}
