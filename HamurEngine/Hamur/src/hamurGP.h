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

namespace hamur
{
	class HamurGP : public Singleton<HamurGP>
	{
		public:

            friend Singleton<HamurGP>;

            /**
            * Checks rectangular collision of 2 textures with their texture data.
            * @param firstTex HamurTexture pointer of first texture.
            * @param secondTex HamurTexture pointer of second texture.
            * @return If two textures collide or not
            */
			bool checkCollision2D(HamurTex* firstTex, HamurTex* secondTex);

            /**
            * Checks rectangular collision of 2 textures with their names
            * @param firstTexName Name of the first texture.
            * @param secondTexName Name of the second texture.
            * @return If two textures collide or not
            */
			bool checkCollision2D(const string &firstTexName, const string &secondTexName);

		protected:

            HamurGP();
            ~HamurGP();
	};
}

#endif // HAMURGP_H
