#pragma once
#include <list>
#include "Road.h"

VOID TimerProc(HWND, UINT, UINT_PTR, DWORD);
class VehicleGen{
public:
	void AddRoad(CRoad* pRoad){ m_listRoad.push_back(pRoad); }
	void Clear(){m_listRoad.clear();}
	void SetGenInterval(UINT time){ m_uInterval = time;} //ms

	void Start(){
		SetTimer(NULL, 1, m_uInterval, (TIMERPROC) TimerProc);
	}

	void GenerateVehicle(){
		std::list<CRoad*>::iterator it = m_listRoad.begin();
		for (;it != m_listRoad.end();it++){
			CVehicle* pVehicle = CVehicle::Alloc();
			pVehicle->speed = 5;
			pVehicle->maxSpeed = 10;
			pVehicle->acceleration = 2;
			pVehicle->deceleration = 5;
			pVehicle->p = (*it)->GetX();
			(*it)->AddVehicle(pVehicle);
		}
	}
	static VehicleGen s_vehicleGen;
private:
	std::list<CRoad*> m_listRoad;
	UINT m_uInterval;
};

VehicleGen VehicleGen::s_vehicleGen;
VOID TimerProc(HWND, UINT, UINT_PTR, DWORD){
	VehicleGen::s_vehicleGen.GenerateVehicle();
};