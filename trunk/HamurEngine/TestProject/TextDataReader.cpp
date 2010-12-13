#include "TextDataReader.h"

using namespace hamur;

TextDataReader* TextDataReader::Instance = NULL;

TextDataReader* TextDataReader::GetInstance()
{
	if (Instance == NULL)
	{
		Instance = new TextDataReader("test.xml");
	}

	return Instance;
}

TextDataReader::TextDataReader( char *fileName )
{
	if(!doc.LoadFile(fileName, TIXML_ENCODING_UTF8))
	{
		HAMURLOG->WriteLog("Xml file could not be loaded");
		HAMURENGINE->Stop();
		return;
	}
}

string TextDataReader::GetFeedback(string nameValue)
{
	string text = "";
	bool done = false;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* fbs = root->FirstChildElement( "Feedbacks" );
		if (fbs)
		{
			TiXmlElement* fb = fbs->FirstChildElement("Feedback");
			while (fb && !done)
			{
				if (fb->Attribute("name") == nameValue)
				{
					text = fb->GetText();
					done = true;
				}

				fb = fb->NextSiblingElement();
			}
		}
	}

	return text;
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
			//element->
		}
	}

	return text;
}

list<string> TextDataReader::GetGoodFood()
{
	list<string> food;

	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* fd = root->FirstChildElement( "FoodDivisions" );
		if (fd)
		{
			TiXmlElement* goods = fd->FirstChildElement("Goods");
			if (goods)
			{
				TiXmlElement* good = goods->FirstChildElement("Good");

				while (good)
				{
					cout << "Good: " << good->GetText() << endl;
					food.push_back(good->GetText());
					good = good->NextSiblingElement();
				}
			}
		}
	}

	return food;
}

list<string> TextDataReader::GetNSGFood()
{
	list<string> food;

	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* fd = root->FirstChildElement( "FoodDivisions" );
		if (fd)
		{
			TiXmlElement* nsgs = fd->FirstChildElement("NotSoGoods");
			if (nsgs)
			{
				TiXmlElement* nsg = nsgs->FirstChildElement("NotSoGood");

				while (nsg)
				{
					cout << "NSG: " << nsg->GetText() << endl;
					food.push_back(nsg->GetText());
					nsg = nsg->NextSiblingElement();
				}
			}
		}
	}

	return food;
}

list<string> TextDataReader::GetBadFood()
{
	list<string> food;

	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* fd = root->FirstChildElement( "FoodDivisions" );
		if (fd)
		{
			TiXmlElement* bads = fd->FirstChildElement("Bads");
			if (bads)
			{
				TiXmlElement* bad = bads->FirstChildElement("Bad");

				while (bad)
				{
					cout << "Bad: " << bad->GetText() << endl;
					food.push_back(bad->GetText());
					bad = bad->NextSiblingElement();
				}
			}
		}
	}

	return food;
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

int TextDataReader::GetStrayerLife()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* st = b->FirstChildElement("Strayer");
			if (st)
			{
				TiXmlElement* l = st->FirstChildElement("Life");

				if (l)
				{
					ret = atoi(l->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetStrayerDamage()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* st = b->FirstChildElement("Strayer");
			if (st)
			{
				TiXmlElement* d = st->FirstChildElement("Damage");

				if (d)
				{
					ret = atoi(d->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetShooterLife()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* sh = b->FirstChildElement("Shooter");
			if (sh)
			{
				TiXmlElement* l = sh->FirstChildElement("Life");

				if (l)
				{
					ret = atoi(l->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetShooterDamage()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* sh = b->FirstChildElement("Shooter");
			if (sh)
			{
				TiXmlElement* d = sh->FirstChildElement("Damage");

				if (d)
				{
					ret = atoi(d->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetSlimLife()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* sl = b->FirstChildElement("Slim");
			if (sl)
			{
				TiXmlElement* l = sl->FirstChildElement("Life");

				if (l)
				{
					ret = atoi(l->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetSlimDamage()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* sl = b->FirstChildElement("Slim");
			if (sl)
			{
				TiXmlElement* l = sl->FirstChildElement("Damage");

				if (l)
				{
					ret = atoi(l->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetFattieLife()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* fa = b->FirstChildElement("Fattie");
			if (fa)
			{
				TiXmlElement* l = fa->FirstChildElement("Life");

				if (l)
				{
					ret = atoi(l->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetFattieDamage()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* fa = b->FirstChildElement("Fattie");
			if (fa)
			{
				TiXmlElement* l = fa->FirstChildElement("Damage");

				if (l)
				{
					ret = atoi(l->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetNormLife()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* no = b->FirstChildElement("Norm");
			if (no)
			{
				TiXmlElement* l = no->FirstChildElement("Life");

				if (l)
				{
					ret = atoi(l->GetText());
				}
			}
		}
	}	

	return ret;
}

int TextDataReader::GetNormDamage()
{
	int ret;
	TiXmlElement* root = doc.FirstChildElement("Texts");

	if (root)
	{
		TiXmlElement* b = root->FirstChildElement( "Bacterias" );
		if (b)
		{
			TiXmlElement* no = b->FirstChildElement("Fattie");
			if (no)
			{
				TiXmlElement* l = no->FirstChildElement("Damage");

				if (l)
				{
					ret = atoi(l->GetText());
				}
			}
		}
	}	

	return ret;
}