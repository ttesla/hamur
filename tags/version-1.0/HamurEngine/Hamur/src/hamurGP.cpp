#include "hamurGP.h"
#include "hamurTextureManager.h"
#include "hamurTexture.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"


namespace hamur
{

HamurGP::HamurGP()
{
	
}


HamurGP::~HamurGP()
{

}


// Init function
bool HamurGP::Init()
{
    HAMURLOG->WriteInitLog("HamurGP");
    return true;
}


// Checks rectangular collision of 2 textures with their texture data
bool HamurGP::CheckCollision2D(HamurTexture* firstTex, HamurTexture* secondTex)
{
	// Calculate the sides of first texture
	float leftA   = firstTex->GetX();
	float rightA  = firstTex->GetX() + firstTex->GetOpenglWidth();
	float topA    = firstTex->GetY();
	float bottomA = firstTex->GetY() + firstTex->GetOpenglHeight();

	// Calculate the sides of second texture
	float leftB   = secondTex->GetX();
	float rightB  = secondTex->GetX() + secondTex->GetOpenglWidth();
	float topB    = secondTex->GetY();
	float bottomB = secondTex->GetY() + secondTex->GetOpenglHeight();

	// If any of the sides from First texture are outside of Second texture
	if(bottomA <= topB) { return false; }
	if(topA >= bottomB) { return false; }
	if(rightA <= leftB) { return false; }
	if(leftA >= rightB) { return false; }

	return true;
}

} // namespace hamur
