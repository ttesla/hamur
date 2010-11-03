#include "BacteriaSlim.h"
#include <cstdlib> 
#include <ctime> 
using namespace std;
 
BacteriaSlim::BacteriaSlim(const string &name, const string &sprite, HamurVec3 basePosition, const float &speed):Bacteria(name, sprite, basePosition, speed)
{
	// We set Life and Shield for Norms
	this->SetLife(1.0); // Example values at the moment
	this->SetShield(3.0); 
	this->mWidth = 10.0;
}

/* Not using it at the moment...

void BacteriaSlim::Draw(float deltaTime)
{
	// Draw yellow circles
	HamurPlotter::DrawSolidCircle(mPos.x, mPos.y, mWidth, HamurColor::BLUE);
}

void BacteriaSlim::Update(float deltaTime)
{
	Bacteria::Update(deltaTime);

}

*/