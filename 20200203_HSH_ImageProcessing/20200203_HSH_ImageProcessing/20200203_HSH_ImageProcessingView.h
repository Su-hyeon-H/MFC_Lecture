
// 20200203_HSH_ImageProcessingView.h : CMy20200203_HSH_ImageProcessingView 클래스의 인터페이스
//

#pragma once


class CMy20200203_HSH_ImageProcessingView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy20200203_HSH_ImageProcessingView();
	DECLARE_DYNCREATE(CMy20200203_HSH_ImageProcessingView)

// 특성입니다.
public:
	CMy20200203_HSH_ImageProcessingDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy20200203_HSH_ImageProcessingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDownsampling();
//	void OnDownSampling(void);
	afx_msg void OnUpSampling();
};

#ifndef _DEBUG  // 20200203_HSH_ImageProcessingView.cpp의 디버그 버전
inline CMy20200203_HSH_ImageProcessingDoc* CMy20200203_HSH_ImageProcessingView::GetDocument() const
   { return reinterpret_cast<CMy20200203_HSH_ImageProcessingDoc*>(m_pDocument); }
#endif

