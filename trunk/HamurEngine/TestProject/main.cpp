/*
	Hamur II - June 2010

	This main.cpp is written to test Hamur Engine. 

	Programming by:
	- Daghan DEMIRCI <daghan.demirci@gmail.com>
	- Omer AKYOL	 <omer.akyol@gmail.com>
*/

#include "hamur.h"
#include "ExampleState.h"

using namespace hamur;

int main(int argc, char *argv[])
{
    if(HAMURENGINE->init("Hamur II test - 2010", 800, 600) == false)
        return 1;

    HAMURENGINE->disableMouseCursor();
    
    HAMURSTATEMR->registerState(new ExampleState());
    HAMURSTATEMR->changeState("ExampleState");
    HAMURENGINE->run();
    HAMURENGINE->terminate();
	
    return 0;
}
