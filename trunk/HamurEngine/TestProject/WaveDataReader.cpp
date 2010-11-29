#include "WaveDataReader.h"
#include "Wave.h"

using namespace hamur;

WaveDataReader::WaveDataReader( char *fileName )
{
	TiXmlDocument doc(fileName);
	if(!doc.LoadFile())
	{
		HAMURLOG->WriteLog("Xml file could not be loaded");
		HAMURENGINE->Stop();
		return;
	}

	CreateWavesFromData(doc);
}

void WaveDataReader::CreateWavesFromData(const TiXmlDocument &doc)
{
	TiXmlNode *root = (TiXmlElement *)doc.RootElement();
	
	TiXmlElement *waves = 0;//(TiXmlElement *)root->FirstChild();
	while( waves = (TiXmlElement *)root->IterateChildren(waves) )
	{
		int fattieCount, normCount, shooterCount, slimCount, strayerCount;
		fattieCount = normCount = shooterCount = slimCount = strayerCount = 0;

		TiXmlElement *bacterias = 0;//(TiXmlElement *)waves->FirstChild();
		while(bacterias = (TiXmlElement *)waves->IterateChildren(bacterias))
		{
			if(string(bacterias->Value()) == "BacteriaFattie")
			{
				fattieCount = atoi(bacterias->Attribute("Count"));
			}
			else if(string(bacterias->Value()) == "BacteriaNorm")
			{
				normCount = atoi(bacterias->Attribute("Count"));
			}
			else if(string(bacterias->Value()) == "BacteriaShooter")
			{
				shooterCount = atoi(bacterias->Attribute("Count"));
			}
			else if(string(bacterias->Value()) == "BacteriaSlim")
			{
				slimCount = atoi(bacterias->Attribute("Count"));
			}
			else if(string(bacterias->Value()) == "BacteriaStrayer")
			{
				strayerCount = atoi(bacterias->Attribute("Count"));
			}
		}
		
		int waveTime = atoi(waves->Attribute("Time"));

		Wave *w = new Wave(waves->Attribute("Name"), waveTime, fattieCount, normCount,
				shooterCount, slimCount, strayerCount);
	}
}

WaveDataReader::~WaveDataReader()
{

}