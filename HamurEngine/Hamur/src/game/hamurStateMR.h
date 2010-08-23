#ifndef HAMUR_STATEMR_H
#define HAMUR_STATEMR_H

#include "../hamurSingleton.h"

#include <map>
#include <string>

using std::map;
using std::string;

namespace hamur
{

// Forward decleration
class HamurState;

/**
* Hamur State Manager
* All states are registered and managed here.
*/
class HamurStateMR : public Singleton<HamurStateMR>
{
	public:

        friend class Singleton<HamurStateMR>;

        /**
        * Initialize Hamur State Manager
        * @return True if initialization is successful else return False
        */
        bool Init();

        /**
        * Registers given state to the state manager.
        * If state is already registered, it will not be registered.
        * @param state Object of the state
        * @return True if register is successful else return False
        * @see RemoveState()
        */
		bool RegisterState(HamurState* state);

        /**
        * Removes and deletes state from state manager.
        * @param stateName Name of the state which will be removed.
        * @return If state is removed successfully or not
        * @see RegisterState()
        */
		bool DeleteState(const string& stateName);

        /**
        * Checks if the manager has the given state.
        * @param stateName Name of the state.
        * @return If given state is found or not
        */
		bool HasState(const string& stateName);

        /**
        * Returns state with the given name.
        * @param stateName Name of the state
        * @return State object, NULL if it is not found.
        */
		HamurState* FindState(const string& stateName);

		/**
        * Changes the current state to the given state.
        * @param stateName Name of the state which will be changed to.
        */
		void ChangeState(const string& stateName);

        /**
        * Get current state.
        * @return Object of the current state
        * @see GetPreviousState();
        */
		HamurState* GetCurrentState();

        /**
        * Get previous state.
        * @return Object of the previous state
        * @see GetCurrentState()
        */
		HamurState* GetPreviousState();

        /**
        * Get current state name.
        * @return Name of the current state
        * @see GetPreviousStateName()
        */
		string GetCurrentStateName();

        /**
        * Get previous state name.
        * @return Name of the previous state
        * @see GetPreviousStateName()
        */
		string GetPreviousStateName();

        /**
        * Clear and delete all state objects in the State Manager
        */
        void ClearAll();

	protected:

        HamurStateMR();

        /**
        * Destructor of Hamur State Manager.
        * Destroys all registered states.
        */
        ~HamurStateMR();

	private:
		map<string, HamurState*> mStateList; /**< Stores all states according to their names. */
		HamurState* mCurrentState; /** Current state of the game. */
		HamurState* mPreviousState; /**< Previous state of the game. */
};

} // namespace hamur

#endif // HAMURSTATEMR_H
