#ifndef BASE_H
#define BASE_H

#include "hamur.h"

#include <list>

using namespace hamur;

class IngameState;
class Bacteria;
class WaterBullet;
class Bullet;
enum BulletTypes;
class Brush;

//Tower which is in the middle of tooth. Controled by player and can fire
class Base : public HamurObject
{
    public:
        //Base(const string& name);
		Base(const string &name, const string &sprite);
		~Base();
        //virtual void Draw(float deltaTime);
		virtual void Update(float deltaTime);
		
		void Fire(const hamur::HamurVec3 &targetPos, const BulletTypes &bulletType);
		void UseWater();
		void UseBrush();
		
		//void setPhysics(); We are not using physics at the moment...

		//std::vector<Bacteria *> *GetEnemiesList(){return &enemies;}

	private:
		//std::vector<Bacteria *> enemies;
		std::list<Bullet *> mBullets;
		WaterBullet *mWater;
		Brush *mBrush;
		int killedEnemyCount;
		bool update;
		float mFlossingBulletCooldown;
		float mLastFlossingBulletFiredTime;
		float mToothpasteBulletCooldown;
		float mLastToothpasteBulletFiredTime;
};

#endif

