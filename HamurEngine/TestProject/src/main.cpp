/*
	Hamur II - June 2010

	This main.cpp is written to test Hamur Engine.

	Programming by:
	- Daghan DEMIRCI <daghan.demirci@gmail.com>
	- Omer AKYOL	 <omer.akyol@gmail.com>
*/

//#include "hamur.h"
#include "ExampleState.h"
#include "MainState.h"

using namespace hamur;


int main(int argc, char *argv[])
{
    if(HAMURENGINE->Init("Hamur II test - 2010", 800, 600) == false)
        return 1;

    // Set debug mode for logging
    HAMURLOG->SetDebugMode(true);

    HAMURENGINE->DisableMouseCursor();

    HAMURSTATEMR->RegisterState(new ExampleState());
    HAMURSTATEMR->RegisterState(new MainState());
    HAMURSTATEMR->ChangeState("ExampleState");
    HAMURENGINE->Run();
    HAMURENGINE->Terminate();

    return 0;
}
