#pragma once


// CUpSampledlg ��ȭ �����Դϴ�.

class CUpSampledlg : public CDialog
{
	DECLARE_DYNAMIC(CUpSampledlg)

public:
	CUpSampledlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUpSampledlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
#pragma once


// CUpSampleDlg ��ȭ �����Դϴ�.

class CUpSampleDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpSampleDlg) 

public:
	CUpSampleDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUpSampleDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_UpSampleRate;
};
