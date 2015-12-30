#include "stdafx.h"
#include "Road.h"

void CRoad::Draw(DrawParam& param){
    RECT& rcItem = param.rectView;
    CDCHandle dc = param.dc;
    //dc.FillRect(&rcItem, 21);
    CPen pen;
    pen.CreatePen(PS_SOLID, 1, 0x00ffff);
    dc.SelectPen(pen);
    dc.MoveTo(m_pX.X, m_pX.Y);
    dc.LineTo(m_pY.X, m_pY.Y);
	pen.DeleteObject();
	pen.CreatePen(PS_SOLID, 1, 0xffffff);
	dc.SelectPen(pen);
	dc.MoveTo(m_pX.X, m_pX.Y-4);
	dc.LineTo(m_pY.X, m_pY.Y-4);
	dc.MoveTo(m_pX.X, m_pX.Y+4);
	dc.LineTo(m_pY.X, m_pY.Y+4);
	dc.SelectPen(NULL);
	Vehicles::iterator it = m_vecVehicle.begin();
	for (;it!=m_vecVehicle.end();++it){
		(*it)->Draw(param);
	}
}

void CRoad::AddVehicle(CVehicle* pVehicle)
{
	m_vecVehicle.push_back(pVehicle);
}

void CRoad::Update()
{
	Vehicles::iterator it = m_vecVehicle.begin();
	for (;it!=m_vecVehicle.end();++it){
		CVehicle& v = **it;
		UINT t = 1;
		UINT d = v.speed*t + v.acceleration*v.acceleration/(2*t) - v.deceleration*v.deceleration/(2*t);
		if(m_bHorizontal)
			v.p.X += d;
		else
			v.p.Y += d;
	}
}
