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
#include "hamurFont.h"
#include "audio/hamurAuMR.h"
#include "hamurDefinitions.h"

using namespace hamur;


// GLOBALS -- for test usage only.
float x = 0, y = 0, z = 0, xcor = 0, ycor = 0, zcor = 0;

// Some test functions
void testDisplay();
void testSimulation();


int main( int argc, char *argv[] )
{
    //Initialize SDL
	if(HAMURGL->initSDL("Hamur II test - 2009", 1024, 768, 32, SDL_OPENGL  | SDL_FULLSCREEN ) == false)
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
	HAMURFONT->getInstance();
    HAMUREVENT->getInstance();
	HAMURGP->getInstance();


	// Main while
	while(! HAMUREVENT->isQuitPerformed())
	{
		// Handle all events
		HAMUREVENT->handleEvents();

		if(HAMUREVENT->isKeyPressed(SDLK_ESCAPE)) break; // If ESC is pressed break from while()

	    // TESTS
		testDisplay();
		testSimulation();
	    
	    //Update screen
	    SDL_GL_SwapBuffers();   
	}
	
	//Clean up & quit
	HAMURGL->quit();
	
	return 0;
}

// Test functions...
void testDisplay()
{   
	//Clear the screen & reset identity matrix
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glTranslatef(0.0f, 0.0f, -1.0f);

	glRotatef(x/10, 1.0f, 0.0f, 0.0f); // Rotate On The X Axis
    glRotatef(y/10, 0.0f, 1.0f, 0.0f); // Rotate On The Y Axis
    glRotatef(z/10, 0.0f, 0.0f, 1.0f); // Rotate On The Z Axis

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
