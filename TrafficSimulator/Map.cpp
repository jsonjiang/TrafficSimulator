#include "stdafx.h"
#include "Map.h"

#define WIDTH 2000
#define HEIGHT	1000
static CMap *g_map = NULL;

void CMap::InitMaps()
{
	g_map = new CMap;
	g_map->AddRoad(CRoad(Point(0, HEIGHT/2), Point(WIDTH, HEIGHT/2), 4));
}

void CMap::Draw(DrawParam& param)
{

}

BOOL CMap::AddRoad(CRoad& road)
{
	return TRUE;
}

CMap* CMap::GetGlobalMap()
{
	return g_map;
}
