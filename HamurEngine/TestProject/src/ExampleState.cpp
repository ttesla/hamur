#include "ExampleState.h"


// Calling HamurState("Name") is a must!
ExampleState::ExampleState() : HamurState("ExampleState")
{
    HAMURWORLD->AddObject(new HamurObject("Tahta"));
}

ExampleState::~ExampleState()
{

}


// ENTER
void ExampleState::Enter() 
{

}


// UPDATE
void ExampleState::Update() 
{
    if(HAMUREVENT->IsKeyPressed(SDLK_ESCAPE)) 
        HAMURENGINE->Stop();

    static bool keyPressed = false;

    HAMURCONSOLE << "Yes Sir?" << HAMURWORLD->GetObject("Tahta") << "\n";
}


// DRAW
void ExampleState::Draw() 
{
 
}


// EXIT
void ExampleState::Exit() 
{

}


