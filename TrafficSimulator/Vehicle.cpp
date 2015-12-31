#include "stdafx.h"
#include "Vehicle.h"

CMemPool<CVehicle> CVehicle::m_vehiclePool;
CVehicle CVehicle::s_v[3];
void CVehicle::InitProtoType()
{
	s_typeIndex = 0;
	s_v[0].maxSpeed = 5;
	s_v[0].maxAcceleration = 2;
	s_v[0].maxDeceleration = 5;
	s_v[1].maxSpeed = 10;
	s_v[1].maxAcceleration = 3;
	s_v[1].maxDeceleration = 5;
	s_v[2].maxSpeed = 6;
	s_v[2].maxAcceleration = 2;
	s_v[2].maxDeceleration = 5;
}
UINT CVehicle::s_typeIndex;

CVehicle* CVehicle::Alloc()
{
	CVehicle* pVehicle = m_vehiclePool.Alloc();
	*pVehicle = s_v[s_typeIndex++];
	return pVehicle;
}

void CVehicle::Draw(DrawParam& param)
{
	CDCHandle dc = param.dc;
	RECT rect = {p.X-2, p.Y-1, p.X+2, p.Y+1};
	dc.FillRect(&rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
}
