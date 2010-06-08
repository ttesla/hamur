#include "hamurState.h"

namespace hamur
{
	HamurState::HamurState(const string &_stateName)
	{
		stateName = _stateName;
	}


	HamurState::~HamurState()
	{
        HAMURLOG->writeLogln("State deleted: " + stateName);
	}


	string HamurState::getStateName()
	{
		return stateName;
	}
}