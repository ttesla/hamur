#include "hamurState.h"

namespace hamur
{

	HamurState::HamurState()
	{

	}


	HamurState::HamurState(const string &_stateName)
	{
		stateName = _stateName;
	}


	HamurState::~HamurState()
	{

	}


	string HamurState::getStateName()
	{
		return stateName;
	}

}