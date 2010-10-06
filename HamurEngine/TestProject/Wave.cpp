#include "Wave.h"
using namespace std;
 
Wave::Wave(const string& name, int level)
{
	mName = name;
	
	if (level < MAXLEVEL && level > 0)
		mLevel = level;
	else
		exit(-1);
}

void Wave::Start()
{
	//TODO...
}