#include "hamurStateMR.h"
#include "hamurState.h"
#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"


namespace hamur
{

HamurStateMR::HamurStateMR()
{
    // empty
}


HamurStateMR::~HamurStateMR()
{
    ClearAll();
    HAMURLOG->WriteTerminateLog("HamurStateMR");
}


// Init Hamur State Manager
bool HamurStateMR::Init()
{
    mCurrentState = NULL;
    mPreviousState = NULL;
    HAMURLOG->WriteInitLog("HamurStateMR");

    return true; // We dont have much choice here :)
}


// Add state into "map" container with state name.
// If state is already registered, it will not be registered.
bool HamurStateMR::RegisterState(HamurState* state)
{
	// Look in the map if the state is already registered. If not found, then register.
    if (HasState(state->GetStateName()))
    {
        HAMURLOG->WriteLogln("Error!: Can't register state, state already exists: " 
            + state->GetStateName(), HamurLog::ALWAYS);
        return false;
    }

	mStateList[state->GetStateName()] = state;

    HAMURLOG->WriteLogln("State registered: " + state->GetStateName());
    return true;
}


// Search through the "map" container and remove & delete state.
// If it is successful, return true else false.
bool HamurStateMR::DeleteState(const string& stateName)
{
	map<string, HamurState*>::iterator iter = mStateList.find(stateName);

	if(iter != mStateList.end())
	{
        // If it was found, delete it then. 
        if(iter->second)
            delete iter->second;
		
		mStateList.erase(iter);

        return true;
	}

	return false;
}


// Checks if the manager has the given state.
bool HamurStateMR::HasState(const string& stateName)
{
	// Look in the map if the state exists.
	map<string, HamurState*>::iterator iter = mStateList.find(stateName);

	// If not found, return false.
	if(iter == mStateList.end())
		return false;

	return true;
}


// Returns state with the given name. 
HamurState* HamurStateMR::FindState(const string& stateName)
{
	// Look in the map.
	map<string, HamurState*>::iterator iter = mStateList.find(stateName);

	// If not found, return NULL.
	if(iter == mStateList.end())
	{
        HAMURLOG->WriteLogln("Error!: Can't find the given state: " 
            + stateName, HamurLog::ALWAYS);
		return NULL;
	}

	return iter->second;
}


// Changes the current state to the given state. 
void HamurStateMR::ChangeState(const string& stateName)
{
    if(HasState(stateName))
    {
        if(mCurrentState != NULL)
        {
            mCurrentState->Exit();
            mPreviousState = mCurrentState;
        }
        
	    mCurrentState = FindState(stateName);
	    mCurrentState->Enter();
    }
    else
    {
        HAMURLOG->WriteLogln("Error!: Can't change current state. "
                             "State does not exists: " + stateName, 
                             HamurLog::ALWAYS);
    }
}


// Checks if Current State available. If so returns it.
HamurState* HamurStateMR::GetCurrentState()
{
	if(mCurrentState == NULL)
	{
        HAMURLOG->WriteLogln("Error!: Current state is not SET yet.", 
            HamurLog::ALWAYS);
		return NULL;
	}
	
	return mCurrentState;
}


// Checks if Current State available. If so returns its name.
string HamurStateMR::GetCurrentStateName()
{
	if(mCurrentState == NULL)
	{
        HAMURLOG->WriteLogln("Error!: Current state is not SET yet.", 
            HamurLog::ALWAYS);
		return NULL;
	}

	return mCurrentState->GetStateName();
}


// Checks if Previous State available. If so returns its name.
string HamurStateMR::GetPreviousStateName()
{
	if(mPreviousState == NULL)
	{
        HAMURLOG->WriteLogln("Error!: Previous state is not SET yet.", 
            HamurLog::ALWAYS);

		return NULL;
	}

	return mPreviousState->GetStateName();
}


// Delete all state objects in the State Manager
void HamurStateMR::ClearAll()
{
    map<string, HamurState*>::iterator iter;

    for(iter = mStateList.begin(); iter != mStateList.end(); iter++)
    {
        if(iter->second)
            delete iter->second;
    }

    HAMURLOG->WriteLogln("All state objects deleted.");
}

} // namespace hamur
