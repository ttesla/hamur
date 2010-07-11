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
        HAMURLOG->writeTerminateLog("HamurStateMR");
	}


    // Init Hamur State Manager
    bool HamurStateMR::Init()
    {
        mCurrentState = NULL;
        mPreviousState = NULL;
        HAMURLOG->writeInitLog("HamurStateMR");

        return true; // We dont have much choice here :)
    }


    // Add state into "map" container with state name.
    // If state is already registered, it will not be registered.
	bool HamurStateMR::RegisterState(HamurState *_state)
	{
		// Look in the map if the state is already registered. If not found, then register.
        if (HasState(_state->GetStateName()))
        {
            HAMURLOG->writeLogln("Error!: Can't register state, state already exists: " 
                + _state->GetStateName(), HamurLog::ALWAYS);
            return false;
        }

		mStateList[_state->GetStateName()] = _state;

        HAMURLOG->writeLogln("State registered: " + _state->GetStateName());
        return true;
	}


    // Search through the "map" container and remove & delete state.
    // If it is successful, return true else false.
	bool HamurStateMR::DeleteState(const string &_stateName)
	{
		map<string, HamurState*>::iterator iter = mStateList.find(_stateName);

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
	bool HamurStateMR::HasState(const string &_stateName)
	{
		// Look in the map if the state exists.
		map<string, HamurState*>::iterator iter = mStateList.find(_stateName);

		// If not found, return false.
		if(iter == mStateList.end())
			return false;

		return true;
	}


    // Returns state with the given name. 
	HamurState* HamurStateMR::FindState(const string &_stateName)
	{
		// Look in the map.
		map<string, HamurState*>::iterator iter = mStateList.find(_stateName);

		// If not found, return NULL.
		if(iter == mStateList.end())
		{
            HAMURLOG->writeLogln("Error!: Can't find the given state: " 
                + _stateName, HamurLog::ALWAYS);
			return NULL;
		}

		return iter->second;
	}


    // Changes the current state to the given state. 
	void HamurStateMR::ChangeState(const string &_stateName)
	{
        if(HasState(_stateName))
        {
            if(mCurrentState != NULL)
            {
                mCurrentState->Exit();
                mPreviousState = mCurrentState;
            }
            
		    mCurrentState = FindState(_stateName);
		    mCurrentState->Enter();
        }
        else
        {
            HAMURLOG->writeLogln("Error!: Can't change current state. "
                                 "State does not exists: " + _stateName, 
                                 HamurLog::ALWAYS);
        }
	}


	// Checks if Current State available. If so returns it.
	HamurState* HamurStateMR::GetCurrentState()
	{
		if(mCurrentState == NULL)
		{
            HAMURLOG->writeLogln("Error!: Current state is not SET yet.", 
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
            HAMURLOG->writeLogln("Error!: Current state is not SET yet.", 
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
            HAMURLOG->writeLogln("Error!: Previous state is not SET yet.", 
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

        HAMURLOG->writeLogln("All state objects deleted.");
    }

} // namespace hamur
