
// 20200131_HSH_ImageProcessingView.h : CMy20200131_HSH_ImageProcessingView Ŭ������ �������̽�
//

#pragma once


class CMy20200131_HSH_ImageProcessingView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20200131_HSH_ImageProcessingView();
	DECLARE_DYNCREATE(CMy20200131_HSH_ImageProcessingView)

// Ư���Դϴ�.
public:
	CMy20200131_HSH_ImageProcessingDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy20200131_HSH_ImageProcessingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 20200131_HSH_ImageProcessingView.cpp�� ����� ����
inline CMy20200131_HSH_ImageProcessingDoc* CMy20200131_HSH_ImageProcessingView::GetDocument() const
   { return reinterpret_cast<CMy20200131_HSH_ImageProcessingDoc*>(m_pDocument); }
#endif

