#ifndef LEVEL_H
#define LEVEL_H
#include "Wave.h"
#include "hamur.h"
using namespace hamur;

#define MAXWAVES 6
#define MAXLEVEL 5

class Level
{
    public:
        Level(const string& name, int number);
		void Start();

	private:
		string mName;
		int mNumber;
		Wave* waves;
};

#endif

