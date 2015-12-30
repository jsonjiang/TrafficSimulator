#include "stdafx.h"
#include "Vehicle.h"
CMemPool<CVehicle> CVehicle::m_vehiclePool;
CVehicle* CVehicle::Alloc()
{
	return m_vehiclePool.Alloc();
}

void CVehicle::Draw(DrawParam& param)
{
	CDCHandle dc = param.dc;
	RECT rect = {p.X-2, p.Y-1, p.X+2, p.Y+1};
	dc.FillRect(&rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
}
