
// 20200203_HSH_ImageProcessingDoc.cpp : CMy20200203_HSH_ImageProcessingDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20200203_HSH_ImageProcessing.h"
#endif

#include "20200203_HSH_ImageProcessingDoc.h"
#include "DownSampleDlg.h"
#include "UpSampleDlg.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy20200203_HSH_ImageProcessingDoc

IMPLEMENT_DYNCREATE(CMy20200203_HSH_ImageProcessingDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy20200203_HSH_ImageProcessingDoc, CDocument)
END_MESSAGE_MAP()


// CMy20200203_HSH_ImageProcessingDoc 생성/소멸

CMy20200203_HSH_ImageProcessingDoc::CMy20200203_HSH_ImageProcessingDoc()
	: m_InputImage(0)
	, m_width(0)
	, m_height(0)
	, m_size(0)
	, m_OutputImage(NULL)
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMy20200203_HSH_ImageProcessingDoc::~CMy20200203_HSH_ImageProcessingDoc()
{
}

BOOL CMy20200203_HSH_ImageProcessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMy20200203_HSH_ImageProcessingDoc serialization

void CMy20200203_HSH_ImageProcessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMy20200203_HSH_ImageProcessingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CMy20200203_HSH_ImageProcessingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy20200203_HSH_ImageProcessingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy20200203_HSH_ImageProcessingDoc 진단

#ifdef _DEBUG
void CMy20200203_HSH_ImageProcessingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy20200203_HSH_ImageProcessingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy20200203_HSH_ImageProcessingDoc 명령

BOOL CMy20200203_HSH_ImageProcessingDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	  CFile File; // 파일 객체 선언

      File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
      // 파일 열기 대화상자에서 선택한 파일을 지정하고 읽기 모드 선택

      // 이 책에서는 영상의 크기 256*256, 512*512, 640*480만을 사용한다.
      if(File.GetLength() == 256*256){ // RAW 파일의 크기 결정

      m_height = 256;
      m_width = 256;
   }
   else if(File.GetLength() == 512*512){ // RAW 파일의 크기 결정
      m_height = 512;
      m_width = 512;
   }
   else if(File.GetLength() == 640*480){ // RAW 파일의 크기 결정
      m_height = 480;
      m_width = 640;
   }
   else{
      AfxMessageBox(_T("Not Support Image Size")); // 해당 크기가 없는 경우
      return 0;
   }
   m_size = m_width * m_height; // 영상의 크기 계산

   m_InputImage = new unsigned char [m_size];
   // 입력 영상의 크기에 맞는 메모리 할당

   for(int i = 0 ; i<m_size ; i++)
      m_InputImage[i] = 255; // 초기화
   File.Read(m_InputImage, m_size); // 입력 영상 파일 읽기
   File.Close(); // 파일 닫기

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return TRUE;
}

BOOL CMy20200203_HSH_ImageProcessingDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CFile File; // 파일 객체 선언
  CFileDialog SaveDlg(FALSE, "raw", NULL, OFN_HIDEREADONLY);
  // raw 파일을 다른 이름으로 저장하기를 위한 대화상자 객체 선언

    if(SaveDlg.DoModal() == IDOK){
    // DoModal 멤버 함수에서 저장하기 수행
    File.Open(SaveDlg.GetPathName(), CFile::modeCreate |
    CFile::modeWrite);
    // 파일 열기
    File.Write(m_InputImage, m_size); // 파일 쓰기
    File.Close(); // 파일 닫기
    }

  return TRUE;


	/*return CDocument::OnSaveDocument(lpszPathName);*/
}


void CMy20200203_HSH_ImageProcessingDoc::OnDownSampling()
{
	int i, j;
   CDownSampleDlg dlg;
   if(dlg.DoModal() == IDOK) // 대화상자의 활성화 여부
   {
      m_Re_height = m_height / dlg.m_DownSampleRate;
      // 축소 영상의 세로 길이를 계산
      m_Re_width = m_width / dlg.m_DownSampleRate;
      // 축소 영상의 가로 길이를 계산
      m_Re_size = m_Re_height * m_Re_width;
      // 축소 영상의 크기를 계산

      m_OutputImage = new unsigned char [m_Re_size];     
      // 축소 영상을 위한 메모리 할당

      for(i=0 ; i<m_Re_height ; i++){
       for(j=0 ; j<m_Re_width ; j++){
         m_OutputImage[i*m_Re_width + j]
          = m_InputImage[(i*dlg.m_DownSampleRate*m_width)+dlg.m_DownSampleRate*j];
                // 축소 영상을 생성
         }
     }
   }

}


void CMy20200203_HSH_ImageProcessingDoc::OnUpSampling(void)
{
	int i, j;
   
   CUpSampleDlg dlg;
   if(dlg.DoModal() == IDOK){ // DoModal 대화상자의 활성화 여부
       m_Re_height = m_height * dlg.m_UpSampleRate;
       // 확대 영상의 세로 길이 계산
       m_Re_width = m_width * dlg.m_UpSampleRate;
       // 확대 영상의 가로 길이 계산
       m_Re_size = m_Re_height * m_Re_width;
       // 확대 영상의 크기 계산
       m_OutputImage = new unsigned char[m_Re_size];
       // 확대 영상을 위한 메모리 할당

       for(i=0 ; i<m_Re_size ; i++)
           m_OutputImage[i] = 0; // 초기화

       for(i=0 ; i<m_height ; i++){
           for(j=0 ; j<m_width ; j++){
              m_OutputImage[i*dlg.m_UpSampleRate*m_Re_width +
              dlg.m_UpSampleRate*j]= m_InputImage[i*m_width + j];
           } // 재배치하여 영상 확대
       }
   }
}
