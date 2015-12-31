#include "stdafx.h"
#include "MainDlg.h"



LRESULT CMainDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	menu.Attach( LoadMenu( _Module.GetResourceInstance(),MAKEINTRESOURCE(IDR_MENU1)));
	SetMenu( menu );
	// center the dialog on the screen
    MoveWindow(0, 0, 1024, 700);
	CenterWindow();

	// set icons
	HICON hIcon = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON));
	SetIcon(hIcon, TRUE);
	HICON hIconSmall = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON));
	SetIcon(hIconSmall, FALSE);

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	UIAddChildWindowContainer(m_hWnd);

	m_trafficCtrl.SubclassWindow(this->GetDlgItem(IDC_STATIC));
    m_trafficCtrl.MoveWindow(5, 0, 800, 600);
	SetTimer(1, 200, NULL);
	return TRUE;
}

LRESULT CMainDlg::OnMenuSet(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	return S_OK;
}

LRESULT CMainDlg::OnTimer(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	Invalidate(FALSE);
	return S_OK;
}
