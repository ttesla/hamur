/*
	Backteria Game

	Programming by:
	- Sitki Emre Solak
	- Edu 

	Graphics by:
	- Victor

	Music by:
	- ?
*/

#include "hamur.h"
#include "IngameState.h"
#include "time.h"

using namespace hamur;


int main(int argc, char *argv[])
{
	srand((unsigned)time(0)); 

    if(HAMURENGINE->Init("Bacteria Outbreak! - 2010", 800, 600) == false)
        return 1;

	HAMURENGINE->SetBackgroundColor(HamurColor::WHITE);
    //HAMURENGINE->DisableMouseCursor();

	HAMURSTATEMR->RegisterState(new IngameState());
	HAMURSTATEMR->ChangeState("IngameState");

    HAMURENGINE->Run();
    HAMURENGINE->Terminate();

    return 0;
}
