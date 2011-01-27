#ifndef HAMUR_ANIMATION_H
#define HAMUR_ANIMATION_H

#include <string>

using std::string;


namespace hamur
{

/**
* Hamur Animation.
* Handles animations which are used in HamurObject
*/
class HamurAnimation
{
	public:
        /**
        * HamurAnimation constructor
        * @param name Name of the animation. ex: Walking, Shooting...
        * @param maxFrame Maximum frame count of the animation.
        * @param delay Delay of the animation which determines the speed in seconds. 
        * @param loop If true animation will loop else it will end when max frame count reached.
        */
        HamurAnimation(const string& name, int maxFrame, float delay, bool loop);
        ~HamurAnimation();

        /**
        * Updates animation, this must be called by the object update or your update
        */
        void Update();

        /**
        * Starts animation. Every call to this function will restart the animation.
        * To make a one time call make a control with IsPlaying()
        * @see IsPlaying()
        */
        void Play();

        /**
        * Stops animation and resets its state.
        */
        void Stop();

        /**
        * Returns if animation is playing or not
        * @return True if animation is playing else False
        */
        bool IsPlaying() const;

        /**
        * Get current animation frame
        * @return Current animation frame
        */
        int GetFrame() const;

        /**
        * Get animation name
        * @return Animation name
        */
        string& GetName();

        /**
        * Sets animation delay, this one may be used to change animation speed
        * @param delay Delay amount in seconds. ex: 1.2f will delay 1.2 seconds or 1200 miliseconds. 
        */
        void SetDelay(float delay);

	private:
        HamurAnimation(const HamurAnimation&);             /**< Disable copy constructor, no definition provided */
        HamurAnimation& operator =(const HamurAnimation&); /**< Disable assignment, no definition provided */

        string mName;
        int mMaxFrame;
        float mDelay;
        bool mLoop;
        bool mIsPlaying;
        int mCurrentFrame;
        float mDelayTimer;

};


// Inline functions...

// GETTERS & SETTERS
inline bool HamurAnimation::IsPlaying() const     { return mIsPlaying; }
inline int HamurAnimation::GetFrame() const       { return mCurrentFrame; }
inline string& HamurAnimation::GetName()          { return mName; }
inline void HamurAnimation::SetDelay(float delay) { mDelay = delay; }

} // namespace hamur

#endif // HAMUR_ANIMATION_H
