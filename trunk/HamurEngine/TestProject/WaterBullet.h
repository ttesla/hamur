#include "Bullet.h"

class Animation;

//Glass of water type bullet:D
class WaterBullet : public Bullet
{
public:
	WaterBullet(const string &name, const float &cooldown); 

	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Explode();

	inline bool IsUsable(){return mIsUsable;}
	inline float GetRemainingCooldownTime() {return mRemainingCooldown;}
protected:
private:
	Animation *mAnimation;
	float mCooldownTime;
	float mRemainingCooldown;
	bool mIsUsable;

};