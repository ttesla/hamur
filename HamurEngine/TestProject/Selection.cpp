#include "Selection.h"

Selection::Selection()
{
	mFoodList.clear();
}

void Selection::AddFood(Food *food)
{
	mFoodList.push_back(food);
}

void Selection::Run()
{
	// Edu: We must control the end of a Wave to start the next one
	//for (int i=0; i < mFoodList.size(); i++)
	{
		list<Food *>::iterator Iter = mFoodList.begin();
		(*Iter)->GetWave()->StartWave();
	}
}