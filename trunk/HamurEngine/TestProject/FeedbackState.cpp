#include "FeedbackState.h"
#include "StoryState.h"

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
	c.x = 75; c.y = 50;
	goodText = new Text ("goodfbText", "Good", font, 30, c, HamurColorRGB::BLACK);
	c.y += 75;
	normalText = new Text ("normalfbText", "Not so good", font, 30, c, HamurColorRGB::BLACK);
	c.y += 75;
	badText = new Text ("badfbText", "Bad", font, 30, c, HamurColorRGB::BLACK);
	c.y = 300;
	lifeText = new Text ("lifefbText", "Life", font, 30, c, HamurColorRGB::BLACK);
	c.y += 50;
	shieldsText = new Text ("shieldsfbText", "Shields", font, 30, c, HamurColorRGB::BLACK);
	c.x = 650; c.y = 550;
	okButton = new Button("okfbButton", c, "Graphics/fbnext.png", 350, 75);
	c.y = 150; c.x = 600;
	characterPanel = new Panel("characterfbPanel", c, "Graphics/testChar.png", 10, 10); 

	SetFeedback();
}

void FeedbackState::Update(float deltaTime)
{
	if(okButton->isPushed())
	{
		/*if(!mIsGameFinished)	
			HAMURSTATEMR->ChangeState("SelectionState");
		else
		{
			HAMURSTATEMR->ChangeState("StoryState");
		}*/
		HAMURSTATEMR->ChangeState("StoryState");
	}
}

void FeedbackState::Draw(float deltaTime)
{

}

void FeedbackState::Exit()
{
	HAMURWORLD->ClearAll();
	
	delete [] fbText;
	fbText = NULL;

	/*
	HAMURWORLD->DeleteObject("titleMenuPanel");
	HAMURWORLD->DeleteObject("playMenuButton");
	HAMURWORLD->DeleteObject("howToPlayMenuButton");
	HAMURWORLD->DeleteObject("exitMenuButton");*/

}

void FeedbackState::SetFeedback()
{
	map<string, string> sel = FeedbackInfo::GetInstance()->GetFoodSelection();
	float h, s;
	h = s = 0.0;

	if (Level::mActiveLevel == "mondayLevel")
	{
		h = FeedbackInfo::GetInstance()->GetHealth(0);
		s = FeedbackInfo::GetInstance()->GetShield(0);
	}
	else if (Level::mActiveLevel == "thursdayLevel")
	{
		h = FeedbackInfo::GetInstance()->GetHealth(1);
		s = FeedbackInfo::GetInstance()->GetShield(1);
	}
	else if (Level::mActiveLevel == "saturdayLevel")
	{
		h = FeedbackInfo::GetInstance()->GetHealth(2);
		s = FeedbackInfo::GetInstance()->GetShield(2);
	}

	HamurVec3 c;
	HamurString str;
	string font = "Fonts/LambadaDexter.ttf";

	c.x = 300; c.y = 300;

	// The bars indicating levels of shields and life
	///////////////
	lifePanel = new Panel("lifefbPanel", c, "", 300, 10, HamurColor::RED);
	c.x = 600;
	str << h/10;
	str << "%";
	lifeValueText = new Text("lVT" + Level::mActiveLevel, str.GetString(), font, 30, c, HamurColorRGB::BLACK); 
	c.x = 300; c.y += 50;
	shieldsPanel = new Panel("shieldsfbPanel", c, "", 300, 10, HamurColor::BLUE);
	c.x = 600;
	str.Clear();
	str << s/10;
	str << "%";
	shieldsValueText = new Text("sVT" + Level::mActiveLevel, str.GetString(), font, 30, c, HamurColorRGB::BLACK);
	// We apply the values
	lifePanel->SetWidth(h*0.3);
	shieldsPanel->SetWidth(s*0.3);

	//////////////////
	// The panels ////
	/////////////////////////////
	TextDataReader *tdr = TextDataReader::GetInstance();
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

	// Add some more feedback information
	FeedbackInfo::GetInstance()->SetSnacks(good2.size(), nsg2.size(), bad2.size());

	// Now we place the panels
	list<string>::iterator it;
	string root = "Graphics/Food/";
	c.x = 175; c.y = 50; c.z = 1.0;
	for (it = good2.begin(); it != good2.end(); it++)
	{
		goodPanels.push_back(new Panel((*it) + "Panel", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}
	c.x = 175; c.y = 125;
	for (it = nsg2.begin(); it != nsg2.end(); it++)
	{
		normalPanels.push_back(new Panel((*it) + "Panel", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}
	c.x = 175; c.y = 200;
	for (it = bad2.begin(); it != bad2.end(); it++)
	{
		badPanels.push_back(new Panel((*it) + "Panel", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}

	// We choose the proper feedback message
	chooseFeedback();
}

string FeedbackState::chooseFeedback()
{
	TextDataReader *tdr = TextDataReader::GetInstance();
	FeedbackInfo *fbi = FeedbackInfo::GetInstance();
	string message = "";
	lines = 0;
	int totalSnacks = fbi->GetGoodSnacks() + fbi->GetNSGSnacks() + fbi->GetBadSnacks();


	// FOR SELECTION --
	if (totalSnacks < 2)
	{
		message += "Man ska vara noga med att äta så man orkar hela dagen. "; //tdr->GetFeedback("fb1");
		lines++;
	}
	else if (totalSnacks > 3)
	{
		message += "Äter du för många saker tar tänderna också skada, även om det är nyttiga saker. Två eller tre mellanmål om dagen borde räcka. "; //tdr->GetFeedback("fb2");
		lines+=2;
	}
	else if (fbi->GetBadSnacks() == 1 || (fbi->GetNSGSnacks() == 1 || fbi->GetNSGSnacks() == 2))
	{
		message += "Att äta något gott och onyttigt är ingen fara, så länge man bara gör det ibland så att tänderna orkar med och är noga med att sköta borstning. "; //tdr->GetFeedback("fb3");
		lines+=2;
	}
	else if (fbi->GetBadSnacks() > 1 || fbi->GetNSGSnacks() == 3)
	{
		message += "Du visste säkert redan att äta sån där saker inte är bra för tänderna. "; //tdr->GetFeedback("fb4");
		lines++;
	}
	else if (totalSnacks >= 2 && totalSnacks <= 3)
	{
		message += "Du vet hur man gör bra matval. "; //tdr->GetFeedback("fb5");
		lines++;
	}

	// FOR HEALTH AND SHIELD --
	float actS, lastS, actH, lastH;
	actS = lastS = actH = lastH = 0.0; 

	if (Level::mActiveLevel == "mondayLevel")
	{
		actS = fbi->GetShield(0);
		lastS = 1000.0;
		actH = fbi->GetHealth(0);
		lastH = 1000.0;
	}
	else if (Level::mActiveLevel == "thursdayLevel")
	{
		actS = fbi->GetShield(1);
		lastS = fbi->GetShield(0);
		actH = fbi->GetHealth(1);
		lastH = fbi->GetHealth(0);
	}
	else if (Level::mActiveLevel == "saturdayLevel")
	{
		actS = fbi->GetShield(2);
		lastS = fbi->GetShield(1);
		actH = fbi->GetHealth(2);
		lastH = fbi->GetHealth(1);
	}

	if ((actH - lastH) < 0)
	{
		message += "När tänderna själva tar skada är det riktigt farligt eftersom dom inte kan laga sig själva särskilt snabbt. "; //tdr->GetFeedback("fb6");
		lines++;
	}
	else if ((actS - lastS) > 0)
	{
		message += "Idag var du visst skötsam med tänderna. "; //tdr->GetFeedback("fb7");
		lines++;
	}
	else if ((lastS - actS) < 200)
	{
		message += "Ja, tänderna klarade sig visst bra idag. "; //tdr->GetFeedback("fb8");
		lines++;
	}
	else if ((lastS - actS) < 700)
	{
		message += "Det gick visst inte allt för bra. Du måste vara mer nogrann med att skydda tänderna. "; //tdr->GetFeedback("fb9");
		lines++;
	}
	else
	{
		message += "Aj-aj-aj. Bakterierna kom nästan in och skadade tänderna. Du borde nog riktigt vara försiktigt nästa gång. "; tdr->GetFeedback("fb10");	
		lines+=2;
	}

	// TOOTHBRUSH USES --
	if (fbi->GetToothBrushUses() < 2)
	{
		message += "Kom ihåg att borsta tänderna ordentligt nästa gång. ";//tdr->GetFeedback("fb11");
		lines++;
	}
	
	cout << "LEV: " << Level::mActiveLevel << " - FBMessage: " << message << endl;
	cout << "TotalSnacks: " << totalSnacks << " G: " << fbi->GetGoodSnacks() << " NSG: " << fbi->GetNSGSnacks() << " BAD: " << fbi->GetBadSnacks() << endl;
	cout << "TBU: " << fbi->GetToothBrushUses()<< endl;

	HamurString s;
	HamurVec3 c; 
	c.x = 400;
	c.y = 425;
	c.z = 3.0;
	
	string* textLines = tdr->FormatText(message, lines);
	fbText = new Text* [lines];

	for (int i = 0; i < lines; i++)
	{
		s.Clear(); s << i;
		fbText[i] = new Text("fbtext" + s.GetString() + Level::mActiveLevel, textLines[i], "Fonts/DejaVuSans.ttf", 20, c, HamurColorRGB::BLACK);
		c.y += 20;
	}
	

	return message;
}