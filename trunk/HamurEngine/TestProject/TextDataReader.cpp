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

TextDataReader::~TextDataReader()
{

}