
// lianliankanDlg.h : ͷ�ļ�
//

#pragma once


// ClianliankanDlg �Ի���
class ClianliankanDlg : public CDialogEx
{
// ����
public:
	ClianliankanDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LIANLIANKAN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	int m_iDelay;
private:
	LPVOID m_lpChess;
	BOOL GetChessBase();
};
