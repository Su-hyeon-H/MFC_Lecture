
// 20200203_HSH_ImageProcessing.h : 20200203_HSH_ImageProcessing ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy20200203_HSH_ImageProcessingApp:
// �� Ŭ������ ������ ���ؼ��� 20200203_HSH_ImageProcessing.cpp�� �����Ͻʽÿ�.
//

class CMy20200203_HSH_ImageProcessingApp : public CWinAppEx
{
public:
	CMy20200203_HSH_ImageProcessingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20200203_HSH_ImageProcessingApp theApp;
