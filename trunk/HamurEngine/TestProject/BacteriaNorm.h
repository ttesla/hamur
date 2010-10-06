#ifndef BACTERIANORM_H
#define BACTERIANORM_H

#include "Bacteria.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.3;

class BacteriaNorm : public Bacteria
{
    public:
		BacteriaNorm(const string& name, hamur::HamurVec3 basePos);
        virtual void Draw();	
		virtual void Update();
		//void setPhysics(); We are not using physics at the moment...

	private:
		
};

#endif

