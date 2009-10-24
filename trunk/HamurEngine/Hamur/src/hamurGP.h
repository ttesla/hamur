#ifndef HAMURGP_H
#define HAMURGP_H

#include "hamurTexMR.h"
#include "hamurTex.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"
#include "hamurSingleton.h"

// Predefined fast functions
#define ABS(x) ((x)>0 ? (x) : (-x))
//#define DEPTH_TEST 1.5f


// INTERFACE OF hamurGP
namespace hamur
{
	class HamurGP : public Singleton<HamurGP>
	{
		public:

			// Return HamurGP singleton object
			//static HamurGP* getInstance(); 

			HamurGP();
			~HamurGP();

			// Checks rectangular collision of 2 textures with their texture data
			bool check_collision_2D(HamurTex* firstTex, HamurTex* secondTex);

			// Checks rectangular collision of 2 textures with their names
			bool check_collision_2D(const string &firstTexName, const string &secondTexName);

		protected:

	};
}
#endif