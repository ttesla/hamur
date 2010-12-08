#include "hamurTimer.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"


namespace hamur
{

// HamurTimer constructor
HamurTimer::HamurTimer() : mDeltaTime(0.0)
{
	
}


// HamurLog destructor
HamurTimer::~HamurTimer()
{
    HAMURLOG->WriteTerminateLog("HamurTimer");
}


// Initialize Hamur Timer
bool HamurTimer::Init()
{
    HAMURLOG->WriteInitLog("HamurTimer");
    return true;
}


} // namespace hamur
