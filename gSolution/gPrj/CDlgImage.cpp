// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "gPrj.h"
#include "afxdialogex.h"
#include "CDlgImage.h"
#include "gPrjDlg.h"

// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기

void CDlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; ++i)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 640, 480);
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}

	if (makeCircle) {
		drawCircle(&dc);
		drawCross(&dc);
	}
}


void CDlgImage::drawCircle(CDC *pDC)
{
	CPoint topLeft(centerX - radius, centerY - radius);
	CPoint bottomRight(centerX + radius, centerY + radius);
	CRect rect(topLeft, bottomRight);
	
	CPen circlePen;
	circlePen.CreatePen(PS_SOLID, CIRCLE_LINE_DEPTH, COLOR_YELLOW);
	CPen* pOldPen = pDC->SelectObject(&circlePen);

	CBrush brush;
	brush.CreateStockObject(NULL_BRUSH);
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	pDC->Ellipse(rect);

	pDC->SelectObject(pOldBrush);
}

void CDlgImage::drawCross(CDC* pDC)
{

	CPoint topLeft(centerX - radius, centerY - radius);
	CPoint bottomRight(centerX + radius, centerY + radius);
	CRect rect(topLeft, bottomRight);

	CPen linePen;
	linePen.CreatePen(PS_SOLID, CROSS_DEPTH, COLOR_RED);
	CPen* pOldPen = pDC->SelectObject(&linePen);

	pDC->MoveTo(centerX - CROSS_LENGTH / 2, centerY);
	pDC->LineTo(centerX + CROSS_LENGTH / 2, centerY);

	pDC->MoveTo(centerX, centerY - CROSS_LENGTH / 2);
	pDC->LineTo(centerX, centerY + CROSS_LENGTH / 2);
	pDC->SelectObject(pOldPen);
}