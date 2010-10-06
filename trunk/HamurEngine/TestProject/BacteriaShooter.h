#ifndef BACTERIASHOOTER_H
#define BACTERIASHOOTER_H

#include "Bacteria.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.3;

class BacteriaShooter : public Bacteria
{
    public:
		BacteriaShooter(const string& name, hamur::HamurVec3 basePos);
        virtual void Draw();	
		virtual void Update();
		//void setPhysics(); We are not using physics at the moment...

	private:
};

#endif

