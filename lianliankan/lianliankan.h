
// lianliankan.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// ClianliankanApp: 
// �йش����ʵ�֣������ lianliankan.cpp
//

class ClianliankanApp : public CWinApp
{
public:
	ClianliankanApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern ClianliankanApp theApp;