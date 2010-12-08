#include "FeedbackInfo.h"

FeedbackInfo* FeedbackInfo::Instance = NULL;

FeedbackInfo* FeedbackInfo::GetInstance()
{
	if (Instance == NULL)
		Instance = new FeedbackInfo();

	return Instance;
}

FeedbackInfo::FeedbackInfo()
{
	for (int i = 0; i < 3; i++)
	{
		healths[i] = 0.0;
		shields[i] = 0.0;
	}
}

FeedbackInfo::~FeedbackInfo()
{

}

void FeedbackInfo::SetSelection(map<string, string> sel)
{
	foodSelection = sel;
}

void FeedbackInfo::SetHealth(int index, float value)
{
	healths[index] = value;
}

void FeedbackInfo::SetShield(int index, float value)
{
	shields[index] = value;
}

void FeedbackInfo::SetToothBrushUses(int tbu)
{
	toothBrushUses = tbu;
}

void FeedbackInfo::SetSnacks(int g, int nsg, int b)
{
	goodSnacks = g;
	nsgSnacks = nsg;
	badSnacks = b;
}