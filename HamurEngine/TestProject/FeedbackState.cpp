#include "FeedbackState.h"
#include "StoryState.h"

using namespace hamur;

FeedbackState::FeedbackState() : HamurState("FeedbackState")
{
}

FeedbackState::~FeedbackState()
{
	
}

void FeedbackState::Enter()
{
	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();
	string font = "Fonts/LambadaDexter.ttf"; 

	HamurVec3 c;
	c.x = w/2; c.y = h/2;
	background = new Panel ("backgroundFeedback", c, "Graphics/menubg.png", HamurOpenGL::GetInstance()->GetScreenWidth(), HamurOpenGL::GetInstance()->GetScreenHeight());
	background->ScaleSprite(1.5,1.5);
	c.x = 75; c.y = 75;
	goodText = new Text ("goodfbText", "Good", font, 30, c, HamurColorRGB::BLACK);
	c.y += 75;
	normalText = new Text ("normalfbText", "Not so good", font, 30, c, HamurColorRGB::BLACK);
	c.y += 75;
	badText = new Text ("badfbText", "Bad", font, 30, c, HamurColorRGB::BLACK);
	c.y += 125;
	lifeText = new Text ("lifefbText", "Life", font, 30, c, HamurColorRGB::BLACK);
	c.y += 50;
	shieldsText = new Text ("shieldsfbText", "Shields", font, 30, c, HamurColorRGB::BLACK);
	c.x = 650; c.y = 550;
	okButton = new Button("okfbButton", c, "Graphics/fbnext.png", 350, 75);
	c.y = 150; c.x = 600;
	characterPanel = new Panel("characterfbPanel", c, "Graphics/testChar.png", 10, 10); 
}

void FeedbackState::Update(float deltaTime)
{
	if(okButton->isPushed())
	{
		if(!mIsGameFinished)	
			HAMURSTATEMR->ChangeState("SelectionState");
		else
		{
			HAMURSTATEMR->ChangeState("StoryState");
		}
	}
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

	HamurVec3 c;
	HamurString str;
	string font = "Fonts/LambadaDexter.ttf";

	c.x = 300; c.y = 350;

	// The bars indicating levels of shields and life
	///////////////
	lifePanel = new Panel("lifefbPanel", c, "", 300, 10, HamurColor::RED);
	c.x = 600;
	str << h/10;
	str << "%";
	lifeValueText = new Text("lifeValueText", str.GetString(), font, 30, c, HamurColorRGB::BLACK); 
	c.x = 300; c.y += 50;
	shieldsPanel = new Panel("shieldsfbPanel", c, "", 300, 10, HamurColor::BLUE);
	c.x = 600;
	str.Clear();
	str << s/10;
	str << "%";
	shieldsValueText = new Text("shieldValueText", str.GetString(), font, 30, c, HamurColorRGB::BLACK);
	// We apply the values
	lifePanel->SetWidth(h*0.3);
	shieldsPanel->SetWidth(s*0.3);

	//////////////////
	// The panels ////
	/////////////////////////////
	TextDataReader *tdr = new TextDataReader("test.xml");
	list<string> good = tdr->GetGoodFood();
	list<string> nsg = tdr->GetNSGFood();
	list<string> bad = tdr->GetBadFood();
	
	list<string> good2;
	list<string> nsg2;
	list<string> bad2;

	bool found = false;
	string aux = "";
	str.Clear();

	for (int i = 1; i <= 6; i++)
	{
		str.Clear();
		str << i;
		found = false;
		aux = sel["snack" + str.GetString()];

		if(aux != "")
		{
			// We search in Good, NSG and Bad
			list<string>::iterator it;
			for (it = good.begin(); it != good.end() && !found; it++)
			{
				if ((*it) == aux)
				{
					cout << "g: " << aux << endl;
					good2.push_back(aux);
					found = true;
				}
			}
			for (it = nsg.begin(); it != nsg.end() && !found; it++)
			{
				if ((*it) == aux)
				{
					cout << "nsg: " << aux << endl;
					nsg2.push_back(aux);
					found = true;
				}
			}
			for (it = bad.begin(); it != bad.end() && !found; it++)
			{
				if ((*it) == aux)
				{
					cout << "b: " << aux << endl;
					bad2.push_back(aux);
					found = true;
				}
			}
		}
	}

	// Now we place the panels
	list<string>::iterator it;
	string root = "Graphics/Food/";
	c.x = 175; c.y = 75;
	for (it = good2.begin(); it != good2.end(); it++)
	{
		goodPanels.push_back(new Panel((*it) + "Panel", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}
	c.x = 175; c.y = 150;
	for (it = nsg2.begin(); it != nsg2.end(); it++)
	{
		normalPanels.push_back(new Panel((*it) + "Panel", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}
	c.x = 175; c.y = 225;
	for (it = bad2.begin(); it != bad2.end(); it++)
	{
		badPanels.push_back(new Panel((*it) + "Panel", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}
}

string FeedbackState::chooseFeedback()
{
	return "";
}