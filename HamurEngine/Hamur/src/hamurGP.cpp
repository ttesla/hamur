#include "hamurGP.h"

namespace hamur
{
	HamurGP::HamurGP()
	{
		HAMURLOG->write_init_log("HamurGP");
	}


	HamurGP::~HamurGP()
	{

	}


	// Checks rectangular collision of 2 textures with their texture data
	bool HamurGP::checkCollision2D(HamurTex* firstTex, HamurTex* secondTex)
	{
		// Calculate the sides of first texture
		float leftA   = firstTex->getCorX();
		float rightA  = firstTex->getCorX() + firstTex->getScaledWidth();
		float topA    = firstTex->getCorY();
		float bottomA = firstTex->getCorY() + firstTex->getScaledHeight();

		// Calculate the sides of second texture
		float leftB   = secondTex->getCorX();
		float rightB  = secondTex->getCorX() + secondTex->getScaledWidth();
		float topB    = secondTex->getCorY();
		float bottomB = secondTex->getCorY() + secondTex->getScaledHeight();

		// If any of the sides from First texture are outside of Second texture
		if(bottomA <= topB) { return false; }
		if(topA >= bottomB) { return false; }
		if(rightA <= leftB) { return false; }
		if(leftA >= rightB) { return false; }

		return true;
	}


	// Checks rectangular collision of 2 textures with their names
	bool HamurGP::checkCollision2D(const string &firstTexName, const string &secondTexName)
	{
		return checkCollision2D(HAMURTEXMR->getTexture(firstTexName), HAMURTEXMR->getTexture(secondTexName));
	}
}
