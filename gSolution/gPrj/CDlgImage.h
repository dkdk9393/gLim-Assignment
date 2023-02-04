#pragma once
#include "afxdialogex.h"

#define CROSS_LENGTH 10
#define CROSS_DEPTH 3
#define CIRCLE_LINE_DEPTH 5
#define COLOR_YELLOW RGB(0xff, 0xff, 0)
#define COLOR_RED RGB(0xff, 0,0)

// CDlgImage 대화 상자

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgImage();

	CImage m_image;
	CWnd* m_pParent;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	BOOL makeCircle = FALSE;
	int centerX;
	int centerY;
	int radius;
private:
	void InitImage();
	void drawCircle(CDC* pDC);
	void drawCross(CDC* pDC);
};
