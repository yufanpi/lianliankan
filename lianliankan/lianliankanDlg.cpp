
// lianliankanDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "lianliankanDlg.h"
#include "afxdialogex.h"
#include "ClearLianliankan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClianliankanDlg 对话框



ClianliankanDlg::ClianliankanDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClianliankanDlg::IDD, pParent)
	, m_iDelay(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClianliankanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DELAY, m_iDelay);
	DDV_MinMaxInt(pDX, m_iDelay, 0, 50000);
}

BEGIN_MESSAGE_MAP(ClianliankanDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HOTKEY()
END_MESSAGE_MAP()


// ClianliankanDlg 消息处理程序

BOOL ClianliankanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	if (!GetChessBase())
	{
		AfxMessageBox(_T("获得系统信息失败！"));
		return FALSE;
	}

	if (!RegisterHotKey(m_hWnd, 100613, MOD_CONTROL, 0x31))
	{
		AfxMessageBox(_T("热键CTRL+1绑定失败！"));
		return FALSE;
	}
	if (!RegisterHotKey(m_hWnd, 100614, MOD_CONTROL, 0x32))
	{
		AfxMessageBox(_T("热键CTRL+2绑定失败！"));
		return FALSE;
	}
	m_iDelay = 200;
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClianliankanDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ClianliankanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ClianliankanDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	ClearLianliankan clearLianliankan(m_lpChess);
	UpdateData(TRUE);
	if (nHotKeyId == 100613)
	{
		//UpdateData(TRUE);
		clearLianliankan.Clear();
	}
	if (nHotKeyId == 100614)
	{	
		while (clearLianliankan.Clear())
		{
			//UpdateData(TRUE);
			Sleep(m_iDelay);
		}
			
	}

	CDialogEx::OnHotKey(nHotKeyId, nKey1, nKey2);
}


BOOL ClianliankanDlg::GetChessBase()
{
	//m_lpChess = (LPVOID)0x129f78;
// 	OSVERSIONINFOEX  VerInfo;
// 	VerInfo.dwOSVersionInfoSize = sizeof(VerInfo);
// 	if (!GetVersionEx((OSVERSIONINFO *)&VerInfo))
// 	{
// 		return FALSE;
// 	}
// 	if (VerInfo.dwMajorVersion != 6)
// 	{
// 		return FALSE;
// 	}
// 	switch (VerInfo.dwMinorVersion)
// 	{
// 	case 1:
// 		//win7
// 		m_lpChess = (LPVOID)0x129f78;
// 		break;
// 	case 2:
// 		//win8
// 		m_lpChess = (LPVOID)0x189f7c;
// 		break;
// 	default:
// 		break;
// 	}
	if (IsOS(OS_WOW6432))
	{
		m_lpChess = (LPVOID)0x189f7c;
	}
	else
	{
		m_lpChess = (LPVOID)0x129f78;
	}
	return TRUE;
}
