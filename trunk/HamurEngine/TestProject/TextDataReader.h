#pragma once

#include "hamur.h"
#include "tinyxml.h"
#include "Text.h"

class TextDataReader
{
	public:
		TextDataReader(char *fileName);
		~TextDataReader();
		// There should be other parameters to select what feedback to choose
		string GetFeedback(string nameValue);
		// Other functions for other kinds of texts
		//string GetStory(...)

	private:
		TiXmlDocument doc;
};