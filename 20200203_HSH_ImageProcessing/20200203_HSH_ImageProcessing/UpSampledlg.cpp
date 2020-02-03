// UpSampledlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "20200203_HSH_ImageProcessing.h"
#include "UpSampledlg.h"
#include "afxdialogex.h"


// CUpSampledlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUpSampledlg, CDialog)

CUpSampledlg::CUpSampledlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUpSampledlg::IDD, pParent)
{

}

CUpSampledlg::~CUpSampledlg()
{
}

void CUpSampledlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUpSampledlg, CDialog)
END_MESSAGE_MAP()


// CUpSampledlg 메시지 처리기입니다.
// UpSampleDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "20200203_HSH_ImageProcessing.h"
#include "UpSampleDlg.h"
#include "afxdialogex.h"


// CUpSampleDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUpSampleDlg, CDialog)

CUpSampleDlg::CUpSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUpSampleDlg::IDD, pParent)
	, m_UpSampleRate(0)
{

}

CUpSampleDlg::~CUpSampleDlg()
{
}

void CUpSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UpSampleRate);
}


BEGIN_MESSAGE_MAP(CUpSampleDlg, CDialog)
END_MESSAGE_MAP()


// CUpSampleDlg 메시지 처리기입니다.
