#ifndef BACTERIASTRAYER_H
#define BACTERIASTRAYER_H

#include "Bacteria.h"

using namespace std;
using namespace hamur;

#define SPEEDCOEF 0.3;//0.3

class BacteriaStrayer : public Bacteria
{
    public:
		BacteriaStrayer(const string& name, const string& sprite, const int &spriteCount, HamurVec3 basePos, const float &speed);
		virtual void Update(float deltaTime);
		//virtual void Draw(float deltaTime);	
		//void setPhysics(); We are not using physics at the moment...
		virtual string GetType() { return "strayer"; }
		virtual int GetInitialLife() { return 2; }
		void DoHit();
		void UndoHit();

	private:
		int mPrevTickCount;
		int mMovementRange;
		int mSideMovFactor;
};

#endif

