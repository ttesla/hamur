#ifndef BACTERIASTRAYER_H
#define BACTERIASTRAYER_H

#include "Bacteria.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.3;//0.3

class BacteriaStrayer : public Bacteria
{
    public:
		BacteriaStrayer(const string& name, hamur::HamurVec3 basePos, const float &speed);
        virtual void Draw(float deltaTime);	
		virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...
	private:
};

#endif
