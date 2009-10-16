#ifndef HAMURFONT_H
#define HAMURFONT_H

#include "hamurTexMR.h"
#include "hamurGL.h"
#include "hamurLog.h"
#include "hamurDefinitions.h"
#include "string"
#include "hamurSingleton.h"


namespace hamur
{
	class HamurFont : public Singleton<HamurFont>
	{
		public:
			
			// Return singleton object
			//static HamurFont* getInstance();

			HamurFont();
			~HamurFont();

			// Draw string to screen with bitmap fonts
			void draw_text(const string &text, float x, float y, float z);


		protected:

		private:

	};
}

#endif
