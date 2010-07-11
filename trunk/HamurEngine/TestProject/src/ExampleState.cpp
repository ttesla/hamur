#include "ExampleState.h"


// Calling HamurState("Name") is a must!
ExampleState::ExampleState() : HamurState("ExampleState")
{

}

ExampleState::~ExampleState()
{

}


// ENTER
void ExampleState::enter() 
{

}


// UPDATE
void ExampleState::update() 
{
    if(HAMUREVENT->IsKeyPressed(SDLK_ESCAPE)) 
        HAMURENGINE->stop();

    static bool keyPressed = false;

    if(HAMUREVENT->IsKeyPressed(SDLK_UP) && !keyPressed)
    {
        keyPressed = true;
    }

    if(! HAMUREVENT->IsKeyPressed(SDLK_UP))
        keyPressed = false;
}


// DRAW
void ExampleState::draw() 
{
 
}


// EXIT
void ExampleState::exit() 
{

}


