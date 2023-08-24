
// MFC_linkage_testDlg.cpp: 實作檔案
//
#include "pch.h"
#include "framework.h"
#include "MFC_linkage_test.h"
#include "MFC_linkage_testDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


bool g_bStartState = FALSE;            // 判斷是否按下 START
DWORD g_dwStartTime;                   // 用於儲存 timeGetTime 開始的時間
double g_dAcceTotalAng = 0.0;          // 加速度區塊總面積



// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFClinkagetestDlg 對話方塊



CMFClinkagetestDlg::CMFClinkagetestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_LINKAGE_TEST_DIALOG, pParent)
	, m_strLeftRectLeverLen(_T("400"))
	, m_strLeftRectH(_T("100"))
	, m_strLeftRectLen(_T("60"))
	, m_strLeftRectW(_T("200"))
	, m_strRightRectLeverLen(_T("500"))
	, m_strRightRectH(_T("150"))
	, m_strRightRectLen(_T("60"))
	, m_strRightRectW(_T("200"))
	, m_strBearingRadius(_T("100"))
	, m_strBearingPosX(_T("0"))
	, m_strBearingPosY(_T("300"))
	, m_strRightLeverRadius(_T("70"))
	, m_strRightAng(_T("-90"))
	, m_strLeftLeverRadius(_T("70"))
	, m_strLeftAng(_T("90"))
	, m_strRPM(_T("100"))              // rpm  =  2*pi*rad / 60s.
	, m_strAngAcc(_T("10"))
	, m_strAngDec(_T("10"))
{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFClinkagetestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LEFT_REC_LEVER, m_strLeftRectLeverLen);
	DDX_Text(pDX, IDC_EDIT_LEFT_REC_HEIGHT, m_strLeftRectH);
	DDX_Text(pDX, IDC_EDIT_LEFT_REC_LENGTH, m_strLeftRectLen);
	DDX_Text(pDX, IDC_EDIT_LEFT_REC_WIDTH, m_strLeftRectW);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REC_LEVER, m_strRightRectLeverLen);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REC_HEIGHT, m_strRightRectH);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REC_LENGTH, m_strRightRectLen);
	DDX_Text(pDX, IDC_EDIT_RIGHT_REC_WIDTH, m_strRightRectW);
	DDX_Text(pDX, IDC_EDIT_SHAFT_RADIUS, m_strBearingRadius);
	DDX_Text(pDX, IDC_EDIT_SHAFT_X_POS, m_strBearingPosX);
	DDX_Text(pDX, IDC_EDIT_SHAFT_Y_POS, m_strBearingPosY);
	DDX_Text(pDX, IDC_EDIT_RIGHT_LEVER_RADIUS, m_strRightLeverRadius);
	DDX_Text(pDX, IDC_EDIT_RIGHT_ANGLE, m_strRightAng);
	DDX_Text(pDX, IDC_EDIT_LEFT_LEVER_RADIUS, m_strLeftLeverRadius);
	DDX_Text(pDX, IDC_EDIT_LEFT_ANGLE, m_strLeftAng);
	DDX_Text(pDX, IDC_EDIT_RPM, m_strRPM);
	DDX_Text(pDX, IDC_EDIT_ANGULAR_ACCELERATION, m_strAngAcc);
	DDX_Text(pDX, IDC_EDIT_ANGULAR_DECELERATION, m_strAngDec);
	DDX_Control(pDX, IDC_EDIT_LEFT_REC_LEVER, m_editLeftRectLever);
	DDX_Control(pDX, IDC_EDIT_LEFT_REC_HEIGHT, m_editLeftRectH);
	DDX_Control(pDX, IDC_EDIT_LEFT_REC_LENGTH, m_editLeftRectLen);
	DDX_Control(pDX, IDC_EDIT_LEFT_REC_WIDTH, m_editLeftRectW);
	DDX_Control(pDX, IDC_EDIT_RIGHT_REC_LEVER, m_editRightRectLever);
	DDX_Control(pDX, IDC_EDIT_RIGHT_REC_HEIGHT, m_editRightRectH);
	DDX_Control(pDX, IDC_EDIT_RIGHT_REC_LENGTH, m_editRightRectLen);
	DDX_Control(pDX, IDC_EDIT_RIGHT_REC_WIDTH, m_editRightRectW);
	DDX_Control(pDX, IDC_EDIT_SHAFT_RADIUS, m_editBearingRadius);
	DDX_Control(pDX, IDC_EDIT_SHAFT_X_POS, m_editBearingPosX);
	DDX_Control(pDX, IDC_EDIT_SHAFT_Y_POS, m_editBearingPosY);
	DDX_Control(pDX, IDC_EDIT_RIGHT_LEVER_RADIUS, m_editRightLeverRadius);
	DDX_Control(pDX, IDC_EDIT_RIGHT_ANGLE, m_editRightAng);
	DDX_Control(pDX, IDC_EDIT_LEFT_LEVER_RADIUS, m_editLeftLeverRadius);
	DDX_Control(pDX, IDC_EDIT_LEFT_ANGLE, m_editLeftAng);
	DDX_Control(pDX, IDC_EDIT_RPM, m_editRPM);
	DDX_Control(pDX, IDC_EDIT_ANGULAR_ACCELERATION, m_editAngAcc);
	DDX_Control(pDX, IDC_EDIT_ANGULAR_DECELERATION, m_editAngDec);
}

BEGIN_MESSAGE_MAP(CMFClinkagetestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_STATIC_PAINT, &CMFClinkagetestDlg::OnStnClickedStaticPaint)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_START, &CMFClinkagetestDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CMFClinkagetestDlg::OnBnClickedButtonStop)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFClinkagetestDlg 訊息處理常式

BOOL CMFClinkagetestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	m_PaintRegionBackgroundColor = RGB(169, 169, 169);

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMFClinkagetestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


////////////////////////////////////////////////////////////////////////////////////////
//判斷左右兩邊方塊是否超出畫部區域
//當超出畫部區域時，傳回最大方塊高度的限制設定
//CRect UppLeftRectPos (double dLeftRectLen, double dLeftRectH, double dLeftRectW, int iPaintW, int iPaintH)
//{
//	if ((dLeftRectLen + dLeftRectH) > iPaintH)
//	{
//		CRect rectLeftUpp(0, 0, dLeftRectW, dLeftRectLen);
//		return  rectLeftUpp;
//	}
//	else
//	{
//		CRect rectLeftUpp(0, iPaintH - (dLeftRectLen + dLeftRectH), dLeftRectW, iPaintH - dLeftRectH);
//		return rectLeftUpp;
//	}
//}
//
//
//CRect UppRightRectPos (double dRightRectLen, double dRightRectH, double dRightRectW, int iPaintW, int iPaintH)
//{
//	if ((dRightRectLen + dRightRectH) > iPaintH)
//	{
//		CRect rectRightUpp(iPaintW - dRightRectW, 0, iPaintW, dRightRectLen);
//		return rectRightUpp;
//	}
//	else
//	{
//		CRect rectRightUpp(iPaintW - dRightRectW, iPaintH - (dRightRectLen + dRightRectH), iPaintW, iPaintH - dRightRectH);
//		return rectRightUpp;
//	}
//}
//
//
//CRect LowLeftRectPos (double dLeftRectLen, double dLeftRectH, double dLowerRectW, int iPaintW, int iPaintH)
//{
//	if ((dLeftRectLen + dLeftRectH) > iPaintH)
//	{
//		CRect rectLeftLow(0, dLeftRectLen, dLowerRectW, iPaintH);
//		return rectLeftLow;
//	}
//	else
//	{
//		CRect rectLeftLow(0, iPaintH - dLeftRectH, dLowerRectW, iPaintH);
//		return rectLeftLow;
//	}
//}
//
//
//CRect LowRightRectPos (double dRightRectLen, double dRightRectH, double dLowerRectW, int iPaintW, int iPaintH)
//{
//	if ((dRightRectLen + dRightRectH) > iPaintH)
//	{
//		CRect rectRightLow(dLowerRectW, dRightRectLen, iPaintW, iPaintH);
//		return rectRightLow;
//	}
//	else
//	{
//		CRect rectRightLow(dLowerRectW, iPaintH - dRightRectH, iPaintW, iPaintH);
//		return rectRightLow;
//	}
//}


// 給矩形中心點，傳回矩形 x1,y1,x2,y2
CRect RectCenterToX1Y1X2Y2(CPoint ptRectCenterPoint, double dRectLen, double dRectW)
{
	double dX1 = ptRectCenterPoint.x - dRectW * 0.5;
	double dY1 = ptRectCenterPoint.y - dRectLen * 0.5;
	double dX2 = ptRectCenterPoint.x + dRectW * 0.5;
	double dY2 = ptRectCenterPoint.y + dRectLen * 0.5;
	CRect rect(CPoint(dX1, dY1), CPoint(dX2, dY2));

	return rect;
}


CRect LowerLeftRect (CRect rectCenter, double dLeftW, double iPaintH)
{
	double dLowerRectH = rectCenter.bottom;
	CRect rectLower(CPoint(0, dLowerRectH), CPoint(dLeftW, iPaintH));

	return rectLower;
}


CRect LowerRightRect(CRect rectCenter, double dRightW, double iPaintH)
{
	double dLowerRectH = rectCenter.bottom;
	CRect rectLower(CPoint(dRightW, dLowerRectH), CPoint(dRightW * 2, iPaintH));

	return rectLower;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
// 傳回畫布中心圓軸的內切矩形
CRect BearingPos (double dRadius, double dBearingX, double dBearingY, int iPaintW, int iPaintH)
{
	CPoint ptX1Y1((iPaintW * 0.5 + dBearingX) - dRadius, (iPaintH - dBearingY) - dRadius);
	CPoint ptX2Y2((iPaintW * 0.5 + dBearingX) + dRadius, (iPaintH - dBearingY) + dRadius);
	CRect rectBearingPos(ptX1Y1, ptX2Y2);

	return rectBearingPos;
}


// 傳回圓軸圓心座標
CPoint BearingCenter (CRect rectBearing)
{
	int iCenterX = (rectBearing.left + rectBearing.right) * 0.5;
	int iCenterY = (rectBearing.top + rectBearing.bottom) * 0.5;
	CPoint ptCenter(iCenterX, iCenterY);

	return ptCenter;
}


// 角度轉弧度
double AngToRad (double dAng)
{
	double dRad = dAng * (M_PI / 180);
	
	return dRad;
}


// 弧度轉角度
double RadToAng (double dRad)
{
	double dAng = dRad * (180 / M_PI);

	return dAng;
}


// 每秒轉速 rpm/s 轉換成角速度 rad/s
double RpmToAngVelocity (double dRpm)
{
	double dAngVelocity = dRpm * (2 * M_PI) / 60;

	return dAngVelocity;
}


// 角速度 rad/s 轉換成每秒轉速 rpm/s
double AngVelovityToRpm(double dAngVelocity)
{
	double dRpm = dAngVelocity * 60 / (2 * M_PI);

	return dRpm;
}


// 角度限制在 360 度內
double LimitTo360(double dAng)
{
	dAng = fmod(dAng, 360.0);
	if (dAng < 0)
	{
		dAng += 360.0;
	}
	return dAng;
}


// 餘弦定理求角度
// dSide1 : 斜邊, 
// dSide2 : 鄰邊, 
// dSide3 : 對邊
// dTheta : 對應角 
double CosAng(double dSide1, double dSide2, double dSide3)
{
	double sCosTheta = (pow(dSide1, 2) + pow(dSide2, 2) - pow(dSide3, 2)) / (2 * dSide1 * dSide2);
	double dTheta = acos(sCosTheta);

	return dTheta;
}


// 傳回左側軸連接點座標
CPoint LeftBearingCenter (double dLeftLeverRadius, double dLeftAng, CPoint ptBearingCenter)
{
	double dLeftRad = AngToRad(dLeftAng);
	double dPosX = abs(dLeftLeverRadius * cos(dLeftRad) - ptBearingCenter.x);
	double dPosY = abs(dLeftLeverRadius * sin(dLeftRad) - ptBearingCenter.y);
	CPoint ptLeftBearing(dPosX, dPosY);

	return ptLeftBearing;
}


// 傳回右側軸連接點座標
CPoint RightBearingCenter (double dRightLeverRadius, double dRightAng, CPoint ptBearingCenter)
{
	double dRightRad = AngToRad(dRightAng);
	double dPosX = abs(dRightLeverRadius * cos(dRightRad) - ptBearingCenter.x);
	double dPosY = abs(dRightLeverRadius * sin(dRightRad) - ptBearingCenter.y);
	CPoint ptRightBearing(dPosX, dPosY);

	return ptRightBearing;
}


// 傳回左側滑塊中心座標
CPoint LeftRectCenter (double dLeftLeverLen, double dLeftRectH, double dLeftRectLen, CPoint ptLeftBearingCenter, CPoint ptBearingCenter, int iPaintH)
{
	double dLeftRectCenterH = iPaintH - (dLeftRectH + dLeftRectLen);
	double dLeftRectCenterPosX = (ptLeftBearingCenter.x - sqrt(pow(dLeftLeverLen, 2) - pow((dLeftRectCenterH - ptLeftBearingCenter.y), 2)));
	CPoint ptLeftRectCenterPos(dLeftRectCenterPosX, dLeftRectCenterH);

	return ptLeftRectCenterPos;
}


// 傳回右側滑塊中心座標
CPoint RightRectCenter (double dRightLeverLen, double dRightRectH, double dRightRectLen, CPoint ptRightBearingCenter, CPoint ptBearingCenter, int iPaintH)
{
	double dRightRectCenterH = iPaintH - (dRightRectH + dRightRectLen);
	double dRightRectCenterPosX = (ptRightBearingCenter.x + sqrt(pow(dRightLeverLen, 2) - pow((dRightRectCenterH - ptRightBearingCenter.y), 2))); 
	CPoint ptRightRectCenterPos(dRightRectCenterPosX, dRightRectCenterH);

	return ptRightRectCenterPos;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////





// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。
void CMFClinkagetestDlg::OnPaint()
{
	if (IsIconic())
	{

		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	
	
	}
	else
	{
		////////////////////////////////////////////////////////////////////////////////////////
		m_editLeftRectLever.GetWindowText(m_strLeftRectLeverLen);
		m_editLeftRectH.GetWindowText(m_strLeftRectH);
		m_editLeftRectLen.GetWindowText(m_strLeftRectLen);
		m_editLeftRectW.GetWindowText(m_strLeftRectW);
		m_editRightRectLever.GetWindowText(m_strRightRectLeverLen);
		m_editRightRectH.GetWindowText(m_strRightRectH);
		m_editRightRectLen.GetWindowText(m_strRightRectLen);
		m_editRightRectW.GetWindowText(m_strRightRectW);
		m_editBearingRadius.GetWindowText(m_strBearingRadius);
		m_editBearingPosX.GetWindowText(m_strBearingPosX);
		m_editBearingPosY.GetWindowText(m_strBearingPosY);
		m_editLeftLeverRadius.GetWindowText(m_strLeftLeverRadius);
		m_editRightLeverRadius.GetWindowText(m_strRightLeverRadius);


		m_dLeftRectLeverLen = _ttof(m_strLeftRectLeverLen);
		m_dLeftRectH = _ttof(m_strLeftRectH);
		m_dLeftRectLen = _ttof(m_strLeftRectLen);
		m_dLeftRectW = _ttof(m_strLeftRectW);
		m_dRightRectLeverLen = _ttof(m_strRightRectLeverLen);
		m_dRightRectH = _ttof(m_strRightRectH);
		m_dRightRectLen = _ttof(m_strRightRectLen);
		m_dRightRectW = _ttof(m_strRightRectW);
		m_dBearingRadius = _ttof(m_strBearingRadius);
		m_dBearingPosX = _ttof(m_strBearingPosX);
		m_dBearingPosY = _ttof(m_strBearingPosY);
		m_dLeftLeverRadius = _ttof(m_strLeftLeverRadius);
		m_dRightLeverRadius = _ttof(m_strRightLeverRadius);


		if (g_bStartState == FALSE)
		{

			m_editLeftAng.GetWindowText(m_strLeftAng);
			m_editRightAng.GetWindowText(m_strRightAng);

			m_dLeftAng = _ttof(m_strLeftAng);
			m_dRightAng = _ttof(m_strRightAng);
		}

		////////////////////////////////////////////////////////////////////////////////////////

		CDialogEx::OnPaint();


		// 取得畫布的長寬高
		CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
		CRect rectPaintRegion;
		pPaintRegion->GetClientRect(&rectPaintRegion);
		int iWidthPaintRegion = rectPaintRegion.Width();
		int iHeightPaintRegion = rectPaintRegion.Height();


		// 計算兩邊下方矩形的固定寬度
		m_dLowerRectW = iWidthPaintRegion * 0.5;


		// 取得上方矩形畫布區域的 dc 並將內部繪成灰色(m_PaintRegionBackgroundColor)
		CPaintDC dc(pPaintRegion);
		CBrush brushPaintRegion;
		CBrush* pOldBrushPaintRegion = dc.SelectObject(&brushPaintRegion);
		brushPaintRegion.CreateSolidBrush(m_PaintRegionBackgroundColor);
		dc.Rectangle(rectPaintRegion);
		dc.FillRect(&rectPaintRegion, &brushPaintRegion);
		dc.SelectObject(pOldBrushPaintRegion);


		// 定義邊界顏色並繪製
		CPen penLowerRectBoarder(PS_SOLID, m_iLowerRectBoarderW * 4, RGB(0, 0, 0));
		CPen penUpperRectBoarder(PS_SOLID, m_iUpperRectBoarderW*2, RGB(0, 0, 0));
		CPen penBearingBoarder(PS_SOLID, m_iBearingBoarderW * 2, RGB(0, 0, 0));
		// 定義兩桿線段
		CPen penLever(PS_SOLID, 4, RGB(0, 0, 0));

		// 下方矩形顏色
		CBrush brushLowerRect;
		brushLowerRect.CreateSolidBrush(RGB(139, 69, 19));
		// 上方矩形顏色
		CBrush brushUpperRect;
		brushUpperRect.CreateSolidBrush(RGB(255, 255, 255));
		// 中心主轉軸顏色
		CBrush brushMainBearing;
		brushMainBearing.CreateSolidBrush(RGB(255, 0, 0));


		// 將黑色邊界 UpperRectBoarderPen 選入 dc
		CPen* pOldPenUpperRectBoarder = dc.SelectObject(&penUpperRectBoarder);
		// 將白色內部  UpperRectBrush 選入 dc
		CBrush* pOldBrushUpperRect = dc.SelectObject(&brushUpperRect);

		// 中心圓軸內切矩形
		CRect rectBearingRect = BearingPos(m_dBearingRadius, m_dBearingPosX, m_dBearingPosY, iWidthPaintRegion, iHeightPaintRegion);


		//// 中心圓軸圓心
		CPoint ptBearingCenterPos = BearingCenter(rectBearingRect);

		// 計算左右滑塊中心座標
		CPoint ptLeftBearingCenter = LeftBearingCenter(m_dLeftLeverRadius, m_dLeftAng, ptBearingCenterPos);
		CPoint ptLeftUpperCenter = LeftRectCenter(m_dLeftRectLeverLen, m_dLeftRectH, m_dLeftRectLen, ptLeftBearingCenter, ptBearingCenterPos, iHeightPaintRegion);

		CPoint ptRightBearingCenter = RightBearingCenter(m_dRightLeverRadius, m_dRightAng, ptBearingCenterPos);
		CPoint ptRightUpperCenter = RightRectCenter(m_dRightRectLeverLen, m_dRightRectH, m_dRightRectLen, ptRightBearingCenter, ptBearingCenterPos, iHeightPaintRegion);


		// 定義左右上方滑塊
		CRect rectLeftUpper = RectCenterToX1Y1X2Y2(ptLeftUpperCenter, m_dLeftRectLen, m_dLeftRectW);
		dc.Rectangle(rectLeftUpper);
		dc.FillRect(&rectLeftUpper, &brushUpperRect);
		CRect rectRightUpper = RectCenterToX1Y1X2Y2(ptRightUpperCenter, m_dRightRectLen, m_dRightRectW);
		dc.Rectangle(rectRightUpper);
		dc.FillRect(&rectRightUpper, &brushUpperRect);
		dc.SelectObject(pOldPenUpperRectBoarder);
		dc.SelectObject(pOldBrushUpperRect);


		// 將黑色邊界  LowerRectBoarderPen 選入 dc
		CPen* pOldPenLowerRectBoarder = dc.SelectObject(&penLowerRectBoarder);
		// 將棕色內部  LowerRectBrush 選入 dc
		CBrush* pOldBrushLowerRect = dc.SelectObject(&brushLowerRect);



		// 定義左右下方方塊
		CRect rectLeftLower = LowerLeftRect(rectLeftUpper, m_dLowerRectW, iHeightPaintRegion);
		dc.Rectangle(rectLeftLower);
		dc.FillRect(&rectLeftLower, &brushLowerRect);
		CRect rectRightLower = LowerRightRect(rectRightUpper, m_dLowerRectW, iHeightPaintRegion);
		dc.Rectangle(rectRightLower);
		dc.FillRect(&rectRightLower, &brushLowerRect);
		dc.SelectObject(pOldPenLowerRectBoarder);
		dc.SelectObject(pOldBrushLowerRect);

		// 中心圓軸繪圖
		CPen* pOldPenBearingBoarder = dc.SelectObject(&penBearingBoarder);
		CBrush* pOldBrushMainBearing = dc.SelectObject(&brushMainBearing);
		dc.Ellipse(rectBearingRect);
		dc.SelectObject(pOldPenBearingBoarder);
		dc.SelectObject(pOldBrushMainBearing);


		// 連桿繪圖
		CPen* pOldPenLever = dc.SelectObject(&penLever);
		dc.SetPixel(ptLeftBearingCenter, RGB(0, 0, 0));
		dc.MoveTo(ptLeftBearingCenter);
		dc.LineTo(ptLeftUpperCenter);
		dc.SetPixel(ptRightBearingCenter, RGB(0, 0, 0));
		dc.MoveTo(ptRightBearingCenter);
		dc.LineTo(ptRightUpperCenter);
		dc.SelectObject(pOldPenLever);



		CPaintDC dcO(pPaintRegion);
		CDC memDC;
		CBitmap memBitmap;
		CRect rect;
		GetClientRect(&rect);
		memDC.CreateCompatibleDC(&dcO);
		memBitmap.CreateCompatibleBitmap(&dcO, rect.Width(), rect.Height());
		memDC.SelectObject(&memBitmap);


		// 在雙緩衝 DC 上進行繪圖
		DrawToBuffer(&memDC);

		// 將雙緩衝 DC 的內容複製到畫布上
		dcO.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

		// 清理
		memBitmap.DeleteObject();
		memDC.DeleteDC();
	}

}


void CMFClinkagetestDlg::DrawToBuffer(CDC* pDC)
{
	// ... (保留原有的程式碼，用於在雙緩衝 DC 上進行繪圖)

	// 取得畫布的長寬高
	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	CRect rectPaintRegion;
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iWidthPaintRegion = rectPaintRegion.Width();
	int iHeightPaintRegion = rectPaintRegion.Height();


	// 計算兩邊下方矩形的固定寬度
	m_dLowerRectW = iWidthPaintRegion * 0.5;


	// 取得上方矩形畫布區域的 dc 並將內部繪成灰色(m_PaintRegionBackgroundColor)
	CPaintDC dc(pPaintRegion);
	CBrush brushPaintRegion;
	CBrush* pOldBrushPaintRegion = dc.SelectObject(&brushPaintRegion);
	brushPaintRegion.CreateSolidBrush(m_PaintRegionBackgroundColor);
	dc.Rectangle(rectPaintRegion);
	dc.FillRect(&rectPaintRegion, &brushPaintRegion);
	dc.SelectObject(pOldBrushPaintRegion);


	// 定義邊界顏色並繪製
	CPen penLowerRectBoarder(PS_SOLID, m_iLowerRectBoarderW * 4, RGB(0, 0, 0));
	CPen penUpperRectBoarder(PS_SOLID, m_iUpperRectBoarderW * 2, RGB(0, 0, 0));
	CPen penBearingBoarder(PS_SOLID, m_iBearingBoarderW * 2, RGB(0, 0, 0));
	// 定義兩桿線段
	CPen penLever(PS_SOLID, 4, RGB(0, 0, 0));

	// 下方矩形顏色
	CBrush brushLowerRect;
	brushLowerRect.CreateSolidBrush(RGB(139, 69, 19));
	// 上方矩形顏色
	CBrush brushUpperRect;
	brushUpperRect.CreateSolidBrush(RGB(255, 255, 255));
	// 中心主轉軸顏色
	CBrush brushMainBearing;
	brushMainBearing.CreateSolidBrush(RGB(255, 0, 0));


	// 將黑色邊界 UpperRectBoarderPen 選入 dc
	CPen* pOldPenUpperRectBoarder = dc.SelectObject(&penUpperRectBoarder);
	// 將白色內部  UpperRectBrush 選入 dc
	CBrush* pOldBrushUpperRect = dc.SelectObject(&brushUpperRect);


	// 中心圓軸內切矩形
	CRect rectBearingRect = BearingPos(m_dBearingRadius, m_dBearingPosX, m_dBearingPosY, iWidthPaintRegion, iHeightPaintRegion);



	//// 中心圓軸圓心
	CPoint ptBearingCenterPos = BearingCenter(rectBearingRect);

	// 計算左右滑塊中心座標
	CPoint ptLeftBearingCenter = LeftBearingCenter(m_dLeftLeverRadius, m_dLeftAng, ptBearingCenterPos);
	CPoint ptLeftUpperCenter = LeftRectCenter(m_dLeftRectLeverLen, m_dLeftRectH, m_dLeftRectLen, ptLeftBearingCenter, ptBearingCenterPos, iHeightPaintRegion);

	CPoint ptRightBearingCenter = RightBearingCenter(m_dRightLeverRadius, m_dRightAng, ptBearingCenterPos);
	CPoint ptRightUpperCenter = RightRectCenter(m_dRightRectLeverLen, m_dRightRectH, m_dRightRectLen, ptRightBearingCenter, ptBearingCenterPos, iHeightPaintRegion);


	// 定義左右上方滑塊
	CRect rectLeftUpper = RectCenterToX1Y1X2Y2(ptLeftUpperCenter, m_dLeftRectLen, m_dLeftRectW);
	dc.Rectangle(rectLeftUpper);
	dc.FillRect(&rectLeftUpper, &brushUpperRect);
	CRect rectRightUpper = RectCenterToX1Y1X2Y2(ptRightUpperCenter, m_dRightRectLen, m_dRightRectW);
	dc.Rectangle(rectRightUpper);
	dc.FillRect(&rectRightUpper, &brushUpperRect);
	dc.SelectObject(pOldPenUpperRectBoarder);
	dc.SelectObject(pOldBrushUpperRect);

	// 將黑色邊界  LowerRectBoarderPen 選入 dc
	CPen* pOldPenLowerRectBoarder = dc.SelectObject(&penLowerRectBoarder);
	// 將棕色內部  LowerRectBrush 選入 dc
	CBrush* pOldBrushLowerRect = dc.SelectObject(&brushLowerRect);

	// 定義左右下方方塊
	CRect rectLeftLower = LowerLeftRect(rectLeftUpper, m_dLowerRectW, iHeightPaintRegion);
	dc.Rectangle(rectLeftLower);
	dc.FillRect(&rectLeftLower, &brushLowerRect);
	CRect rectRightLower = LowerRightRect(rectRightUpper, m_dLowerRectW, iHeightPaintRegion);
	dc.Rectangle(rectRightLower);
	dc.FillRect(&rectRightLower, &brushLowerRect);
	dc.SelectObject(pOldPenLowerRectBoarder);
	dc.SelectObject(pOldBrushLowerRect);

	// 中心圓軸繪圖
	CPen* pOldPenBearingBoarder = dc.SelectObject(&penBearingBoarder);
	CBrush* pOldBrushMainBearing = dc.SelectObject(&brushMainBearing);
	dc.Ellipse(rectBearingRect);
	dc.SelectObject(pOldPenBearingBoarder);
	dc.SelectObject(pOldBrushMainBearing);

	// 連桿繪圖
	CPen* pOldPenLever = dc.SelectObject(&penLever);
	dc.SetPixel(ptLeftBearingCenter, RGB(0, 0, 0));
	dc.MoveTo(ptLeftBearingCenter);
	dc.LineTo(ptLeftUpperCenter);
	dc.SetPixel(ptRightBearingCenter, RGB(0, 0, 0));
	dc.MoveTo(ptRightBearingCenter);
	dc.LineTo(ptRightUpperCenter);
	dc.SelectObject(pOldPenLever);
}




// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMFClinkagetestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFClinkagetestDlg::OnStnClickedStaticPaint()
{
	// TODO: 在此加入控制項告知處理常式程式碼
}


//重新設置方塊的按鈕 START
void CMFClinkagetestDlg::OnBnClickedButtonStart()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	// 按下 START 時記錄開始的時間
	g_dwStartTime = timeGetTime();


	// 更新輸入的長,寬,高
	UpdateData(TRUE);
	m_editLeftRectLever.GetWindowText(m_strLeftRectLeverLen);
	m_editLeftRectH.GetWindowText(m_strLeftRectH);
	m_editLeftRectLen.GetWindowText(m_strLeftRectLen);
	m_editLeftRectW.GetWindowText(m_strLeftRectW);
	m_editRightRectLever.GetWindowText(m_strRightRectLeverLen);
	m_editRightRectH.GetWindowText(m_strRightRectH);
	m_editRightRectLen.GetWindowText(m_strRightRectLen);
	m_editRightRectW.GetWindowText(m_strRightRectW);
	m_editBearingRadius.GetWindowText(m_strBearingRadius);
	m_editBearingPosX.GetWindowText(m_strBearingPosX);
	m_editBearingPosY.GetWindowText(m_strBearingPosY);
	m_editRightLeverRadius.GetWindowText(m_strRightLeverRadius);
	m_editRightAng.GetWindowText(m_strRightAng);
	m_editLeftLeverRadius.GetWindowText(m_strLeftLeverRadius);
	m_editLeftAng.GetWindowText(m_strLeftAng);

	m_editAngAcc.GetWindowText(m_strAngAcc);
	m_editAngDec.GetWindowText(m_strAngDec);


	// 將 string 轉為 double
	m_dLeftRectLeverLen = _ttof(m_strLeftRectLeverLen);
	m_dLeftRectH = _ttof(m_strLeftRectH);
	m_dLeftRectLen = _ttof(m_strLeftRectLen);
	m_dLeftRectW = _ttof(m_strLeftRectW);
	m_dRightRectLeverLen = _ttof(m_strRightRectLeverLen);
	m_dRightRectH = _ttof(m_strRightRectH);
	m_dRightRectLen = _ttof(m_strRightRectLen);
	m_dRightRectW = _ttof(m_strRightRectW);
	m_dBearingRadius = _ttof(m_strBearingRadius);
	m_dBearingPosX = _ttof(m_strBearingPosX);
	m_dBearingPosY = _ttof(m_strBearingPosY);

	m_dRightLeverRadius = _ttof(m_strRightLeverRadius);
	m_dRightAng = _ttof(m_strRightAng);
	m_dLeftLeverRadius = _ttof(m_strLeftLeverRadius);
	m_dLeftAng = _ttof(m_strLeftAng);

	m_dAngAcc = _ttof(m_strAngAcc);
	m_dAngDec = _ttof(m_strAngDec);


	m_editLeftRectLever.EnableWindow(0);
	m_editLeftRectH.EnableWindow(0);
	m_editLeftRectLen.EnableWindow(0);
	m_editLeftRectW.EnableWindow(0);
	m_editRightRectLever.EnableWindow(0);
	m_editRightRectH.EnableWindow(0);
	m_editRightRectLen.EnableWindow(0);
	m_editRightRectW.EnableWindow(0);
	m_editBearingRadius.EnableWindow(0);
	m_editBearingPosX.EnableWindow(0);
	m_editBearingPosY.EnableWindow(0);
	m_editRightLeverRadius.EnableWindow(0);
	m_editRightAng.EnableWindow(0);
	m_editLeftLeverRadius.EnableWindow(0);
	m_editLeftAng.EnableWindow(0);
	m_editRPM.EnableWindow(0);
	m_editAngAcc.EnableWindow(0);
	m_editAngDec.EnableWindow(0);


	// 中心圓軸與滑塊最大距離條件設定
	// 當桿長長度大於此條件時，直接暫停並重新輸入
	double dLeftMaxLenY = m_dBearingPosY - (m_dLeftRectLen * 0.5 + m_dLeftRectH);
	double dLeftMaxLenX = m_dLowerRectW - 0.5 * m_dLeftRectW;
	double dLeftClientMaxLenX = sqrt(pow((m_dLeftRectLeverLen + m_dBearingRadius), 2) - pow(dLeftMaxLenY, 2));

	double dRightMaxLenY = m_dBearingPosY - (m_dRightRectLen * 0.5 + m_dRightRectH);
	double dRightMaxLenX = m_dLowerRectW - 0.5 * m_dRightRectW;
	double dRightClientMaxLenX = sqrt(pow((m_dRightRectLeverLen + m_dBearingRadius), 2) - pow(dRightMaxLenY, 2));

	// 中心圓軸與滑塊最小距離條件設定
	// 當桿長長度小於此條件時，直接暫停輸入
	double dLeftRectSmallSide = sqrt(pow((m_dLeftRectLen * 0.5 + m_dLeftRectH), 2) + pow((m_dLeftRectLen + m_dLeftRectH), 2));
	double dLeftClientMinLeverLen = m_dLeftRectLeverLen - 2 * m_dLeftLeverRadius - dLeftRectSmallSide;

	double dRightRectSmallSide = sqrt(pow((m_dRightRectLen * 0.5 + m_dRightRectH), 2) + pow((m_dRightRectLen + m_dRightRectH), 2));
	double dRightClientMinLeverLen = m_dRightRectLeverLen - 2 * m_dRightLeverRadius - dRightRectSmallSide;


	// 確認當中心圓軸是否高過畫圖區
	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	CRect rectPaintRegion;
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iWidthPaintRegion = rectPaintRegion.Width();
	int iHeightPaintRegion = rectPaintRegion.Height();
	double dBearingTopState = iHeightPaintRegion - (m_dBearingPosY + m_dBearingRadius);


	// 設定一個時間間隔，這裡設定為 42 毫秒 (0.042 s.)
	UINT nInterval = 42;
	// 使用 SetTimer 函數時，就會產生一個計時器
	// 第一個參數 1         : 計時器的名稱
	// 第二個參數 nInterval : 時間間隔 (毫秒)
	// 第三個參數 NULL      : 使用系統默認的回調函數 (OnTime) 
	SetTimer(1, nInterval, NULL);


	if ((dLeftClientMaxLenX >= dLeftMaxLenX) || (dRightClientMaxLenX >= dRightMaxLenX))
	{
		KillTimer(1);

		m_editLeftRectLever.EnableWindow(1);
		m_editLeftRectH.EnableWindow(1);
		m_editLeftRectLen.EnableWindow(1);
		m_editLeftRectW.EnableWindow(1);
		m_editRightRectLever.EnableWindow(1);
		m_editRightRectH.EnableWindow(1);
		m_editRightRectLen.EnableWindow(1);
		m_editRightRectW.EnableWindow(1);
		m_editBearingRadius.EnableWindow(1);
		m_editBearingPosX.EnableWindow(1);
		m_editBearingPosY.EnableWindow(1);
		m_editRightLeverRadius.EnableWindow(1);
		m_editRightAng.EnableWindow(1);
		m_editLeftLeverRadius.EnableWindow(1);
		m_editLeftAng.EnableWindow(1);
		m_editRPM.EnableWindow(1);
		m_editAngAcc.EnableWindow(1);
		m_editAngDec.EnableWindow(1);

	}

	if ((dLeftClientMinLeverLen <= 0) || (dRightClientMinLeverLen <= 0))
	{
		KillTimer(1);

		m_editLeftRectLever.EnableWindow(1);
		m_editLeftRectH.EnableWindow(1);
		m_editLeftRectLen.EnableWindow(1);
		m_editLeftRectW.EnableWindow(1);
		m_editRightRectLever.EnableWindow(1);
		m_editRightRectH.EnableWindow(1);
		m_editRightRectLen.EnableWindow(1);
		m_editRightRectW.EnableWindow(1);
		m_editBearingRadius.EnableWindow(1);
		m_editBearingPosX.EnableWindow(1);
		m_editBearingPosY.EnableWindow(1);
		m_editRightLeverRadius.EnableWindow(1);
		m_editRightAng.EnableWindow(1);
		m_editLeftLeverRadius.EnableWindow(1);
		m_editLeftAng.EnableWindow(1);
		m_editRPM.EnableWindow(1);
		m_editAngAcc.EnableWindow(1);
		m_editAngDec.EnableWindow(1);
	}


	if ((dBearingTopState <= 0) || (m_dBearingPosY < m_dBearingRadius))
	{
		KillTimer(1);

		m_editLeftRectLever.EnableWindow(1);
		m_editLeftRectH.EnableWindow(1);
		m_editLeftRectLen.EnableWindow(1);
		m_editLeftRectW.EnableWindow(1);
		m_editRightRectLever.EnableWindow(1);
		m_editRightRectH.EnableWindow(1);
		m_editRightRectLen.EnableWindow(1);
		m_editRightRectW.EnableWindow(1);
		m_editBearingRadius.EnableWindow(1);
		m_editBearingPosX.EnableWindow(1);
		m_editBearingPosY.EnableWindow(1);
		m_editRightLeverRadius.EnableWindow(1);
		m_editRightAng.EnableWindow(1);
		m_editLeftLeverRadius.EnableWindow(1);
		m_editLeftAng.EnableWindow(1);
		m_editRPM.EnableWindow(1);
		m_editAngAcc.EnableWindow(1);
		m_editAngDec.EnableWindow(1);
	}



	g_bStartState = TRUE;
}



void CMFClinkagetestDlg::OnBnClickedButtonStop()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	m_editLeftRectLever.EnableWindow(1);
	m_editLeftRectH.EnableWindow(1);
	m_editLeftRectLen.EnableWindow(1);
	m_editLeftRectW.EnableWindow(1);
	m_editRightRectLever.EnableWindow(1);
	m_editRightRectH.EnableWindow(1);
	m_editRightRectLen.EnableWindow(1);
	m_editRightRectW.EnableWindow(1);
	m_editBearingRadius.EnableWindow(1);
	m_editBearingPosX.EnableWindow(1);
	m_editBearingPosY.EnableWindow(1);
	m_editRightLeverRadius.EnableWindow(1);
	m_editRightAng.EnableWindow(1);
	m_editLeftLeverRadius.EnableWindow(1);
	m_editLeftAng.EnableWindow(1);
	m_editRPM.EnableWindow(1);
	m_editAngAcc.EnableWindow(1);
	m_editAngDec.EnableWindow(1);

	KillTimer(1);
}


void CMFClinkagetestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值


	// 在 OnTimer 函數中計算經過的時間
	DWORD dwCurrentTime = timeGetTime();
	DWORD dwElapsedTime = dwCurrentTime - g_dwStartTime;

	// 將毫秒轉為秒
	double seconds = static_cast<double>(dwElapsedTime) / 1000.0;


	//if (m_dLeftAng <= -360)
	//{
	//	m_dLeftAng = m_dLeftAng + 360;
	//}
	//
	//if (m_dRightAng <= -360)
	//{
	//	m_dRightAng = m_dRightAng + 360;
	//}



	if (g_bStartState = TRUE)
	{
		m_editRPM.GetWindowText(m_strRPM);
		m_dRPM = _ttof(m_strRPM);
	}


	/*
		已知加速度值，
		
	
	*/
	
	// 加入加速度
	// 考慮加速度至等速運動時，加速度超過等速限制
	// 發現轉速會一直累加不會是單位圓角度
	//double dMaxAng = RpmToAngVelocity(m_dRPM);
	//if ((m_dLeftAng < m_dRPM) && (m_dRightAng < m_dRPM))
	//{
	//	m_dLeftAng -= pow(seconds, 2) * 0.5 * m_dAngAcc;
	//	m_dRightAng -= pow(seconds, 2) * 0.5 * m_dAngAcc;
	//}
	//else
	//{
	//	//m_dLeftAng -= seconds * m_dAngAcc;
	//	//m_dRightAng -= seconds * m_dAngAcc;
	//	m_dLeftAng = seconds * m_dRPM;
	//	m_dRightAng = seconds * m_dRPM;
	//}

	m_dLeftAng -= pow(seconds, 2) * 0.5 * m_dAngAcc;
	m_dRightAng -= pow(seconds, 2) * 0.5 * m_dAngAcc;

	//m_dLeftAng -= 10;
	//m_dRightAng -= 10;



	CRect rectWindow;
	GetDlgItem(IDC_STATIC_PAINT)->GetWindowRect(&rectWindow);
	GetDlgItem(IDC_STATIC_PAINT)->GetParent()->ScreenToClient(rectWindow);
	InvalidateRect(&rectWindow, TRUE);
	UpdateWindow();

	CDialogEx::OnTimer(nIDEvent);
}









