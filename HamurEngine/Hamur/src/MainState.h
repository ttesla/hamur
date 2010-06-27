#ifndef MAINSTATE_H
#define MAINSTATE_H

#include "hamur.h"

using namespace hamur;

/**
* This is the main state of the game.
* For testing and an example framework for your game.
*/
class MainState : public HamurState
{
	public:
        
        MainState();
        ~MainState();

        // Virtual function implementations comes from HamurState
        void enter();
        void update();      
        void draw();
        void exit();
        
	protected:

        
    private:
        void testBox2D();
        void testPlotter();

        float angle1;
       
};

#endif //MAINSTATE_H
