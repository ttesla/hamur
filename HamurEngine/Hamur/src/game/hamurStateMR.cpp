#include "hamurStateMR.h"
namespace hamur
{
	HamurStateMR::HamurStateMR()
	{
		currentState = NULL;
		previousState = NULL;
	}


	HamurStateMR::~HamurStateMR()
	{
		map<string, HamurState*>::iterator iter;

		for(iter = stateList.begin(); iter != stateList.end(); iter++)
		{
			if(iter->second)
				delete iter->second;
		}
	}


    // Add state into "map" container with state name.
    // If state is already registered, it will not be registered.
	void HamurStateMR::registerState(const string &_stateName, HamurState *_state)
	{
		// Look in the map if the state is already registered. If not found, then register.
		if ( !(hasState(_stateName)))
        {
			stateList[_stateName] = _state;
		}
	}


    // Search through the "map" container and remove state.
    // If it is successful, return true else false.
	bool HamurStateMR::removeState(const string &_stateName)
	{
		// Get the state from the map.
		bool bFound = false;
		map<string, HamurState*>::iterator iter = stateList.find(_stateName);

		if(iter != stateList.end())
		{
			// If it was found, delete it then. 
			bFound = true;
			stateList.erase(iter);
		}

		return bFound;
	}


	// Checks if the manager has the given state.
	bool HamurStateMR::hasState(const string &_stateName)
	{
		// Look in the map if the state exists.
		map<string, HamurState*>::iterator iter = stateList.find(_stateName);

		// If not found, return false.
		if(iter == stateList.end())
			return false;

		return true;
	}


    // Returns state with the given name. 
	HamurState* HamurStateMR::findState(const string &_stateName)
	{
		// Look in the map.
		map<string, HamurState*>::iterator iter = stateList.find(_stateName);

		// If not found, return NULL.
		if(iter == stateList.end())
		{
			HAMURLOG->write_log("Can't find the given state.");
			return NULL;
		}

		return iter->second;
	}


    // Changes the current state to the given state. 
	void HamurStateMR::changeState(const string &_stateName)
	{
        if(hasState(_stateName))
        {
		    currentState->exit();
		    currentState = this->findState(_stateName);
		    currentState->enter();
        }
        else
            HAMURLOG->write_log("Can't change current state. State does not exists.");
	}


	// Checks if Current State available. If so returns it.
	HamurState* HamurStateMR::getCurrentState()
	{
		if(currentState == NULL)
		{
			HAMURLOG->write_log("Current state is not SET yet");
			return NULL;
		}
		
		return currentState;
	}


	// Checks if Current State available. If so returns its name.
	string HamurStateMR::getCurrentStateName()
	{
		if(currentState == NULL)
		{
			HAMURLOG->write_log("Current state is not SET yet");
			return NULL;
		}

		return currentState->getStateName();
	}


	// Checks if Previous State available. If so returns its name.
	string HamurStateMR::getPreviousStateName()
	{
		if(previousState == NULL)
		{
			HAMURLOG->write_log("Previous state is not SET yet");

			return NULL;
		}

		return previousState->getStateName();
	}
}
