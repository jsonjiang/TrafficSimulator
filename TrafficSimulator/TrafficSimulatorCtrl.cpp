#include "stdafx.h"
#include "TrafficSimulatorCtrl.h"
#include "Map.h"

void CTrafficSimulatorCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDCHandle dc = lpDrawItemStruct->hDC;
	RECT& rcItem = lpDrawItemStruct->rcItem;
	dc.FillRect( &rcItem, 21);
	//dc.MoveTo( rcItem.left, rcItem.top);
	//dc.LineTo(rcItem.right, rcItem.bottom);
	CMap::GetGlobalMap()->Draw(DrawParam(CDCHandle(lpDrawItemStruct->hDC), lpDrawItemStruct->rcItem, lpDrawItemStruct->rcItem));
}

LRESULT CTrafficSimulatorCtrl::OnEraseBkgnd( UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/ )
{
    return 1;
}
