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
    HAMURWORLD->AddObject(new HamurObject("Tank", "data/Tank.png", HamurColorRGB::COLORKEY));
    HAMURWORLD->GetHamurObject("Tank")->SetPosition(100, 100);
    mAngle = 0;

}


// UPDATE
void ExampleState::Update(float deltaTime) 
{
    if(HAMUREVENT->IsKeyDown(Keys::Escape)) 
    {
        HAMURENGINE->Stop();
    }
    
    mAngle += 100*deltaTime;
    HAMURWORLD->GetHamurObject("Tank")->RotateDegree(mAngle);
    
    HAMURCONSOLE << HAMURTIMER->DeltaTime() << "\n";
}


// DRAW
void ExampleState::Draw(float deltaTime) 
{
 
}


// EXIT
void ExampleState::Exit() 
{
    HAMURWORLD->DeleteObject("Tank");
}


