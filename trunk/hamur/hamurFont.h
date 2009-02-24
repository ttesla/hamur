#ifndef HAMURFONT_H
#define HAMURFONT_H

#include "hamurTexMR.h"
#include "hamurGL.h"
#include "hamurLog.h"
#include "hamurDefinition.h"
#include "string"


namespace hamur
{
	class HamurFont
	{
		public:
			
			// Return singleton object
			static HamurFont* getInstance(); 

			// Draw string to screen with bitmap fonts
			void draw_text(const string &text, float x, float y, float z);


		protected:

			// Constructor - Destructor
			HamurFont();
			~HamurFont();

		private:

	};
}

#endif
