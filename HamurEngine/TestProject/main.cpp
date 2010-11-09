/*
	Bacteria Game

	Programming by:
	- Sitki Emre Solak
	- Edu 

	Graphics by:
	- Victor

	Music by:
	- Elton John
*/

#include "hamur.h"
#include "MenuState.h"
#include "SelectionState.h"
#include "IngameState.h"
#include "FeedbackState.h"
#include "time.h"

using namespace hamur;


int main(int argc, char *argv[])
{
	srand((unsigned)time(0)); 

    if(HAMURENGINE->Init("Bacteria Outbreak! - 2010", 800, 600) == false)
        return 1;

	HAMURENGINE->SetBackgroundColor(HamurColor::WHITE);
    //HAMURENGINE->DisableMouseCursor();

	// Registering the states of the game:
	HAMURSTATEMR->RegisterState(new MenuState());
	HAMURSTATEMR->RegisterState(new SelectionState());
	HAMURSTATEMR->RegisterState(new IngameState());
	HAMURSTATEMR->RegisterState(new FeedbackState());

	HAMURSTATEMR->ChangeState("MenuState");
	//HAMURSTATEMR->ChangeState("FeedbackState");
	
    HAMURENGINE->Run();
    HAMURENGINE->Terminate();

    return 0;
}
