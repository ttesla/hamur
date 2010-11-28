#ifndef FEEDBACKINFO_H
#define FEEDBACKINFO_H
#include "hamur.h"
#include <map>
using namespace hamur;
using namespace std;

class FeedbackInfo
{
    public:
		static FeedbackInfo* GetInstance();
		~FeedbackInfo();

		map<string, string> GetFoodSelection() {return foodSelection;}
		float GetHealth(int index){return healths[index];}
		float GetShield(int index){return shields[index];}
		int GetToothBrushUses(){return toothBrushUses;}

		void SetSelection(map<string, string> sel);
		void SetHealth(int index, float value);
		void SetShield(int index, float value);
		void SetToothBrushUses(int tbu);

	private:
		static FeedbackInfo* Instance;
		FeedbackInfo();

		map<string, string> foodSelection;
		float healths[3]; // Stores the health after each level (3 levels)
		float shields[3];
		int toothBrushUses;
};

#endif

