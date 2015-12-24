#include "stdafx.h"
#include "TrafficSimulatorCtrl.h"

void CTrafficSimulatorCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDCHandle dc = lpDrawItemStruct->hDC;
	RECT& rcItem = lpDrawItemStruct->rcItem;
	dc.FillRect( &rcItem, 21);
	dc.MoveTo( rcItem.left, rcItem.top);
	dc.LineTo(rcItem.right, rcItem.bottom);
}
