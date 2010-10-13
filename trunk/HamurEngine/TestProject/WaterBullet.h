#include "Bullet.h"

//Glass of water type bullet:D
class WaterBullet : public Bullet
{
public:
	WaterBullet(const string &name, const float &cooldown) : 
	  Bullet(name, hamur::HamurVec3(0, 0, 0), hamur::HamurVec3(0, 0, 0), 0), mCooldownTime(cooldown){}

	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Explode();

	inline bool IsUsable(){return mIsUsable;}
protected:
private:
	float mCooldownTime;
	float mRemainingCooldown;
	bool mIsUsable;

};