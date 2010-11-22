#include "Bullet.h"

//ToothPaste type bullet, yellow ones
class ToothPasteBullet : public Bullet
{
public:
	ToothPasteBullet(const string &name, const hamur::HamurVec3 &startingPos, 
		const hamur::HamurVec3 &targetPos, const float &speed) : Bullet(name, startingPos, targetPos, speed), startingPosition(startingPos)
	{
		mBulletType = BulletTypes::ToothPasteBulletType;

		mWidth = 3;
		mHeight = 3;
		// This needs to be checked with Victor GDD
	}

	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Explode();

	void ResetBullet();

protected:
private:
	hamur::HamurVec3 startingPosition;
};