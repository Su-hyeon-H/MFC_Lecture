
// 20200203_HSH_ImageProcessing.h : 20200203_HSH_ImageProcessing 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CMy20200203_HSH_ImageProcessingApp:
// 이 클래스의 구현에 대해서는 20200203_HSH_ImageProcessing.cpp을 참조하십시오.
//

class CMy20200203_HSH_ImageProcessingApp : public CWinAppEx
{
public:
	CMy20200203_HSH_ImageProcessingApp();


// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 구현입니다.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20200203_HSH_ImageProcessingApp theApp;
