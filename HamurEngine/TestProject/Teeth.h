#pragma once

#include "hamur.h"

using namespace hamur;
using namespace std;

class Teeth : public HamurObject
{
	public:
		Teeth(const string &name, const string &sprite, float mLife, float mShield);

		void Reset();

		void Update(float deltaTime);
		//void Draw(float deltaTime);

		inline const float &GetHealth(){return mLife;}
		inline const float &GetShield(){return mShield;}
		inline void SetHealth(const float &value){mLife = value;}
		inline void SetShield(const float &value){mShield = value; if(mShield > 1000) mShield = 1000;}
		inline void DecreaseShield(const float &value)
		{
			mShield -= value;
		}
		inline void IncreaseShield(const float &value)
		{
			mShield += value;

			if(mShield > 0)
				SetSprite("Graphics/teeth/teeth0.png");
		}
		inline void DecreaseHealth(const float &value)
		{
			mLife -= value;
			if(mLife <= 0)
				HAMURSTATEMR->ChangeState("GameOverState");
		}
		void HitDamage(const float &value);


	private:
		float mLife;
		float mShield;

		bool isMiddleTextureLoaded;
};