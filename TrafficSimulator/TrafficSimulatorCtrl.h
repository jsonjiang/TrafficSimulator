#pragma once

class CTrafficSimulatorCtrl : public CWindowImpl<CTrafficSimulatorCtrl>, //CStatic
	public COwnerDraw<CTrafficSimulatorCtrl>
{
public:
	CTrafficSimulatorCtrl(void)
	{
	}
	~CTrafficSimulatorCtrl()
	{
	}
	DECLARE_WND_SUPERCLASS(_T("WTL_TrafficSimulatorCtrl"), GetWndClassName())
	BEGIN_MSG_MAP(CTrafficSimulatorCtrl)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
		CHAIN_MSG_MAP_ALT( COwnerDraw<CTrafficSimulatorCtrl>,1)
		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()
public:
	LRESULT OnEraseBkgnd(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct  );

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		LRESULT lRes = DefWindowProc();
		return lRes;
	}
};
