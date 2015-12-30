#pragma once
#include "DrawUtil.h"
#include "Vehicle.h"

class CRoad
{
public:
	//CRoad BuildRoad(Point x, Point y, UINT lanes);
	CRoad(Point x, Point y, UINT lanes):m_pX(x), m_pY(y), m_nLanes(lanes), m_bHorizontal(TRUE){}
	void Draw(DrawParam& param);
	void AddVehicle(CVehicle* pVehicle);
	void Update();
	Point GetX(){return m_pX;}
	Point GetY(){return m_pY;}
private:
	Point m_pX, m_pY;
	BOOL m_bHorizontal;
	UINT m_nLanes;
	std::vector<CVehicle*> m_vecVehicle;
	std::vector<CVehicle*> m_vecVehicleReverse;
	typedef std::vector<CVehicle*> Vehicles;
};