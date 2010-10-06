#ifndef BASE_H
#define BASE_H

#include "hamur.h"
#include <vector>

using namespace hamur;

class IngameState;
class Bacteria;

//Tower which is in the middle of tooth. Controled by player and can fire
class Base : public HamurObject
{
    public:
        Base(const string& name, IngameState *state);
        virtual void Draw(float deltaTime);
		virtual void Update(float deltaTime);
		//void setPhysics(); We are not using physics at the moment...

		std::vector<Bacteria *> *GetEnemiesList(){return &enemies;}

private:
	IngameState *state;
	std::vector<Bacteria *> enemies;
	int killedEnemyCount;
	bool update;
};

#endif

