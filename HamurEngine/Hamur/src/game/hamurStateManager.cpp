#include "hamurStateManager.h"
#include "hamurState.h"
#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"


namespace hamur
{

HamurStateManager::HamurStateManager()
{
    // empty
}


HamurStateManager::~HamurStateManager()
{
    ClearAll();
    HAMURLOG->WriteTerminateLog("HamurStateManager");
}


// Init Hamur State Manager
bool HamurStateManager::Init()
{
    mCurrentState = NULL;
    mPreviousState = NULL;
    HAMURLOG->WriteInitLog("HamurStateManager");

    return true; // We dont have much choice here :)
}


// Add state into "map" container with state name.
// If state is already registered, it will not be registered.
bool HamurStateManager::RegisterState(HamurState* state)
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
bool HamurStateManager::DeleteState(const string& stateName)
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
bool HamurStateManager::HasState(const string& stateName)
{
	// Look in the map if the state exists.
	map<string, HamurState*>::iterator iter = mStateList.find(stateName);

	// If not found, return false.
	if(iter == mStateList.end())
		return false;

	return true;
}


// Returns state with the given name. 
HamurState* HamurStateManager::FindState(const string& stateName)
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
void HamurStateManager::ChangeState(const string& stateName)
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
HamurState* HamurStateManager::GetCurrentState()
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
string HamurStateManager::GetCurrentStateName()
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
string HamurStateManager::GetPreviousStateName()
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
void HamurStateManager::ClearAll()
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
