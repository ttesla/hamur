#ifndef HAMURFONT_H
#define HAMURFONT_H

#include "hamurTexMR.h"
#include "hamurGL.h"
#include "helper/hamurLog.h"
#include "hamurDefinitions.h"
#include "hamurSingleton.h"

namespace hamur
{
    /**
    * Hamur Font Manager.
    * Singleton class that manages the font system.
    */ 
	class HamurFont : public Singleton<HamurFont>
	{
		public:
            /**
            * Hamur Font Constructor.
            * Loads surfaces and add textures to texture manager.
            * @see HamurTexMR::addTexture()
            */ 
			HamurFont();
			~HamurFont();

            /**
            * Draw string to screen with bitmap fonts.
            * @param text Given text that written to the screen.
            * @param x Given x coordinate of the text that will be drawn.
            * @param y Given y coordinate of the text that will be drawn.
            * @param z Given z coordinate of the text that will be drawn.
            */
			void drawText(const string &text, float x, float y, float z);

		protected:

		private:
	};
}

#endif // HAMURFONT_H
