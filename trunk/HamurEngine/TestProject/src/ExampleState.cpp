#include "ExampleState.h"


// Calling HamurState("Name") is a must!
ExampleState::ExampleState() : HamurState("ExampleState")
{
   
}

ExampleState::~ExampleState()
{
 
}


// ENTER
void ExampleState::Enter() 
{
    HAMURWORLD->AddObject(new HamurObject("Tank", "data/Tank.png"));
    HAMURWORLD->GetHamurObject("Tank")->SetPosition(0, 0);
}


// UPDATE
void ExampleState::Update() 
{
    if(HAMUREVENT->IsKeyDown(Keyboard::Escape)) 
    {
        HAMURENGINE->Stop();
    }
    else if(HAMUREVENT->IsKeyPressed(Keyboard::Escape))
    {
        HAMURCONSOLE << "Space'e bastin!!" << HamurConsole::Endl();
        HAMURCONSOLE << "Time:" << HAMURTIMER->GetTimeInSeconds() << HamurConsole::Endl();
    }

    HAMURWORLD->GetHamurObject("Tank")->RotateDegree(mAngle);
    HAMURCONSOLE << HAMURTIMER->DeltaTime() << "\n";
}


// DRAW
void ExampleState::Draw() 
{
 
}


// EXIT
void ExampleState::Exit() 
{
    HAMURWORLD->DeleteObject("Tank");
    HAMURWORLD->DeleteObject("Tahta");
}


