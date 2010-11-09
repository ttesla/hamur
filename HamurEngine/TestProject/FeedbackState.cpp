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
	c.y += 50;
	normalText = new Text ("normalfbText", "Not so good", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
	c.y += 50;
	badText = new Text ("badfbText", "Bad", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
	c.y += 100;
	shieldsText = new Text ("shieldsfbText", "Shields", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
	c.y += 50;
	lifeText = new Text ("lifefbText", "Life", "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
	
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

	c.y += 150;
	// Perhaps a new constructor that takes an external file and formats the long text to fit the screen
	// will be needed...
	//fbText = new Text ("fbText", "lalalalalaalalallaallalalla\nlalalalalallalaa\nlalalala", "Fonts/DejaVuSans.ttf", 10, c, HamurColorRGB::BLACK);

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
	HAMURWORLD->DeleteObject("titleMenuPanel");
	HAMURWORLD->DeleteObject("playMenuButton");
	HAMURWORLD->DeleteObject("howToPlayMenuButton");
	HAMURWORLD->DeleteObject("exitMenuButton");
}