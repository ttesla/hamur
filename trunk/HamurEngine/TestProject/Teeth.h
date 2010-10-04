#pragma once

#include "hamur.h"

class Teeth : hamur::HamurObject
{
public:
	Teeth(const string &name);

	void Reset();

	void Update(float deltaTime);
	void Draw(float deltaTime);

	inline const float &GetHealth(){return health;}
	inline const float &GetShield(){return shield;}
	inline void SetHealth(const float &value){health = value;}
	inline void SetShield(const float &value){shield = value;}
	inline void DecreaseHealth(const float &value){health -= value;}
	inline void DecreaseShield(const float &value){shield -= value;}
	inline void IncreaseShield(const float &value){shield += value;}

private:
	float health;
	float shield;
};