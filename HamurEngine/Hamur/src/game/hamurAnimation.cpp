#include "hamurAnimation.h"
#include "../hamurTimer.h"


namespace hamur
{

// HamurAnimation constructor
HamurAnimation::HamurAnimation(const string& name, int maxFrame, float delay, bool loop)
    : mName(name), mMaxFrame(maxFrame), mDelay(delay), mLoop(loop), mIsPlaying(false),
      mCurrentFrame(0), mDelayTimer(0.0f)
{

}


// Destructor
HamurAnimation::~HamurAnimation()
{

}


// Update
void HamurAnimation::Update()
{
    if(mIsPlaying)
    {
        mDelayTimer -= HamurTimer::GetInstance()->DeltaTime();

        // If sufficient time passed then move to next frame
        if(mDelayTimer < 0)
        {
            mCurrentFrame++;
            
            if(mLoop)
            {
                mCurrentFrame = mCurrentFrame % mMaxFrame;
            }
            else if(mCurrentFrame >= mMaxFrame)
            {
                mCurrentFrame = mMaxFrame - 1; // Set to last frame
                mIsPlaying = false; // Animation finished
            }
            
            mDelayTimer = mDelay;
        }
    }
}


// Play
void HamurAnimation::Play()
{
    mCurrentFrame = 0;
    mDelayTimer = mDelay;
    mIsPlaying = true;
}


// Stop
void HamurAnimation::Stop()
{
    mCurrentFrame = 0;
    mIsPlaying = false;
}

} // namespace hamur
