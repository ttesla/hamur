#include "TestState.h"


// Calling HamurState("Name") is a must!
TestState::TestState() : HamurState("TestState")
{
   
}

TestState::~TestState()
{
 
}


// ENTER
void TestState::Enter() 
{
    HAMURWORLD->AddObject(new HamurObject("B1", "data/normal.png", HamurColorRGB::COLORKEY));
    HAMURWORLD->AddObject(new HamurObject("B2", "data/fatty.png"));
	HAMURWORLD->AddObject(new HamurObject("B3", "data/slim.png"));
	HAMURWORLD->AddObject(new HamurObject("B4", "data/strayer.png"));
	HAMURWORLD->AddObject(new HamurObject("B5", "data/shooter.png"));

    HAMURWORLD->GetHamurObject("B1")->SetPosition(200, 100);
    HAMURWORLD->GetHamurObject("B1")->ScaleSpriteUniform(2);
	HAMURWORLD->GetHamurObject("B2")->SetPosition(230, 100);
    HAMURWORLD->GetHamurObject("B2")->SetTransparency(0.3f);
	HAMURWORLD->GetHamurObject("B3")->SetPosition(280, 100);
	HAMURWORLD->GetHamurObject("B4")->SetPosition(300, 100);
	HAMURWORLD->GetHamurObject("B5")->SetPosition(320, 100);
    mAngle = 0;
}


// UPDATE
void TestState::Update(float deltaTime) 
{
	
    if(HAMUREVENT->IsKeyDown(Keys::Escape)) 
    {
        HAMURENGINE->Stop();
    }
    
    mAngle += 10*deltaTime;
    HAMURWORLD->GetHamurObject("B1")->RotateDegree(mAngle);
	HAMURWORLD->GetHamurObject("B2")->RotateDegree(mAngle);
	HAMURWORLD->GetHamurObject("B3")->RotateDegree(mAngle);
	HAMURWORLD->GetHamurObject("B4")->RotateDegree(mAngle);
	HAMURWORLD->GetHamurObject("B5")->RotateDegree(mAngle);
    HAMURWORLD->GetHamurObject("B5")->ScaleSpriteUniform(mAngle/10);
     HAMURWORLD->GetHamurObject("B5")->SetTransparency(mAngle/100);
    
    HAMURCONSOLE << HAMURTIMER->DeltaTime() << "\n";
	
	//DrawPlotter();
}


// DRAW
void TestState::Draw(float deltaTime) 
{
 
}


// EXIT
void TestState::Exit() 
{
    HAMURWORLD->DeleteObject("Tank");
}

void TestState::DrawPlotter()
{
	//HamurPlotter::DrawSolidRectangle(100, 100, 50, 50, HamurColor::RED);

	//HamurPlotter::DrawSolidRectangle(400, 400, 10, 80, HamurColor::GREEN);

	HamurVec3 vecx1(1, 1 ,1);
	HamurVec3 vecx2(2,3,5);

	int x = HamurMath::Random(-6, 12);
	x = HamurMath::Random(-25, 12);
	x = HamurMath::Random(-39, 12);
	x = HamurMath::Random(11, 17);
	x = HamurMath::Random(25, 12);

	HamurColor::SetDefaultColor(HamurColor::GREEN);
	HamurVec3 vecs[4] = {HamurVec3(100,100,0), HamurVec3(100,500,0), HamurVec3(500, 500, 0), HamurVec3(500,100,0) };
	HamurPlotter::DrawRectangle(400, 400, 300, 100);
	HamurPlotter::DrawPoint(100, 100, HamurColor::BLUE);
	HamurPlotter::DrawPoint(100, 500, HamurColor::BLUE);
	HamurPlotter::DrawPoint(500, 100, HamurColor::BLUE);
	//HamurVec3(450, 450,50), HamurVec3(600,250,50), HamurVec3(450, 10,50)};

	//HamurPlotter::DrawPolygon(vecs, 6, HamurColor::CYAN,180);

	HamurVec3 vec2(60, 60, 0);

	
	//HamurPlotter::DrawPoint(60, 60, HamurColor::BLUE);

	//HamurPlotter::DrawCircle(365, 237, 136, HamurColor::MAGENTA);

	//HamurPlotter::DrawSolidCircle(365, 237, 50, HamurColor::YELLOW);


	for ( int i =0; i< 40; i++)
	{
		//HamurPlotter::DrawCircle(400, 300, (i+1)* 8.0f, HamurColor::RED);
	}


	HamurVec2 down1(140, 70);
	HamurVec2 down2(140,350);

	HamurVec3 up1(140, 70, 0);
	HamurVec3 up2(140, 350, 0);

	HamurColor newcolor1(255, 50, 0);
	HamurColor newcolor2 (255, 0, 255);

	HamurVec2 try1(1,1);
	HamurVec3 try2(3,3,0);

	//HamurPlotter::DrawLine(140, 70, 0, 140, 350, 0, HamurColor::WHITE, 90);
// 	HamurPlotter::DrawLine(down1, down2, HamurColor::WHITE, 90);
// 	HamurPlotter::DrawLine(up1, up2, HamurColor::YELLOW, 45);
// 	HamurPlotter::DrawLine(down1, down2, newcolor1);
// 	HamurPlotter::DrawLine(up1, up2, newcolor2);

	for (int i = 0, k=0; i < 50; i++)
	{
		HamurPlotter::DrawPoint(try1, HamurColor::YELLOW);
		HamurPlotter::DrawPoint(try2, HamurColor::BLUE);
	}
};


