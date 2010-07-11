#include "hamurState.h"
#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"

namespace hamur
{

HamurState::HamurState(const string& stateName)
{
	mStateName = stateName;
}


HamurState::~HamurState()
{
    HAMURLOG->writeLogln("State deleted: " + mStateName);
}


string HamurState::GetStateName() const
{
	return mStateName;
}

} // namespace hamur
