#pragma once

#include "hamur.h"
#include "tinyxml.h"

class WaveDataReader
{
public:
	WaveDataReader(char *fileName);
	~WaveDataReader();


private:
	void CreateWavesFromData(TiXmlDocument doc);

};