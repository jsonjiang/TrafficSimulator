#include "stdafx.h"
#include "Map.h"
#include "VehicleGen.h"

#define WIDTH 800
#define HEIGHT 600
static CMap *g_map = NULL;
VOID TimerToUpdate(HWND, UINT, UINT_PTR, DWORD);

void CMap::InitMaps()
{
	g_map = new CMap;
	CRoad* pRoad = new CRoad(Point(0, HEIGHT/2), Point(WIDTH, HEIGHT/2), 4);
	g_map->AddRoad(pRoad);
	VehicleGen::s_vehicleGen.AddRoad(pRoad);
	VehicleGen::s_vehicleGen.SetGenInterval(1000);
	//VehicleGen::s_vehicleGen.Start();
	VehicleGen::s_vehicleGen.GenerateVehicle();

	SetTimer(NULL, 1, 200, (TIMERPROC) TimerToUpdate);
}

void CMap::Draw(DrawParam& param)
{
    std::vector<CRoad*>::iterator it = m_vecRoad.begin();
    for (;it != m_vecRoad.end();it++){
    	(*it)->Draw(param);
    }
}

BOOL CMap::AddRoad(CRoad* road)
{
    m_vecRoad.push_back(road);
	return TRUE;
}

CMap* CMap::GetGlobalMap()
{
	return g_map;
}

void CMap::Update()
{
	std::vector<CRoad*>::iterator it = m_vecRoad.begin();
	for (;it != m_vecRoad.end();it++){
		(*it)->Update();
	}
}

VOID TimerToUpdate(HWND, UINT, UINT_PTR, DWORD){
	g_map->Update();
};