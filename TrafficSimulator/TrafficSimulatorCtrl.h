#pragma once

class CTrafficSimulatorCtrl : public CWindowImpl<CTrafficSimulatorCtrl/*, CStatic*/>, //CStatic
	public COwnerDraw<CTrafficSimulatorCtrl>
{
public:
	CTrafficSimulatorCtrl(void)
	{
	}
	~CTrafficSimulatorCtrl()
	{
	}
	BEGIN_MSG_MAP(CTrafficSimulatorCtrl)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
		CHAIN_MSG_MAP_ALT( COwnerDraw<CTrafficSimulatorCtrl>,1)
		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()

public:
	LRESULT OnEraseBkgnd(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		return 1;
	}
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct  );
};
