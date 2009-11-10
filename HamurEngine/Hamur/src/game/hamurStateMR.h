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
	class HamurStateMR : public Singleton<HamurStateMR>
	{
		public:
			HamurStateMR();
			~HamurStateMR();
			void registerState(const string &_stateName, HamurState *_state);
			bool removeState(const string &_stateName);
			bool hasState(const string &_stateName);
			HamurState* findState(const string &_stateName);

			void setCurrentState(HamurState &_state);
			HamurState* getCurrentState();

			void setCurrentState(const string &_stateName);
			string getCurrentStateName();

		protected:

		private:
			map<string, HamurState*> stateList; // Stores all states according to their names.
			HamurState* currentState; // Current state of the game.
	};
}
#endif // HAMURSTATEMR_H