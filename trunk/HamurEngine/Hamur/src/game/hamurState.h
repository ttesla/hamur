#ifndef HAMUR_STATE_H
#define HAMUR_STATE_H

#include <string>

using std::string;

namespace hamur
{
    /**
     * Hamur State base class.
     * Every game state is represented by Hamur State, ex: MenuState, GameState...ect.
     */
	class HamurState
	{
		public:

            ~HamurState();

            /**
            * HamurState constructor.
            * @param _stateName Name of the state.
            */
            HamurState(const string &_stateName);

            /**
            * Pure virtual enter function of the state.
            * Initialization logic about the state should be written here.
            * It is called once when the state manager switches to this state.
            * @see HamurStateMR
            */
            virtual void enter() = 0;

            /**
            * Pure virtual update function of the state. 
            * All update logic should be written here, 
            * and its called by the State Manager. 
            * @see HamurStateManager
            */
            virtual void update() = 0;

            /**
            * Pure virtual draw function of the state. 
            * All drawings should be written here.
            * and its called by the State Manager
            * @see HamurStateManager
            */
            virtual void draw() = 0;

            /**
            * Pure virtual exit function of the state. 
            * Finalization logic about the state should be written here.
            * It is called once when the state manager switches to another state.
            * @see HamurStateMR
            */
            virtual void exit() = 0;

            /** return State name */
            string getStateName();

		protected:
		
        private:
			string stateName; /** Name of this state */
	};

}

#endif // HAMUR_STATE_H