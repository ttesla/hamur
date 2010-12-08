#ifndef SELECTION_H_
#define SELECTION_H_

#include "Food.h"
using namespace std;

class Selection
{
	public:
		Selection();
		void AddFood(Food *food);
		void Run();

	private: 
		list<Food *> mFoodList;
};

#endif