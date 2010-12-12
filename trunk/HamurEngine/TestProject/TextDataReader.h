#pragma once

#include "hamur.h"
#include "tinyxml.h"
#include "Text.h"
#include <list>

using namespace std;

class TextDataReader
{
	public:
		static TextDataReader* GetInstance();
		//TextDataReader(char *fileName);
		~TextDataReader();
		// There should be other parameters to select what feedback to choose
		string GetFeedback(string nameValue);
		string GetHowToPlay();
		
		list<string> GetGoodFood();
		list<string> GetNSGFood();
		list<string> GetBadFood();
		
		int GetStrayerLife();
		int GetStrayerDamage();
		int GetShooterLife();
		int GetShooterDamage();
		int GetSlimLife();
		int GetSlimDamage();
		int GetFattieLife();
		int GetFattieDamage();
		int GetNormLife();
		int GetNormDamage();

		// Other functions for other kinds of texts
		//string GetStory(...)
		string* FormatText(string text, int lines);

	private:
		static TextDataReader* Instance;
		TextDataReader(char *fileName);
		TiXmlDocument doc;
};