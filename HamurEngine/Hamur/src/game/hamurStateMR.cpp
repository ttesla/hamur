#include "hamurStateMR.h"
namespace hamur
{
	HamurStateMR::HamurStateMR()
	{
        // empty
	}


	HamurStateMR::~HamurStateMR()
	{
        clearAll();
        HAMURLOG->writeTerminateLog("HamurStateMR");
	}


    // Init Hamur State Manager
    bool HamurStateMR::init()
    {
        currentState = NULL;
        previousState = NULL;
        HAMURLOG->writeInitLog("HamurStateMR");

        return true; // We dont have much choice here :)
    }


    // Add state into "map" container with state name.
    // If state is already registered, it will not be registered.
	bool HamurStateMR::registerState(HamurState *_state)
	{
		// Look in the map if the state is already registered. If not found, then register.
        if (hasState(_state->getStateName()))
        {
            HAMURLOG->writeLogln("Error!: Can't register state, state already exists: " 
                + _state->getStateName(), HamurLog::ALWAYS);
            return false;
        }

		stateList[_state->getStateName()] = _state;

        HAMURLOG->writeLogln("State registered: " + _state->getStateName());
        return true;
	}


    // Search through the "map" container and remove & delete state.
    // If it is successful, return true else false.
	bool HamurStateMR::deleteState(const string &_stateName)
	{
		map<string, HamurState*>::iterator iter = stateList.find(_stateName);

		if(iter != stateList.end())
		{
            // If it was found, delete it then. 
            if(iter->second)
                delete iter->second;
			
			stateList.erase(iter);

            return true;
		}

		return false;
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
            HAMURLOG->writeLogln("Error!: Can't find the given state: " 
                + _stateName, HamurLog::ALWAYS);
			return NULL;
		}

		return iter->second;
	}


    // Changes the current state to the given state. 
	void HamurStateMR::changeState(const string &_stateName)
	{
        if(hasState(_stateName))
        {
            if(currentState != NULL)
            {
                currentState->exit();
                previousState = currentState;
            }
            
		    currentState = findState(_stateName);
		    currentState->enter();
        }
        else
        {
            HAMURLOG->writeLogln("Error!: Can't change current state. "
                                 "State does not exists: " + _stateName, 
                                 HamurLog::ALWAYS);
        }
	}


	// Checks if Current State available. If so returns it.
	HamurState* HamurStateMR::getCurrentState()
	{
		if(currentState == NULL)
		{
            HAMURLOG->writeLogln("Error!: Current state is not SET yet.", 
                HamurLog::ALWAYS);
			return NULL;
		}
		
		return currentState;
	}


	// Checks if Current State available. If so returns its name.
	string HamurStateMR::getCurrentStateName()
	{
		if(currentState == NULL)
		{
            HAMURLOG->writeLogln("Error!: Current state is not SET yet.", 
                HamurLog::ALWAYS);
			return NULL;
		}

		return currentState->getStateName();
	}


	// Checks if Previous State available. If so returns its name.
	string HamurStateMR::getPreviousStateName()
	{
		if(previousState == NULL)
		{
            HAMURLOG->writeLogln("Error!: Previous state is not SET yet.", 
                HamurLog::ALWAYS);

			return NULL;
		}

		return previousState->getStateName();
	}

    
    // Delete all state objects in the State Manager
    void HamurStateMR::clearAll()
    {
        map<string, HamurState*>::iterator iter;

        for(iter = stateList.begin(); iter != stateList.end(); iter++)
        {
            if(iter->second)
                delete iter->second;
        }

        HAMURLOG->writeLogln("All state objects deleted.");
    }
}