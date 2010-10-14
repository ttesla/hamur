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
    HAMURWORLD->AddObject(new HamurObject("Tank", "data/Tank.png", HamurColorRGB::COLORKEY));
    HAMURWORLD->GetHamurObject("Tank")->SetPosition(100, 100);
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
    HAMURWORLD->GetHamurObject("Tank")->RotateDegree(mAngle);
    
    HAMURCONSOLE << HAMURTIMER->DeltaTime() << "\n";
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


