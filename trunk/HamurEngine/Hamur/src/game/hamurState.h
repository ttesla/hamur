#ifndef HAMUR_STATE_H
#define HAMUR_STATE_H

#include <string>

using std::string;

namespace hamur
{

	class HamurState
	{
		public:
			HamurState();
			HamurState(const string &_stateName);
			~HamurState();

            virtual void draw() = 0;
            virtual void update() = 0;

			string getStateName();

			virtual void enter() = 0;
			virtual void exit() = 0;
			virtual void execute() = 0;

		protected:
		
        private:
			string stateName;
	};

}

#endif // HAMUR_STATE_H