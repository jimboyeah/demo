#include "stdafx.h"
#include "../res/resource.h"       // main symbols

class CAboutDlg : public CDialog
{
public:
// Dialog Data
    //{{AFX_DATA(CAboutDlg)
    typedef enum {
        IDD_ABOUT = IDD_ABOUTBOX,
        IDD_CHILD = ID_VIEW_CHILD,
        IDD_POPUP = ID_VIEW_POPUP,
        IDD_TEXTBOX = ID_VIEW_TEXTBOX,
        IDD_OVERLAPPED = ID_VIEW_OVERLAPPED
        } BoxStyle;
    //}}AFX_DATA

    CAboutDlg();
    CAboutDlg(BoxStyle*);

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAboutDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    //{{AFX_MSG(CAboutDlg)
        // No message handlers
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};
