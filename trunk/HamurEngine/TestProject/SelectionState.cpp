#include "SelectionState.h"
#include "IngameState.h"
#include "audio/hamurFX.h"

using namespace hamur;

SelectionState::SelectionState() : HamurState("SelectionState"), mSelectedSnackCount(0)
{
	
}

SelectionState::~SelectionState()
{

}

void SelectionState::createMenu()
{
	/** NOTE! It is important to add each button with the same name its wave has in the XML file!!! */
	HamurVec3 c;
	string root = "Graphics/Food/";

	if (Level::mActiveLevel == "")
	{
		c.x = 100; c.y = 230; c.z = +10.0;
		breakfastPanel = new Panel("breakfastPanel", c, root + "Breakfast1.png", 64, 64);
		c.x = 375;
		lunchPanel = new Panel("lunchPanel", c, root + "Lunch1.png", 64, 64);
		c.x = 650;
		dinnerPanel = new Panel("dinnerPanel", c, root + "Dinner1.png", 64, 64);
	}
	else if (Level::mActiveLevel == "mondayLevel")
	{
		c.x = 100; c.y = 230; c.z = +10.0;
		breakfastPanel = new Panel("breakfastPanel", c, root + "Breakfast2.png", 64, 64);
		c.x = 375;
		lunchPanel = new Panel("lunchPanel", c, root + "Lunch2.png", 64, 64);
		c.x = 650;
		dinnerPanel = new Panel("dinnerPanel", c, root + "Dinner2.png", 64, 64);
	}
	else if (Level::mActiveLevel == "thursdayLevel")
	{
		c.x = 100; c.y = 230; c.z = +10.0;
		breakfastPanel = new Panel("breakfastPanel", c, root + "Breakfast3.png", 64, 64);
		c.x = 375;
		lunchPanel = new Panel("lunchPanel", c, root + "Lunch3.png", 64, 64);
		c.x = 650;
		dinnerPanel = new Panel("dinnerPanel", c, root + "Dinner3.png", 64, 64);
	}

	c.x = 50; c.y = 420;

	TextDataReader *tdr = TextDataReader::GetInstance();
	list<string> good = tdr->GetGoodFood();
	list<string> nsg = tdr->GetNSGFood();
	list<string> bad = tdr->GetBadFood();
	

	list<string>::iterator it;
	for (it = good.begin(); it != good.end(); it++)
	{
		snackButtons.push_back(new Button((*it) + "Button", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}
	for (it = nsg.begin(); it != nsg.end(); it++)
	{
		snackButtons.push_back(new Button((*it) + "Button", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}
	for (it = bad.begin(); it != bad.end(); it++)
	{
		snackButtons.push_back(new Button((*it) + "Button", c, root + (*it) + ".png", 64, 64));
		c.x += 70;
	}
}

void SelectionState::Enter()
{
	this->snacksNumber = 4;

	int w = HamurOpenGL::GetInstance()->GetScreenWidth();
	int h = HamurOpenGL::GetInstance()->GetScreenHeight();

	HamurVec3 c;

	// Background
	c.x = w/2; c.y = h/2;
	background = new Panel ("backgroundSelection", c, "Graphics/menubg.png", HamurOpenGL::GetInstance()->GetScreenWidth(), HamurOpenGL::GetInstance()->GetScreenHeight());
	background->ScaleSprite(1.5,1.5);
	// Some texts
	c.x = 375; c.y = 50;
	chooseTextPanel = new Panel("chooseText", c, "Graphics/selwhattoeat.png", 400, 100);
	//chooseText = new Text("chooseText", "Chose what to eat", "Fonts/DejaVuSans.ttf", 40, c, HamurColorRGB::BLACK, BOLD);
	c.x = 100; c.y = 150;
	breakfastTextPanel = new Panel("breakfastText", c, "Graphics/selbreakfast.png", 150,50); 
	//breakfastText = new Text("breakfastText", "Breakfast", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 375;
	lunchTextPanel = new Panel("lunchText", c, "Graphics/sellunch.png", 150,50);
	//lunchText = new Text("lunchText", "Lunch", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 650;
	dinnerTextPanel = new Panel("dinnerText", c, "Graphics/seldinner.png", 150,50);
	//dinnerText = new Text("dinnerText", "Dinner", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	c.x = 375; c.y = 350;
	snacksTextPanel = new Panel("snacksText", c, "Graphics/selsnacks.png", 150,50);
	//snacksText = new Text("snacksText", "Snacks", "Fonts/DejaVuSans.ttf", 30, c, HamurColorRGB::BLACK);
	
	c.x = 700;
	c.y = 550;

	startButton = new Button("startButton", c, "Graphics/selstart.png", 250, 75);	

	//Reset values;
	foodSelection["snack1"] = "";
	foodSelection["snack2"] = "";
	foodSelection["snack3"] = "";
	foodSelection["snack4"] = "";
	foodSelection["snack5"] = "";
	foodSelection["snack6"] = "";
	
	// Create the menu according to the level
	createMenu();
}

void SelectionState::Update(float deltaTime)
{
	if (startButton->isPushed())
	{
		int randomIndex = (int)((rand() % 3) + 1);
		foodSelection["breakfast"] = "Breakfast" + HamurString::ParseInt(randomIndex).GetString();
		foodSelection["lunch"] = "Lunch" + HamurString::ParseInt(randomIndex).GetString();
		foodSelection["dinner"] = "Dinner" + HamurString::ParseInt(randomIndex).GetString();

		if (foodSelection.empty() == false)
		{
			FeedbackInfo *fi = FeedbackInfo::GetInstance();
			fi->SetSelection(foodSelection);
			HAMURSTATEMR->ChangeState("IngameState");
		}
	}

	vector<Button *>::iterator Iter;
	for (Iter = snackButtons.begin(); Iter != snackButtons.end(); Iter++)
	{
		if ((*Iter)->isPushed() && mSelectedSnackCount < 6)
		{
			cout << (*Iter)->GetName() + " pushed!" << endl;
			(*Iter)->SetSprite("Graphics/Food/foodselected.png");
			string foodKey = "snack" + HamurString::ParseInt(++mSelectedSnackCount).GetString();
			string waveName = (*Iter)->GetName();
			foodSelection[foodKey] = waveName.substr(0, waveName.find("Button"));
		}
	}
}

void SelectionState::Draw(float deltaTime)
{

}

void SelectionState::Exit()
{
	HAMURWORLD->ClearAll();
}