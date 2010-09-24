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
    if(HAMUREVENT->IsKeyPressed(SDLK_ESCAPE)) 
    {
        HAMURENGINE->Stop();
    }
    else if(HAMUREVENT->IsKeyPressed(SDLK_SPACE))
    {
        HAMURSTATEMR->ChangeState("MainState");
        return;
        HAMURCONSOLE << "Changing state!";
    }

    HAMURWORLD->GetHamurObject("Tank")->RotateDegree(mAngle);
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


