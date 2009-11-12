#ifndef HAMUR_STATEMR_H
#define HAMUR_STATEMR_H

#include "../hamurSingleton.h"
#include "hamurState.h"
#include "../helper/hamurLog.h"
#include "../hamurDefinitions.h"

#include <map>

using std::map;

namespace hamur
{
    /**
    * Hamur State Manager
    * All states are registered and managed here. 
    */
	class HamurStateMR : public Singleton<HamurStateMR>
	{
		public:
			HamurStateMR();

            /**
            * Destructor of Hamur State Manager.
            * Destroys all registered states.
            */
			~HamurStateMR();

            /**
            * Registers given state to the state manager.
            * If state is already registered, it will not be registered.
            * @param _stateName Name of the state
            * @param _state Object of the state
            * @see removeState()
            */
			void registerState(const string &_stateName, HamurState *_state);

            /**
            * Removes state from state manager, unregister state.
            * @param _stateName Name of the state which will be removed.
            * @return If state is removed successfully or not
            * @see registerState()
            */
			bool removeState(const string &_stateName);

            /**
            * Checks if the manager has the given state.
            * @param _stateName Name of the state.
            * @return If given state is found or not
            */
			bool hasState(const string &_stateName);

            /**
            * Returns state with the given name. 
            * @param _stateName Name of the state
            * @return State object, NULL if it is not found.
            */
			HamurState* findState(const string &_stateName);

			/** 
            * Changes the current state to the given state. 
            * @param _stateName Name of the state which will be changed to.
            */
			void changeState(const string &_stateName);

            /**
            * Get current state.
            * @return Object of the current state
            * @see getPreviousState();
            */
			HamurState* getCurrentState();

            /**
            * Get previous state.
            * @return Object of the previous state
            * @see getCurrentState()
            */
			HamurState* getPreviousState();

            /**
            * Get current state name.
            * @return Name of the current state
            * @see getPreviousStateName()
            */
			string getCurrentStateName();

            /**
            * Get previous state name.
            * @return Name of the previous state
            * @see getPreviousStateName()
            */
			string getPreviousStateName();

		protected:

		private:
			map<string, HamurState*> stateList; /**< Stores all states according to their names. */
			HamurState* currentState; /** Current state of the game. */
			HamurState* previousState; /**< Previous state of the game. */ 
	};
}

#endif // HAMURSTATEMR_H
