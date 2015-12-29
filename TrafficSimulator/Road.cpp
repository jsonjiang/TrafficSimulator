#include "stdafx.h"
#include "Road.h"

void CRoad::Draw(DrawParam& param){
    RECT& rcItem = param.rectView;
    CDCHandle dc = param.dc;
    //dc.FillRect(&rcItem, 21);
    CPen pen;
    pen.CreatePen(PS_DASH, 2, 0x00ffff);
    dc.SelectPen(pen);
    dc.MoveTo(m_pX.X, m_pX.Y);
    dc.LineTo(m_pY.X, m_pY.Y);

}
