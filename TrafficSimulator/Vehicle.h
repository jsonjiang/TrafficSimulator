#pragma once

class CVehicle
{
public:
	UINT speed, deceleration, acceleration;
	UINT reflectTime;//��Ӧʱ��,ms
	UINT safeDistance(){return speed*speed/2/deceleration+reflectTime*speed/1000;} //����ʱ��+��Ӧʱ��
};