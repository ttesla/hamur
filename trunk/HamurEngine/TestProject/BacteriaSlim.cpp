#include "BacteriaSlim.h"
#include <cstdlib> 
#include <ctime> 
#include "TextDataReader.h"
using namespace std;
 
BacteriaSlim::BacteriaSlim(const string &name, const string &sprite, const int &spriteCount, HamurVec3 basePosition, const float &speed):Bacteria(name, sprite, spriteCount, basePosition, speed)
{
	// We set Life and Shield for Norms
	this->SetLife(TextDataReader::GetInstance()->GetSlimLife()); // Example values at the moment
	this->SetDamage(TextDataReader::GetInstance()->GetSlimDamage());
	this->SetShield(3.0); 
	this->mWidth = 10.0;
}

void BacteriaSlim::DoHit()
{
	this->SetAnimation("Graphics/slim_hit", 1);
	this->mHitTimer = 1.49;
}

void BacteriaSlim::UndoHit()
{
	this->SetAnimation("Graphics/slim", 1);
	this->mHitTimer = 1.5;
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