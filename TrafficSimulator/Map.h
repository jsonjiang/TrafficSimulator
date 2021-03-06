#pragma once
#include "Road.h"
#include <vector>

class CMap
{
public:
	static CMap* GetGlobalMap();
	static void InitMaps();
	BOOL AddRoad(CRoad* road);
	void Draw(DrawParam& param);
	void Update();
private:
	std::vector<CRoad*> m_vecRoad;
};