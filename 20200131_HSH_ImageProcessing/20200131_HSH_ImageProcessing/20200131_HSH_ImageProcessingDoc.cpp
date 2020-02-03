
// 20200131_HSH_ImageProcessingDoc.cpp : CMy20200131_HSH_ImageProcessingDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20200131_HSH_ImageProcessing.h"
#endif

#include "20200131_HSH_ImageProcessingDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy20200131_HSH_ImageProcessingDoc

IMPLEMENT_DYNCREATE(CMy20200131_HSH_ImageProcessingDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy20200131_HSH_ImageProcessingDoc, CDocument)
END_MESSAGE_MAP()


// CMy20200131_HSH_ImageProcessingDoc ����/�Ҹ�

CMy20200131_HSH_ImageProcessingDoc::CMy20200131_HSH_ImageProcessingDoc()
	: m_InputImage(0)
	, m_width(0)
	, m_height(0)
	, m_size(0)
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMy20200131_HSH_ImageProcessingDoc::~CMy20200131_HSH_ImageProcessingDoc()
{
}

BOOL CMy20200131_HSH_ImageProcessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMy20200131_HSH_ImageProcessingDoc serialization

void CMy20200131_HSH_ImageProcessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMy20200131_HSH_ImageProcessingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CMy20200131_HSH_ImageProcessingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy20200131_HSH_ImageProcessingDoc::SetSearchContent(const CString& value)
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

// CMy20200131_HSH_ImageProcessingDoc ����

#ifdef _DEBUG
void CMy20200131_HSH_ImageProcessingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy20200131_HSH_ImageProcessingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy20200131_HSH_ImageProcessingDoc ���


BOOL CMy20200131_HSH_ImageProcessingDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	  CFile File; // ���� ��ü ����

      File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
      // ���� ���� ��ȭ���ڿ��� ������ ������ �����ϰ� �б� ��� ����

      // �� å������ ������ ũ�� 256*256, 512*512, 640*480���� ����Ѵ�.
      if(File.GetLength() == 256*256){ // RAW ������ ũ�� ����

      m_height = 256;
      m_width = 256;
   }
   else if(File.GetLength() == 512*512){ // RAW ������ ũ�� ����
      m_height = 512;
      m_width = 512;
   }
   else if(File.GetLength() == 640*480){ // RAW ������ ũ�� ����
      m_height = 480;
      m_width = 640;
   }
   else{
      AfxMessageBox(_T("Not Support Image Size")); // �ش� ũ�Ⱑ ���� ���
      return 0;
   }
   m_size = m_width * m_height; // ������ ũ�� ���

   m_InputImage = new unsigned char [m_size];
   // �Է� ������ ũ�⿡ �´� �޸� �Ҵ�

   for(int i = 0 ; i<m_size ; i++)
      m_InputImage[i] = 255; // �ʱ�ȭ
   File.Read(m_InputImage, m_size); // �Է� ���� ���� �б�
   File.Close(); // ���� �ݱ�

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return TRUE;
}
