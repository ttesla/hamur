#include "Level.h"
using namespace std;

Level::Level(const string& name, int number)
{
	// We generate the waves for each level
	switch (number)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
			//...
		default:
			exit(-1);
	}
	mName = name;
	mNumber = number;	
}

void Level::Start()
{
	// TODO
}