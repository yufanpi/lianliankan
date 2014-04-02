
// lianliankanDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lianliankan.h"
#include "lianliankanDlg.h"
#include "afxdialogex.h"
#include "ClearLianliankan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClianliankanDlg �Ի���



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


// ClianliankanDlg ��Ϣ�������

BOOL ClianliankanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	if (!GetChessBase())
	{
		AfxMessageBox(_T("���ϵͳ��Ϣʧ�ܣ�"));
		return FALSE;
	}

	if (!RegisterHotKey(m_hWnd, 100613, MOD_CONTROL, 0x31))
	{
		AfxMessageBox(_T("�ȼ�CTRL+1��ʧ�ܣ�"));
		return FALSE;
	}
	if (!RegisterHotKey(m_hWnd, 100614, MOD_CONTROL, 0x32))
	{
		AfxMessageBox(_T("�ȼ�CTRL+2��ʧ�ܣ�"));
		return FALSE;
	}
	m_iDelay = 200;
	UpdateData(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void ClianliankanDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR ClianliankanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ClianliankanDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
