#pragma once


// CUpSampledlg 대화 상자입니다.

class CUpSampledlg : public CDialog
{
	DECLARE_DYNAMIC(CUpSampledlg)

public:
	CUpSampledlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CUpSampledlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
#pragma once


// CUpSampleDlg 대화 상자입니다.

class CUpSampleDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpSampleDlg) 

public:
	CUpSampleDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CUpSampleDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_UpSampleRate;
};
