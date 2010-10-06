#ifndef BACTERIASLIM_H
#define BACTERIASLIM_H

#include "Bacteria.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.5;

class BacteriaSlim : public Bacteria
{
    public:
		BacteriaSlim(const string& name, hamur::HamurVec3 basePos);
        virtual void Draw(float deltaTime);	
		virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...

	private:
};

#endif

