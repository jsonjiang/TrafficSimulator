#pragma once
#include "MemPool.h"
#include "DrawUtil.h"

class CVehicle
{
public:
	UINT speed, maxSpeed, deceleration, acceleration; //m/s
	UINT reflectTime;//��Ӧʱ��,ms
	Point p;
	UINT safeDistance(){return speed*speed/2/deceleration+reflectTime*speed/1000;} //����ʱ��+��Ӧʱ��
	void Draw(DrawParam& param);
	static CVehicle* Alloc();

private:
	CVehicle(){}
	static CMemPool<CVehicle> m_vehiclePool;
	friend class CMemPool<CVehicle>;
};