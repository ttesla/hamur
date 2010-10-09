#include "Bullet.h"

//Flossing type bullet
class FlossingBullet : public Bullet
{
public:
	FlossingBullet(const string &name, const hamur::HamurVec3 &startingPos, const hamur::HamurVec3 &targetPos, const float &speed) :
	  Bullet(name, startingPos, targetPos, speed){}

	void Update(float deltaTime);
	void Draw(float deltaTime);
	void Explode();
protected:
private:
};