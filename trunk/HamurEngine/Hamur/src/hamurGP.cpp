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


	// Return HamurGP singleton object
	/*
	HamurGP* HamurGP::getInstance()
	{
		static HamurGP instance;
		return &instance;
	}
	*/


	// Checks rectangular collision of 2 textures with their texture data
	bool HamurGP::check_collision_2D(HamurTex* firstTex, HamurTex* secondTex)
	{
		// Calculate the sides of first texture
		float leftA   = firstTex->get_corX();
		float rightA  = firstTex->get_corX() + firstTex->get_scaledWidth();
		float topA    = firstTex->get_corY();
		float bottomA = firstTex->get_corY() + firstTex->get_scaledHeight();

		// Calculate the sides of second texture
		float leftB   = secondTex->get_corX();
		float rightB  = secondTex->get_corX() + secondTex->get_scaledWidth();
		float topB    = secondTex->get_corY();
		float bottomB = secondTex->get_corY() + secondTex->get_scaledHeight();

		// If any of the sides from First texture are outside of Second texture
		if(bottomA <= topB) { return false; }
		if(topA >= bottomB) { return false; }
		if(rightA <= leftB) { return false; }
		if(leftA >= rightB) { return false; }

		return true;
	}


	// Checks rectangular collision of 2 textures with their names
	bool HamurGP::check_collision_2D(const string &firstTexName, const string &secondTexName)
	{
		return check_collision_2D(HAMURTEXMR->getTexture(firstTexName), HAMURTEXMR->getTexture(secondTexName));
	}
}
