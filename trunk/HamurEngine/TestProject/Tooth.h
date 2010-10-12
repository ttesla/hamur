#ifndef TOOTH_H
#define TOOTH_H

#include "hamur.h"
#include <list>
using namespace hamur;

//Holds the life and shield points of tooth.
class Tooth : public HamurObject
{
    public:
		static std::list<Tooth *> GetTeeth() {return *teeth;}
		static void SetTeeth(std::list<Tooth *> *toothList) {teeth = toothList;}

        Tooth(const string& name);
        virtual void Draw(float deltaTime);
		virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...

		void SetLife(float pLife){mLife = pLife;}
		void SetShield(float pShield){mShield = pShield;}
		float GetLife(){return mLife;}
		float GetShield(){return mShield;}

		void SetPosition(float x, float y);

	private:
		static std::list<Tooth *> *teeth;

		float mLife;
		float mShield;
};

#endif

