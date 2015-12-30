#pragma once
#include "MemPool.h"
#include "DrawUtil.h"

class CVehicle
{
public:
	UINT speed, maxSpeed, deceleration, acceleration, maxAcceleration, maxDeceleration; //m/s
	UINT reflectTime;//��Ӧʱ��,ms
	Point p;
	UINT safeDistance(){return speed*speed/2/deceleration+reflectTime*speed/1000;} //����ʱ��+��Ӧʱ��
	void Draw(DrawParam& param);
	static CVehicle* Alloc();

private:
	CVehicle():p(0,0){
        speed = maxSpeed = acceleration = maxAcceleration = deceleration = maxDeceleration = 0;
    }
	static CMemPool<CVehicle> m_vehiclePool;
	friend class CMemPool<CVehicle>;
};