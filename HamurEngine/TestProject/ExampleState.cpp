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
        HAMURSTATEMR->ChangeState("MainState");
    }

    static bool keyPressed = false;

   // HAMURCONSOLE << "Yes Sir?" << HAMURWORLD->GetObject("Tahta") << "\n";
}


// DRAW
void ExampleState::Draw() 
{
 
}


// EXIT
void ExampleState::Exit() 
{
    HAMURWORLD->DeleteObject("Tahta");
}


