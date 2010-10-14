/*
	Hamur - October 2010

	This is the testing lab of Hamur Engine.

	Programming by:
	- Daghan DEMIRCI <daghan.demirci@gmail.com>
	- Omer AKYOL	 <omer.akyol@gmail.com>
*/

#include "hamur.h"
#include "TestState.h"

using namespace hamur;


int main(int argc, char *argv[])
{
    if(HAMURENGINE->Init("Hamur Test Project - 2010", 800, 600) == false)
        return 1;

    // Set debug mode for logging
    HAMURLOG->SetDebugMode(true);

    HAMURENGINE->DisableMouseCursor();

    HAMURSTATEMR->RegisterState(new TestState());
	HAMURSTATEMR->ChangeState("TestState");
    HAMURENGINE->Run();
    HAMURENGINE->Terminate();

    return 0;
}
