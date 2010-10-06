#ifndef BACTERIAFATTIE_H
#define BACTERIAFATTIE_H

#include "Bacteria.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.2;

class BacteriaFattie : public Bacteria
{
    public:
		BacteriaFattie(const string& name, hamur::HamurVec3 basePos);
        virtual void Draw();	
		virtual void Update();
		//void setPhysics(); We are not using physics at the moment...

	private:

};

#endif

