#include <afxwin.h>

class CHelloApp : public CWinApp
{
public:
    virtual BOOL InitInstance();
};

class CMainFrame : public CFrameWnd
{
public:
    CMainFrame();

protected:
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    DECLARE_MESSAGE_MAP()
};


CHelloApp theApp;

BOOL CHelloApp::InitInstance()
{
    m_pMainWnd = new CMainFrame;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    return TRUE;
}

CMainFrame::CMainFrame()
{
    Create(NULL, _T("HelloMFC"));
}

void CMainFrame::OnPaint()
{
    CPaintDC dc(this);
    const TCHAR* msg = _T("Hello, MFC");
    dc.TextOutW(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
    int answer = MessageBox(_T("종료하시겠습니까?"), _T("마우스 메시지"), MB_ICONQUESTION | MB_YESNO);
    if (answer == IDYES) DestroyWindow();

}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
