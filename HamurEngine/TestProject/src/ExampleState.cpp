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

}


// UPDATE
void ExampleState::Update() 
{
    if(HAMUREVENT->IsKeyPressed(SDLK_ESCAPE)) 
        HAMURENGINE->Stop();

    static bool keyPressed = false;

    if(HAMUREVENT->IsKeyPressed(SDLK_UP) && !keyPressed)
    {
        keyPressed = true;
    }

    if(! HAMUREVENT->IsKeyPressed(SDLK_UP))
        keyPressed = false;
}


// DRAW
void ExampleState::Draw() 
{
 
}


// EXIT
void ExampleState::Exit() 
{

}


