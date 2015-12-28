#pragma once

class CVehicle
{
public:
	UINT speed, deceleration, acceleration;
	UINT reflectTime;//反应时间,ms
	UINT safeDistance(){return speed*speed/2/deceleration+reflectTime*speed/1000;} //减速时间+反应时间
};