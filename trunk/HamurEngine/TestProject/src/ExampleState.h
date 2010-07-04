#ifndef EXAMPLESTATE_H
#define EXAMPLESTATE_H

#include "hamur.h"

using namespace hamur;

/**
* This is the example state of the game.
* For testing and an example framework for your game.
*/
class ExampleState : public HamurState
{
	public:
        
        ExampleState();
        ~ExampleState();

        // Virtual function implementations comes from HamurState
        void enter();
        void update();      
        void draw();
        void exit();
        
	protected:

        
    private:

       
};

#endif //EXAMPLESTATE_H