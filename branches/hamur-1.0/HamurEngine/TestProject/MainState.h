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
        void Enter();
        void Update(float deltaTime);      
        void Draw(float deltaTime);
        void Exit();
        
	protected:

        
    private:
        void testBox2D();
        void testPlotter();
		void spawnObjects();

        float angle1;
       
};

#endif //MAINSTATE_H
