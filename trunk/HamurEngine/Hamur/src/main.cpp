/*
	Hamur II - October 2009

	This main.cpp is written to test Hamur II. 

	Programming by:
	- Daghan DEMIRCI <daghan.demirci@gmail.com>
	- Omer AKYOL	 <omer.akyol@gmail.com>
*/

#include "hamurGL.h"
#include "hamurEvent.h"
#include "hamurTexMR.h"
#include "hamurGP.h"
#include "helper/hamurLog.h"
#include "helper/hamurConsole.h"
#include "hamurFont.h"
#include "audio/hamurAuMR.h"
#include "hamurDefinitions.h"
#include "game/hamurWorld.h"
#include "game/hamurObject.h"
#include "helper/hamurString.h"
#include <sstream>

using namespace hamur;
using std::stringstream;


// GLOBALS -- for test usage only.
float x = 0, y = 0, z = 0, xcor = 0, ycor = 0, zcor = 0;
float angle1 = 0, angle2 = 0;

// Some test functions
void testDisplay(unsigned int, unsigned int);
void testSimulation();
void testGameObjects();

int main( int argc, char *argv[] )
{
    //Initialize SDL
	if(HAMURGL->initSDL("Hamur II test - 2009", 800, 600, 32, SDL_OPENGL) == false)
	//if(HAMURGL->init_SDL("Hamur II test - 2009", 1024, 768, 32, SDL_OPENGL) == false) 
		return 1;    

	//Initialize OpenGL
	if(HAMURGL->initGL() == false) 
		return 1; 

	// Disable mouse
	SDL_ShowCursor(SDL_DISABLE);

	// Init all other Hamur subsystems...
	HAMURTEXMR->getInstance();
	HAMURAUMR->init();
	//HAMURFONT->getInstance();
    HAMUREVENT->getInstance();
	HAMURGP->getInstance();
    HAMURWORLD->getInstance();

    

    HAMURCONSOLE << "Testing hamur console\n";  

    unsigned int firstTex = HAMURTEXMR->addTexture("data/daghan.png");
    unsigned int secondTex = HAMURTEXMR->addTexture("data/omer.png");

	// Main while
	while(! HAMUREVENT->isQuitPerformed())
	{
		// Handle all events
		HAMUREVENT->handleEvents();

		if(HAMUREVENT->isKeyPressed(SDLK_ESCAPE)) break; // If ESC is pressed break from while()

	    // TESTS
		testDisplay(firstTex, secondTex);
		testSimulation();
        //testGameObjects();
	    
	    //Update screen
	    SDL_GL_SwapBuffers();   
	}
	
	//Clean up & quit
	HAMURGL->quit();
	
	return 0;
}

// Test functions...
void testDisplay(unsigned int first, unsigned int second)
{

    if(HAMUREVENT->isKeyPressed(SDLK_RIGHT))	angle1 += 0.1;
    if(HAMUREVENT->isKeyPressed(SDLK_LEFT))	    angle1 -= 0.1;

    HAMURCONSOLE << angle1 << "\n";
    //if(HAMUREVENT->isKeyPressed(SDLK_UP))		angle2 += 0.1;
    //if(HAMUREVENT->isKeyPressed(SDLK_DOWN))	    angle2 -= 0.1;*/

    //Clear the screen & reset identity matrix
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -1.0f);

    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    glTranslatef(0.5,0.5,0.0);
    glRotatef(angle1, 0.0, 0.0, 1.0);
    glTranslatef(-0.5,-0.5,0.0);

    

	//glRotatef(x/10, 1.0f, 0.0f, 0.0f); // Rotate On The X Axis
    //glRotatef(y/10, 0.0f, 1.0f, 0.0f); // Rotate On The Y Axis
    //glRotatef(z/10, 0.0f, 0.0f, 1.0f); // Rotate On The Z Axis

    HAMURTEXMR->blitTexture(first, 0, 0, 0);

    glMatrixMode(GL_MODELVIEW);

	// Wireframe - May be handy
	//glPolygonMode(GL_FRONT, GL_LINE);
	//glPolygonMode(GL_BACK, GL_LINE);

	//xcor = -0.55f + HAMUREVENT->getMouseX()*(1.10f/1024);
	//ycor = 0.42f - HAMUREVENT->getMouseY()*(0.84f/768);
	//HAMURTEXMR->blitTexture("red", xcor, ycor, 0);

	//cout << "X:" << xcor << " Y:" << ycor << " Z:" << zcor << endl;
	//cout << "rotX:" << x << " rotY:" << y << " rotZ:" << z << endl;
}

void testSimulation()
{
	float vel1 = 0.1f;
	float vel2 = 0.2f;
	// KEYS
	if(HAMUREVENT->isKeyPressed(SDLK_RIGHT))	x += vel1;
	if(HAMUREVENT->isKeyPressed(SDLK_LEFT))	    x -= vel1;
	if(HAMUREVENT->isKeyPressed(SDLK_UP))		y += vel1;
	if(HAMUREVENT->isKeyPressed(SDLK_DOWN))	    y -= vel1;
	if(HAMUREVENT->isKeyPressed(SDLK_z))		z -= vel1;
	if(HAMUREVENT->isKeyPressed(SDLK_x))		z += vel1;
	if(HAMUREVENT->isKeyPressed(SDLK_q))		zcor -= vel2;
	if(HAMUREVENT->isKeyPressed(SDLK_e))		zcor += vel2;
	if(HAMUREVENT->isKeyPressed(SDLK_d))		xcor += vel2;
	if(HAMUREVENT->isKeyPressed(SDLK_a))		xcor -= vel2;
	if(HAMUREVENT->isKeyPressed(SDLK_w))		ycor += vel2;
	if(HAMUREVENT->isKeyPressed(SDLK_s))		ycor -= vel2;
}

void testGameObjects()
{
    HamurObject* myFirstObject = new HamurObject("Araba");
    //HamurObject* secondObject = new HamurObject("Player");

    myFirstObject->setPosition(0, 0, 0);
    //secondObject->setPosition(5, 5, 5);

    myFirstObject->setSprite("data/daghan.png");
    //HAMURLOG->write_log(myFirstObject->getSpriteID());
    myFirstObject->draw();

    stringstream ss;
    stringstream ss2;
    stringstream ss3;
    /*

    ss << "First Object Name: " << HAMURWORLD->getObject("Player")->getName() << ", Position: "  <<
        HAMURWORLD->getObject("Player")->getPosition();
    cout << "First Object Name: " << HAMURWORLD->getObject("Player")->getName() << " Position:  "  <<
        HAMURWORLD->getObject("Player")->getPosition() << endl;

    ss2 << "Second Object Name: " << HAMURWORLD->getObject("Araba")->getName() << " Position: "  <<
        HAMURWORLD->getObject("Araba")->getPosition();

    cout << "Second Object Name: " << HAMURWORLD->getObject("Araba")->getName() << " Position:  "  <<
        HAMURWORLD->getObject("Araba")->getPosition() << endl;
        */


    /*
    HamurString mystring;

    mystring << "Atisma degeri :" << 10 << 30.6;

    HAMURFONT->drawText(mystring, -0.3f, -0.07f, 0);

    mystring = 10.7;
    mystring.clear();


    HAMURFONT->drawText(mystring, -0.3f, -0.10f, 0);

    */

   
    //HAMURFONT->drawText(ss3.str, -0.4f, 0.0f, 0);

    //cout << ss2.str() << "hoppa";
}
