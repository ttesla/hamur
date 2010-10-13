#ifndef FOOD_H
#define FOOD_H

#include "Wave.h"
#include "hamur.h"
using namespace hamur;

class Food : HamurObject
{
    public:
		Food (const string& name);	
        void AddWave(Wave* v);
		Wave* GetWave();
		virtual void Update(float deltaTime);
		virtual void Draw(float deltaTime);
		
	private:
		Wave* mWave;
};


#endif