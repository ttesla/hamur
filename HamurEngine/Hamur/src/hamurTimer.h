#ifndef HAMURTIMER_H
#define HAMURTIMER_H

#include "SDL.h"
#include "hamurSingleton.h"


namespace hamur
{

/**
* Hamur Timer.
* Singleton class which manages time, delta time...ect
*/
class HamurTimer : public Singleton<HamurTimer>
{
	public:

        friend class Singleton<HamurTimer>;

        /**
        * Initialize Hamur Timer
        * @return True if initialization is successful, else return False
        */
        bool Init();

        /**
        * Get current time (total time elapsed since program has started) in seconds. 
        * ex: 0.300 which means 300 milliseconds
        * @return Current time in seconds
        */
        float GetTimeInSeconds();

        /**
        * Get current time (total time elapsed since program has started) in milliseconds.
        * ex: 250 which means 250 milliseconds
        * @return Current time in milliseconds
        */
        int GetTimeInMilliseconds();

        /**
        * Get delta time, the time difference between two Hamur Engine frames. 
        * @return Delta time
        */
        float DeltaTime();

        /**
        * Set delta time, only Hamur Engine should call this.
        */
        void SetDeltaTime(float deltaTime); 

        
	protected:

        HamurTimer();
        ~HamurTimer();

	private:

		float mDeltaTime;
};


// Inline Function Definitions //

inline float HamurTimer::GetTimeInSeconds()
{
    return (float)SDL_GetTicks() / 1000; 
}

inline int HamurTimer::GetTimeInMilliseconds()
{
    return SDL_GetTicks();
}

inline float HamurTimer::DeltaTime()
{
    return mDeltaTime;
}

inline void HamurTimer::SetDeltaTime(float deltaTime)
{
    mDeltaTime = deltaTime;
}


} // namespace hamur

#endif // HAMURTIMER_H
