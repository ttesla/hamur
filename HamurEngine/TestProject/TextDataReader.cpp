#include "TextDataReader.h"

using namespace hamur;

TextDataReader::TextDataReader( char *fileName )
{
	if(!doc.LoadFile(fileName))
	{
		HAMURLOG->WriteLog("Xml file could not be loaded");
		HAMURENGINE->Stop();
		return;
	}
}

string TextDataReader::GetFeedback(string nameValue)
{
	TiXmlNode *root = (TiXmlElement *)doc.RootElement();
	
	TiXmlElement *texts = 0;//(TiXmlElement *)root->FirstChild();
	while( texts = (TiXmlElement *)root->IterateChildren(texts) )
	{
		TiXmlElement *feedbacks = 0;//(TiXmlElement *)texts->FirstChild();
		while(feedbacks = (TiXmlElement *)texts->IterateChildren(feedbacks))
		{
			if (feedbacks->Attribute("name") == "nameValue")
			{
				//Whatever			
			}
		}
	}

	return "nice!";
}

string TextDataReader::GetHowToPlay()
{
	string text = "";
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* element = root->FirstChildElement( "HowToPlay" );
		if (element)
		{
			text = element->GetText();
		}
	}

	return text;
}

string* TextDataReader::FormatText(string text, int lines)
{
	bool end = false;
	string* textLines = new string[lines];
	int size = text.length()/lines;
	int ipos = 0;
	int fpos = size;
	char* chartext = (char*)text.c_str();

	for (int i = 0; i < lines && !end; i++)
	{	
		while (chartext[fpos] != ' ' && chartext[fpos] != '\0')
		{
			fpos++;
		}

		textLines[i] = text.substr(ipos, fpos-ipos);

		if (chartext[fpos] == '\0')
		{
			end = true;
		}

		ipos = fpos + 1;
		fpos += size;
	}

	return textLines;
}

TextDataReader::~TextDataReader()
{

}