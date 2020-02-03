
// 20200131_HSH_ImageProcessingView.cpp : CMy20200131_HSH_ImageProcessingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20200131_HSH_ImageProcessing.h"
#endif

#include "20200131_HSH_ImageProcessingDoc.h"
#include "20200131_HSH_ImageProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200131_HSH_ImageProcessingView

IMPLEMENT_DYNCREATE(CMy20200131_HSH_ImageProcessingView, CView)

BEGIN_MESSAGE_MAP(CMy20200131_HSH_ImageProcessingView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20200131_HSH_ImageProcessingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy20200131_HSH_ImageProcessingView ����/�Ҹ�

CMy20200131_HSH_ImageProcessingView::CMy20200131_HSH_ImageProcessingView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20200131_HSH_ImageProcessingView::~CMy20200131_HSH_ImageProcessingView()
{
}

BOOL CMy20200131_HSH_ImageProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20200131_HSH_ImageProcessingView �׸���

void CMy20200131_HSH_ImageProcessingView::OnDraw(CDC* pDC)
{
	CMy20200131_HSH_ImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	int i, j;
   unsigned char R, G, B;

   for(i=0 ; i<pDoc->m_height ; i++){
      for(j=0 ; j<pDoc->m_width ; j++){
         R = G = B = pDoc->m_InputImage[i*pDoc->m_width+j];
         pDC->SetPixel(j+5, i+5, RGB(R, G, B));
      }
   }

}


// CMy20200131_HSH_ImageProcessingView �μ�


void CMy20200131_HSH_ImageProcessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20200131_HSH_ImageProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20200131_HSH_ImageProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20200131_HSH_ImageProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy20200131_HSH_ImageProcessingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20200131_HSH_ImageProcessingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20200131_HSH_ImageProcessingView ����

#ifdef _DEBUG
void CMy20200131_HSH_ImageProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200131_HSH_ImageProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200131_HSH_ImageProcessingDoc* CMy20200131_HSH_ImageProcessingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200131_HSH_ImageProcessingDoc)));
	return (CMy20200131_HSH_ImageProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200131_HSH_ImageProcessingView �޽��� ó����
