#ifndef BASE_H
#define BASE_H

#include "hamur.h"

#include <vector>

using namespace hamur;

class IngameState;
class Bacteria;
class WaterBullet;
class Bullet;
enum BulletTypes;

//Tower which is in the middle of tooth. Controled by player and can fire
class Base : public HamurObject
{
    public:
        Base(const string& name);
        virtual void Draw(float deltaTime);
		virtual void Update(float deltaTime);
		
		void Fire(const hamur::HamurVec3 &targetPos);
		void UseWater();
		
		inline void SetSelectedWeapon(const BulletTypes &typeName) {mSelectedWeaponType = typeName;}
		inline BulletTypes GetSelectedWeapon() {return mSelectedWeaponType;}
		//void setPhysics(); We are not using physics at the moment...

		std::vector<Bacteria *> *GetEnemiesList(){return &enemies;}

	private:
		std::vector<Bacteria *> enemies;
		std::vector<Bullet *> mBullets;
		WaterBullet *mWater;
		BulletTypes mSelectedWeaponType;
		int killedEnemyCount;
		bool update;
};

#endif

