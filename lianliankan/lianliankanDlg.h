
// lianliankanDlg.h : 头文件
//

#pragma once


// ClianliankanDlg 对话框
class ClianliankanDlg : public CDialogEx
{
// 构造
public:
	ClianliankanDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LIANLIANKAN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
