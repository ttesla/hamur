/*
	Hamur II - October 2009

	This main.cpp is written to test Hamur II. 

	Programming by:
	- Daghan DEMIRCI <daghan.demirci@gmail.com>
	- Omer AKYOL	 <omer.akyol@gmail.com>
*/

#include "hamur.h"

#include <sstream>

using namespace hamur;
using std::stringstream;


// GLOBALS -- for test usage only.
float x = 0, y = 0, z = 0, xcor = 0, ycor = 0, zcor = 0;
float angle1 = 0, angle2 = 0;
float camX = 0, camY = 0, camZ = 0;
int Z = 0;

// Some test functions
void testDisplay(unsigned int, unsigned int);
void testSimulation();
void testGameObjects();
int DrawGLScene(GLvoid);

int main( int argc, char *argv[] )
{
    //Initialize SDL
	if(HAMURGL->initSDL("Hamur II test - 2010", 800, 600, 32, SDL_OPENGL) == false)
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

    // :::: TESTING ::::
    HAMURWORLD->addObject(new HamurObject("Balik"));
    HAMURWORLD->getObject("Balik")->setSprite("data/fish.png");
    HAMURWORLD->addObject(new HamurObject("Tank", "data/Tank.png"));
    
    unsigned int firstTex = HAMURTEXMR->addTexture("data/dot.png");
    unsigned int secondTex = HAMURTEXMR->addTexture("data/omer.png");
    // :::: TESTING ::::

	// Main while
	while(! HAMUREVENT->isQuitPerformed())
	{
		// Handle all events
		HAMUREVENT->handleEvents();

		if(HAMUREVENT->isKeyPressed(SDLK_ESCAPE)) break; // If ESC is pressed break from while()

	    // TESTS
        testSimulation();
        testGameObjects();
		testDisplay(firstTex, secondTex);
	    
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
    //if(HAMUREVENT->isKeyPressed(SDLK_UP))	    angle1 += 0.5f;
    //if(HAMUREVENT->isKeyPressed(SDLK_DOWN))	    angle1 -= 0.5f;

    //Clear the screen & reset identity matrix
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //glDisable(GL_TEXTURE_2D);
    ////glLoadIdentity();									// Reset The Current Modelview Matrix
    //glTranslatef(-1.5f,0.0f,-6.0f);						// Move Left 1.5 Units And Into The Screen 6.0
    //glRotatef(angle1,0.0f,1.0f,0.0f);						// Rotate The Triangle On The Y axis ( NEW )
    //glBegin(GL_TRIANGLES);								// Start Drawing A Triangle
    //    glColor3f(1.0f,0.0f,0.0f);						// Set Top Point Of Triangle To Red
    //    glVertex3f( 0.0f, 1.0f, 0.0f);					// First Point Of The Triangle
    //    glColor3f(0.0f,1.0f,0.0f);						// Set Left Point Of Triangle To Green
    //    glVertex3f(-1.0f,-1.0f, 0.0f);					// Second Point Of The Triangle
    //    glColor3f(0.0f,0.0f,1.0f);						// Set Right Point Of Triangle To Blue
    //    glVertex3f( 1.0f,-1.0f, 0.0f);					// Third Point Of The Triangle
    //glEnd();											// Done Drawing The Triangle
    //glEnable(GL_TEXTURE_2D);

    camX = -x;
    camY = -y;
    camZ = z;

    glTranslatef(camX, camY, camZ);
  
    HAMURWORLD->getObject("Balik")->rotate(-angle1*10);
    HAMURWORLD->getObject("Balik")->draw();
    
    HAMURWORLD->getObject("Tank")->draw();
    HAMURWORLD->getObject("Tank")->setPosition(200, 300);
    HAMURWORLD->getObject("Tank")->rotate(angle1);
    HAMURWORLD->getObject("Tank")->draw();
  
    HAMURTEXMR->blitTexture(first, 798, 598, 0);
  
    HAMURCONSOLE << "Angle1:" << angle1 << "\n";
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
    HamurObject *object = HAMURWORLD->getObject("Balik");
    object->setPosition(100, 100);
    object = HAMURWORLD->getObject("Tank");
    object->setPosition(500, 200);
}

