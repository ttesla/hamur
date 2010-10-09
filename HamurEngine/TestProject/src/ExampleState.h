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
        void Enter();
        void Update(float deltaTime);      
        void Draw(float deltaTime);
        void Exit();
        
	protected:

        
    private:

        float mAngle;
        HamurVec2 mPosition;

       
};

#endif //EXAMPLESTATE_H