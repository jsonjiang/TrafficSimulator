#include "stdafx.h"
#include "Map.h"

#define WIDTH 800
#define HEIGHT 600
static CMap *g_map = NULL;

void CMap::InitMaps()
{
	g_map = new CMap;
	g_map->AddRoad(CRoad(Point(0, HEIGHT/2), Point(WIDTH, HEIGHT/2), 4));
}

void CMap::Draw(DrawParam& param)
{
    std::vector<CRoad>::iterator it = m_vecRoad.begin();
    for (;it != m_vecRoad.end();it++){
    	it->Draw(param);
    }
    
}

BOOL CMap::AddRoad(CRoad& road)
{
    m_vecRoad.push_back(road);
	return TRUE;
}

CMap* CMap::GetGlobalMap()
{
	return g_map;
}
