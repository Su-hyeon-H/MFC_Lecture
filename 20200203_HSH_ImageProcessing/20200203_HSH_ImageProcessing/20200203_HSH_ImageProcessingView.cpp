
// 20200203_HSH_ImageProcessingView.cpp : CMy20200203_HSH_ImageProcessingView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20200203_HSH_ImageProcessing.h"
#endif

#include "20200203_HSH_ImageProcessingDoc.h"
#include "20200203_HSH_ImageProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200203_HSH_ImageProcessingView

IMPLEMENT_DYNCREATE(CMy20200203_HSH_ImageProcessingView, CView)

BEGIN_MESSAGE_MAP(CMy20200203_HSH_ImageProcessingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20200203_HSH_ImageProcessingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWNSAMPLING, &CMy20200203_HSH_ImageProcessingView::OnDownsampling)
	ON_COMMAND(ID_UP_SAMPLING, &CMy20200203_HSH_ImageProcessingView::OnUpSampling)
END_MESSAGE_MAP()

// CMy20200203_HSH_ImageProcessingView 생성/소멸

CMy20200203_HSH_ImageProcessingView::CMy20200203_HSH_ImageProcessingView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20200203_HSH_ImageProcessingView::~CMy20200203_HSH_ImageProcessingView()
{
}

BOOL CMy20200203_HSH_ImageProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20200203_HSH_ImageProcessingView 그리기

void CMy20200203_HSH_ImageProcessingView::OnDraw(CDC* pDC)
{
	CMy20200203_HSH_ImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int i, j;
   unsigned char R, G, B;

   for(i=0 ; i<pDoc->m_height ; i++){
      for(j=0 ; j<pDoc->m_width ; j++){
         R = G = B = pDoc->m_InputImage[i*pDoc->m_width+j];
         pDC->SetPixel(j+5, i+5, RGB(R, G, B));
      }
   }
   // 축소된 영상 출력
   for(i = 0 ; i<pDoc->m_Re_height ; i++){
       for(j = 0 ; j<pDoc->m_Re_width ; j++){
           R = pDoc->m_OutputImage[i*pDoc->m_Re_width+j];
           G = B = R;
           pDC->SetPixel(j+pDoc->m_width+10, i+5, RGB(R, G, B));
       }
   }

}


// CMy20200203_HSH_ImageProcessingView 인쇄


void CMy20200203_HSH_ImageProcessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20200203_HSH_ImageProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20200203_HSH_ImageProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20200203_HSH_ImageProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy20200203_HSH_ImageProcessingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20200203_HSH_ImageProcessingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20200203_HSH_ImageProcessingView 진단

#ifdef _DEBUG
void CMy20200203_HSH_ImageProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200203_HSH_ImageProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200203_HSH_ImageProcessingDoc* CMy20200203_HSH_ImageProcessingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200203_HSH_ImageProcessingDoc)));
	return (CMy20200203_HSH_ImageProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200203_HSH_ImageProcessingView 메시지 처리기


void CMy20200203_HSH_ImageProcessingView::OnDownsampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMy20200203_HSH_ImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
   ASSERT_VALID(pDoc);

   pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

   Invalidate(TRUE); // 화면 갱신
	
}





void CMy20200203_HSH_ImageProcessingView::OnUpSampling()
{
	   // TODO: Add your command handler code here
   CMy20200203_HSH_ImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
   ASSERT_VALID(pDoc);

   pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출
 
   Invalidate(TRUE); // 화면 갱신

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
