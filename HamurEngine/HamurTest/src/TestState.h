#ifndef TESTSTATE_H
#define TESTSTATE_H

#include "hamur.h"

using namespace hamur;

/**
* This is the example state of the game.
* For testing and an example framework for your game.
*/
class TestState : public HamurState
{
	public:
        
        TestState();
        ~TestState();

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

#endif //TESTSTATE_H