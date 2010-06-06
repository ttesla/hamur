#include "MainState.h"


// Calling HamurState("Name") is a must!
MainState::MainState() : HamurState("MainState")
{
    angle1 = 0;

}

MainState::~MainState()
{

}


// ENTER
void MainState::enter() 
{
    // Add some objects
    HAMURWORLD->addObject(new HamurObject("Balik"));
    HAMURWORLD->getObject("Balik")->setSprite("data/fish.png");
    HAMURWORLD->getObject("Balik")->setPosition(100, 100);

    HAMURWORLD->addObject(new HamurObject("Tank", "data/Tank.png"));
    HAMURWORLD->getObject("Tank")->setPosition(200, 300);
    HAMURWORLD->getObject("Tank")->rotateDegree(90);
}


// UPDATE
void MainState::update() 
{
    if(HAMUREVENT->isKeyPressed(SDLK_ESCAPE)) 
        HAMURENGINE->stop();

    if(HAMUREVENT->isKeyPressed(SDLK_UP))	    angle1 += 0.5f;
    if(HAMUREVENT->isKeyPressed(SDLK_DOWN))	    angle1 -= 0.5f;

    HAMURWORLD->getObject("Balik")->rotateDegree(-angle1*10);
   
    HAMURCONSOLE << "Angle1:" << angle1 << "\n";
}


// DRAW
void MainState::draw() 
{
  
    HAMURWORLD->getObject("Balik")->draw();
    HAMURWORLD->getObject("Tank")->draw();
}


// EXIT
void MainState::exit() 
{

}