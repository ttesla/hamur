#include "Bullet.h"

//Flossing type bullet
class FlossingBullet : public Bullet
{
public:
	FlossingBullet(const string &name, const hamur::HamurVec3 &startingPos, const hamur::HamurVec3 &targetPos, const float &speed) :
	  Bullet(name, startingPos, targetPos, speed), targetPosition(targetPos), startingPosition(startingPos)
	  {
			mBulletType = BulletTypes::FlossingBulletType;

			mWidth = 5;
			mHeight = 5;
	  }

	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Explode();
	void ResetBullet();

protected:
private:
	hamur::HamurVec3 targetPosition;
	hamur::HamurVec3 startingPosition;
};