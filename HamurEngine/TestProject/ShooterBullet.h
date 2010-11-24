#ifndef SHOOTERBULLET_H
#define SHOOTERBULLET_H

#include "Bullet.h"
#include "Tooth.h"
#include <list>
using namespace hamur;
using namespace std;

// Shooter bullet (for the ShooterBacteria)
class ShooterBullet : public Bullet
{
	public:
		ShooterBullet(const string &name, const string &sprite, const HamurVec3 &startingPos, const HamurVec3 targetPos, const float &speed);
		void Update(float deltaTime);
		//void Draw(float deltaTime);
		void Explode();

		void ResetBullet();

	protected:
	private:
		HamurVec3 startingPosition;
};

#endif

