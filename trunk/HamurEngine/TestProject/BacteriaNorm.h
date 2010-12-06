#ifndef BACTERIANORM_H
#define BACTERIANORM_H

#include "Bacteria.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.3;

class BacteriaNorm : public Bacteria
{
    public:
		BacteriaNorm(const string& name, const string& sprite, const int &spriteCount, HamurVec3 basePos, const float &speed);
        //virtual void Draw(float deltaTime);	
		//virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...
		virtual string GetType() { return "norm"; }
		virtual int GetInitialLife() { return 3; }
		void DoHit();
		void UndoHit();

	private:
		
};

#endif

