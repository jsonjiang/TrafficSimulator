#pragma once
#include "DrawUtil.h"

class CRoad
{
public:
	//CRoad BuildRoad(Point x, Point y, UINT lanes);
	CRoad(Point x, Point y, UINT lanes):m_pX(x), m_pY(y), m_nLanes(lanes){}
	void Draw(DrawParam& param);
private:
	Point m_pX, m_pY;
	UINT m_nLanes;
};