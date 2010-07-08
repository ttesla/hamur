#include "hamurGP.h"

namespace hamur
{
	HamurGP::HamurGP()
	{
		HAMURLOG->writeInitLog("HamurGP");
	}


	HamurGP::~HamurGP()
	{

	}


	// Checks rectangular collision of 2 textures with their texture data
	bool HamurGP::checkCollision2D(HamurTex* firstTex, HamurTex* secondTex)
	{
		// Calculate the sides of first texture
		float leftA   = firstTex->GetCorX();
		float rightA  = firstTex->GetCorX() + firstTex->GetScaledWidth();
		float topA    = firstTex->GetCorY();
		float bottomA = firstTex->GetCorY() + firstTex->GetScaledHeight();

		// Calculate the sides of second texture
		float leftB   = secondTex->GetCorX();
		float rightB  = secondTex->GetCorX() + secondTex->GetScaledWidth();
		float topB    = secondTex->GetCorY();
		float bottomB = secondTex->GetCorY() + secondTex->GetScaledHeight();

		// If any of the sides from First texture are outside of Second texture
		if(bottomA <= topB) { return false; }
		if(topA >= bottomB) { return false; }
		if(rightA <= leftB) { return false; }
		if(leftA >= rightB) { return false; }

		return true;
	}
}
