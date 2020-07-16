// OptionsDialog.cpp : implementation file
//GUI for Options

#include <afxwin.h>
#include <afxdlgs.h>
#include "OptionsDialog.h"


extern BOOL add_to_recorded_time;
extern BOOL normal_speed;
extern int time_interval;
extern int repeat_count;
/////////////////////////////////////////////////////////////////////////////
// OptionsDialog dialog


OptionsDialog::OptionsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(OptionsDialog::IDD, pParent)
{
	

	//{{AFX_DATA_INIT(OptionsDialog)
	//}}AFX_DATA_INIT
}


void OptionsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(OptionsDialog)
	DDX_Control(pDX, IDC_REPEAT_PLAYBACK, m_repeat_playback);
	DDX_Control(pDX, IDC_NO_OF_REPETITIONS, m_no_of_repetitions);
	DDX_Control(pDX, IDC_ADD_TO_RECORDED_TIME, m_add_to_recorded_time);
	DDX_Control(pDX, IDC_TIME_INTERVAL, m_time_interval);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(OptionsDialog, CDialog)
	//{{AFX_MSG_MAP(OptionsDialog)
	ON_BN_CLICKED(IDOK, OnOK_Click)
	ON_BN_CLICKED(IDC_USER_DEFINED_SPEED, OnUserDefinedSpeed_Click)
	ON_BN_CLICKED(IDC_NORMAL_SPEED, OnNormalSpeed_Click)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_REPEAT_PLAYBACK, OnRepeatPlayback_Click)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OptionsDialog message handlers

void OptionsDialog::OnOK_Click() 
{
	
	//If repeat playback has been checked
	if (m_repeat_playback.GetCheck()==1)
	{
		BOOL value_ok=TRUE;
		repeat_count=GetDlgItemInt(IDC_NO_OF_REPETITIONS,&value_ok);
		if (!value_ok || repeat_count<=0 )
		{
			//Clear it so that next time dialog opens, the "Repeat Playback" button is unchecked
			//signifying rejection of invalid input provided now.
			repeat_count=0;
			MessageBox( "Invalid value for No. of Repetitions. Please give a positive integer value greater than zero.\r\nUncheck Repeat Playback checkbox if you don't want to repeat playback.", \
			"WinMacro Input Error",MB_ICONERROR|MB_OK);
			
			return;
		}
	}

	
	
	//If normal speed has been selected, set bool value to true
	CButton *ptr=(CButton *)GetDlgItem(IDC_NORMAL_SPEED);
	if (ptr->GetCheck()==1)
	{
		normal_speed=TRUE;
		time_interval=0;
	}
	else
	{
		
		//Get and check if time interval entered is valid.
		BOOL value_ok=TRUE;
		time_interval=GetDlgItemInt(IDC_TIME_INTERVAL,&value_ok);

		//Check if Add to Recorded Time Checkbox is checked and set bool variable
		ptr=(CButton *)GetDlgItem(IDC_ADD_TO_RECORDED_TIME);
		
		if (value_ok==0 )
		{
				MessageBox("Invalid value for Time Interval. Please specify a numeric value",\
					"WinMacro Input Error",MB_ICONERROR|MB_OK);
			return;
		}

		//Set bool variable to false
		normal_speed=FALSE;
		
		if (ptr->GetCheck()==1)
		{
			add_to_recorded_time=TRUE;
		}
		else
		{
			add_to_recorded_time=FALSE;
		}
	}
	CDialog::OnOK();
}

BOOL OptionsDialog::OnInitDialog() 
{
	
	CDialog::OnInitDialog();
	
	
	char buf[10];	
	
	
	//Initialize UI according to stored values


	//Check if repeat_count has been specified earlier
	//and if so, prepare UI accordingly
	if (!repeat_count)
	{
		m_repeat_playback.SetCheck(0);
		m_no_of_repetitions.EnableWindow(FALSE);
	}
	else
	{
		m_repeat_playback.SetCheck(1);
		m_no_of_repetitions.EnableWindow(TRUE);
	}
	
	m_no_of_repetitions.SetWindowText(itoa(repeat_count,buf,10));
	
	
	
	
	if (normal_speed)
	{
		CButton *ptr=(CButton *)GetDlgItem(IDC_NORMAL_SPEED);
		ptr->SetCheck(1);	

		m_time_interval.EnableWindow(FALSE);
		m_add_to_recorded_time.EnableWindow(FALSE);	
		
	}
	else
	{
		CButton *ptr=(CButton *)GetDlgItem(IDC_USER_DEFINED_SPEED);
		ptr->SetCheck(1);
	}

	
	m_time_interval.SetWindowText(itoa(time_interval,buf,10));
	if (add_to_recorded_time)
	{
		m_add_to_recorded_time.SetCheck(1);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void OptionsDialog::OnUserDefinedSpeed_Click() 
{
	m_time_interval.EnableWindow(TRUE);
	m_add_to_recorded_time.EnableWindow(TRUE);
	
	
}

void OptionsDialog::OnNormalSpeed_Click() 
{
	m_time_interval.EnableWindow(FALSE);
	m_add_to_recorded_time.EnableWindow(FALSE);	
	
}

void OptionsDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void OptionsDialog::OnRepeatPlayback_Click() 
{
	//It's getting checked now
	if (m_repeat_playback.GetCheck()==1)
	{
		m_no_of_repetitions.EnableWindow(TRUE);
	}
	else
	{
		m_no_of_repetitions.EnableWindow(FALSE);
	}
	
}
