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

		static inline const float &GetHealth(){return mLife;}
		static inline const float &GetShield(){return mShield;}
		static inline void SetHealth(const float &value){mLife = value;}
		static inline void SetShield(const float &value){mShield = value;}
		static inline void DecreaseHealth(const float &value){Teeth::mLife -= value;}
		static inline void DecreaseShield(const float &value){Teeth::mShield -= value;}
		static inline void IncreaseShield(const float &value){Teeth::mShield += value;}

	private:
		static float mLife;
		static float mShield;
};