#include "Bullet.h"

//ToothPaste type bullet, yellow ones
class ToothPasteBullet : public Bullet
{
public:
	ToothPasteBullet(const string &name, const hamur::HamurVec3 &startingPos, 
		const hamur::HamurVec3 targetPos, const float &speed) : Bullet(name, startingPos, targetPos, speed)
	{
		mWidth = 3;
		mHeight = 3;
		// This needs to be checked with Victor GDD
		mPower = 3;
	}

	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Explode();

protected:
private:
};