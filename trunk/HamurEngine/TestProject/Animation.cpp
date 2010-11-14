#include "Animation.h"

using namespace hamur;

Animation::Animation( const string &name, const int &frameCount ) : mAnimationName(name), 
mFrameCount(frameCount), mIsFinished(false), mIsAnimationPlaying(false), mIsPaused(false)
{
	for(int i = 0; i < frameCount; i++)
	{
		HamurString textureID;
		textureID << i;
		int id = HamurTextureManager::GetInstance()->AddTexture(name + "_" + textureID.GetString() + ".png");
		mTextureIDs.push_back(id);
	}
}

void Animation::Update( float deltaTime )
{
	if(mIsAnimationPlaying && !mIsPaused)
	{
		mActiveFrame += deltaTime;

		if(mActiveFrame >= mFrameCount)
		{
			if(mIsLooped)
				mActiveFrame = 0;
			else
			{
				mIsAnimationPlaying = false;
				mIsFinished = true;
			}
		}
	}
}

void Animation::PlayAnimation( const bool &isLooped )
{
	mIsLooped = isLooped;
	mIsAnimationPlaying = true;
	mActiveFrame = 0;
	mIsFinished = false;
}

void Animation::Draw(const HamurVec3 &position, const float &rotation)
{
	HamurTextureManager::GetInstance()->BlitTexture((int)mTextureIDs[mActiveFrame] , position, rotation );
}