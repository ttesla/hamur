#include "Food.h"

Food::Food(const string &name) : HamurObject(name)
{
}

void Food::AddWave(Wave* wave)
{
	mWave = wave;
}

Wave* Food::GetWave()
{
	return (mWave);
}

void Food::Update(float deltaTime)
{
	mWave->Update(deltaTime);
}

void Food::Draw(float deltaTime)
{
	
}