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

		protected:
		
        private:

			string stateName;
	};

}

#endif // HAMUR_STATE_H