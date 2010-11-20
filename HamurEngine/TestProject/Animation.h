#pragma once

#include "hamur.h"
#include <vector>


class Animation
{
public:
	Animation(const string &name, const int &frameCount);
	~Animation(){};

	void Update(float deltaTime);
	void Draw(const hamur::HamurVec3 &position, const float &rotation);

	void PlayAnimation(const bool &isLooped);
	
	inline void PauseAnimation() {mIsPaused = true;}
	inline void ResumeAnimation() {mIsPaused = false;}
	inline void StopAnimation() 
	{
		mIsAnimationPlaying = false;
		mActiveFrame = 0;
	}


	inline bool IsFinished() {return mIsFinished;}
	inline bool IsPlaying() {return mIsAnimationPlaying;}
	inline int GetFrameCount() {return mFrameCount;}
protected:
private:
	std::vector<int> mTextureIDs;
	string mAnimationName;
	int mFrameCount;
	float mActiveFrame;
	bool mIsLooped;
	bool mIsPaused;
	bool mIsFinished;
	bool mIsAnimationPlaying;
};