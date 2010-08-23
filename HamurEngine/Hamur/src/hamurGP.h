#ifndef HAMURGP_H
#define HAMURGP_H

#include "hamurSingleton.h"


namespace hamur
{

// Forward declarations
class HamurTex;

class HamurGP : public Singleton<HamurGP>
{
	public:

        friend class Singleton<HamurGP>;

        /**
        * Initialize Hamur Gameplay
        */
        bool Init();

        /**
        * Checks rectangular collision of 2 textures with their texture data.
        * @param firstTex HamurTexture pointer of first texture.
        * @param secondTex HamurTexture pointer of second texture.
        * @return If two textures collide or not
        */
		bool CheckCollision2D(HamurTex* firstTex, HamurTex* secondTex);

	protected:

        HamurGP();
        ~HamurGP();
};

} // namespace hamur

#endif // HAMURGP_H
