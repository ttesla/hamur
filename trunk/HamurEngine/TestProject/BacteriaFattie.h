#ifndef BACTERIAFATTIE_H
#define BACTERIAFATTIE_H

#include "Bacteria.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.2;

class BacteriaFattie : public Bacteria
{
    public:
		BacteriaFattie(const string& name, const string& sprite, HamurVec3 basePos, const float &speed);
        //virtual void Draw(float deltaTime);	
		//virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...

	private:

};

#endif

