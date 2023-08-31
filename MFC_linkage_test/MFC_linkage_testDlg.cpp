
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
bool g_bFirstStart = TRUE;             // 判斷是否為第一次按下 START
bool g_bStopState = FALSE;             // 判斷是否按下 Stop
DWORD g_dwStartTime;                   // 用於儲存 timeGetTime 開始的時間



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
	, m_strRPM(_T("100"))
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
	DDX_Control(pDX, IDC_STATIC_RPM_NOW, m_staticNowRPM);
}

BEGIN_MESSAGE_MAP(CMFClinkagetestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
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
////////////////////////////////////////////////////////////////////////////////////////
// double 四捨五入轉型 int
int RoundDouble(double dValue)
{
	return static_cast<int>(dValue + 0.5);
}

// 給矩形中心點，傳回矩形 x1,y1,x2,y2
CRect RectCenterToX1Y1X2Y2 (CPoint ptRectCenterPoint, double dRectLen, double dRectW)
{
	double dX1 = ptRectCenterPoint.x - dRectW * 0.5;
	double dY1 = ptRectCenterPoint.y - dRectLen * 0.5;
	double dX2 = ptRectCenterPoint.x + dRectW * 0.5;
	double dY2 = ptRectCenterPoint.y + dRectLen * 0.5;
	CRect rect(CPoint(RoundDouble(dX1), RoundDouble(dY1)), CPoint(RoundDouble(dX2), RoundDouble(dY2)));

	return rect;
}

// 從輸入的寬、高條件，定義左下角方塊
CRect LowerLeftRect (CRect rectCenter, double dLeftW, double iPaintH)
{
	double dLowerRectH = rectCenter.bottom;
	CRect rectLower(CPoint(0, RoundDouble(dLowerRectH)), CPoint(RoundDouble(dLeftW), RoundDouble(iPaintH)));

	return rectLower;
}

// 從輸入的寬、高條件，定義右下角方塊
CRect LowerRightRect (CRect rectCenter, double dRightW, double iPaintH)
{
	double dLowerRectH = rectCenter.bottom;
	CRect rectLower(CPoint(RoundDouble(dRightW), RoundDouble(dLowerRectH)), CPoint(RoundDouble(dRightW) * 2, RoundDouble(iPaintH)));

	return rectLower;
}

// 傳回畫布中心圓軸的內切矩形
CRect BearingPos (double dRadius, double dBearingX, double dBearingY, int iPaintW, int iPaintH)
{
	CPoint ptX1Y1(RoundDouble((iPaintW * 0.5 + dBearingX) - dRadius), RoundDouble((iPaintH - dBearingY) - dRadius));
	CPoint ptX2Y2(RoundDouble((iPaintW * 0.5 + dBearingX) + dRadius), RoundDouble((iPaintH - dBearingY) + dRadius));
	CRect rectBearingPos(ptX1Y1, ptX2Y2);

	return rectBearingPos;
}


// 傳回圓軸圓心座標
CPoint BearingCenter (CRect rectBearing)
{
	int iCenterX = RoundDouble((rectBearing.left + rectBearing.right) * 0.5);
	int iCenterY = RoundDouble((rectBearing.top + rectBearing.bottom) * 0.5);
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


// 每秒轉速 rpm 轉換成角速度 rad/s
double RpmToAngVelocity (double dRpm)
{
	double dAngVelocity = dRpm * (2 * M_PI) / 60;

	return dAngVelocity;
}

// 角度限制在 360 度內
double LimitTo360 (double dAng)
{
	dAng = fmod(dAng, 360.0);
	if (dAng < 0)
	{
		dAng += 360.0;
	}
	return dAng;
}

// 傳回左側軸連接點座標
CPoint LeftBearingCenter (double dLeftLeverRadius, double dLeftAng, CPoint ptBearingCenter)
{
	double dLeftRad = AngToRad(dLeftAng);
	double dPosX = (ptBearingCenter.x - dLeftLeverRadius * cos(dLeftRad));
	double dPosY = (ptBearingCenter.y - dLeftLeverRadius * sin(dLeftRad));
	CPoint ptLeftBearing(RoundDouble(dPosX), RoundDouble(dPosY));

	return ptLeftBearing;
}


// 傳回右側軸連接點座標
CPoint RightBearingCenter (double dRightLeverRadius, double dRightAng, CPoint ptBearingCenter)
{
	double dRightRad = AngToRad(dRightAng);
	double dPosX = (ptBearingCenter.x - dRightLeverRadius * cos(dRightRad));
	double dPosY = (ptBearingCenter.y - dRightLeverRadius * sin(dRightRad));
	CPoint ptRightBearing(RoundDouble(dPosX), RoundDouble(dPosY));

	return ptRightBearing;
}


// 傳回左側滑塊中心座標
CPoint LeftRectCenter (double dLeftLeverLen, double dLeftRectH, double dLeftRectLen, CPoint ptLeftBearingCenter, CPoint ptBearingCenter, int iPaintH)
{
	double dLeftRectCenterH = iPaintH - (dLeftRectH + dLeftRectLen);
	double dLeftRectCenterPosX = (ptLeftBearingCenter.x - sqrt(pow(dLeftLeverLen, 2) - pow((dLeftRectCenterH - ptLeftBearingCenter.y), 2)));
	CPoint ptLeftRectCenterPos(RoundDouble(dLeftRectCenterPosX), RoundDouble(dLeftRectCenterH));

	return ptLeftRectCenterPos;
}


// 傳回右側滑塊中心座標
CPoint RightRectCenter (double dRightLeverLen, double dRightRectH, double dRightRectLen, CPoint ptRightBearingCenter, CPoint ptBearingCenter, int iPaintH)
{
	double dRightRectCenterH = iPaintH - (dRightRectH + dRightRectLen);
	double dRightRectCenterPosX = (ptRightBearingCenter.x + sqrt(pow(dRightLeverLen, 2) - pow((dRightRectCenterH - ptRightBearingCenter.y), 2))); 
	CPoint ptRightRectCenterPos(RoundDouble(dRightRectCenterPosX), RoundDouble(dRightRectCenterH));

	return ptRightRectCenterPos;
}

// 開啟所有輸入框
void CMFClinkagetestDlg::OpenAllInputEdit()
{
	m_editLeftRectLever.EnableWindow(TRUE);
	m_editLeftRectH.EnableWindow(TRUE);
	m_editLeftRectLen.EnableWindow(TRUE);
	m_editLeftRectW.EnableWindow(TRUE);
	m_editRightRectLever.EnableWindow(TRUE);
	m_editRightRectH.EnableWindow(TRUE);
	m_editRightRectLen.EnableWindow(TRUE);
	m_editRightRectW.EnableWindow(TRUE);
	m_editBearingRadius.EnableWindow(TRUE);
	m_editBearingPosX.EnableWindow(TRUE);
	m_editBearingPosY.EnableWindow(TRUE);
	m_editRightLeverRadius.EnableWindow(TRUE);
	m_editRightAng.EnableWindow(TRUE);
	m_editLeftLeverRadius.EnableWindow(TRUE);
	m_editLeftAng.EnableWindow(TRUE);
	m_editRPM.EnableWindow(TRUE);
	m_editAngAcc.EnableWindow(TRUE);
	m_editAngDec.EnableWindow(TRUE);
}

// 關閉所有輸入框
void CMFClinkagetestDlg::CloseAllInputEdit()
{
	m_editLeftRectLever.EnableWindow(FALSE);
	m_editLeftRectH.EnableWindow(FALSE);
	m_editLeftRectLen.EnableWindow(FALSE);
	m_editLeftRectW.EnableWindow(FALSE);
	m_editRightRectLever.EnableWindow(FALSE);
	m_editRightRectH.EnableWindow(FALSE);
	m_editRightRectLen.EnableWindow(FALSE);
	m_editRightRectW.EnableWindow(FALSE);
	m_editBearingRadius.EnableWindow(FALSE);
	m_editBearingPosX.EnableWindow(FALSE);
	m_editBearingPosY.EnableWindow(FALSE);
	m_editRightLeverRadius.EnableWindow(FALSE);
	m_editRightAng.EnableWindow(FALSE);
	m_editLeftLeverRadius.EnableWindow(FALSE);
	m_editLeftAng.EnableWindow(FALSE);
	m_editRPM.EnableWindow(FALSE);
	m_editAngAcc.EnableWindow(FALSE);
	m_editAngDec.EnableWindow(FALSE);
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
		m_editRPM.GetWindowText(m_strRPM);
		m_editAngAcc.GetWindowText(m_strAngAcc);
		m_editAngDec.GetWindowText(m_strAngDec);


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
		m_dRPM = _ttof(m_strRPM);
		m_dAngAcc = _ttof(m_strAngAcc);
		m_dAngDec = _ttof(m_strAngDec);

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

		// 中心圓軸圓心
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

		// 雙緩衝內存畫布設置
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

	// 中心圓軸圓心
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



//按鈕 START
void CMFClinkagetestDlg::OnBnClickedButtonStart()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	// 更新輸入的長,寬,高
	if (g_bFirstStart == TRUE)
	{
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
		m_editRPM.GetWindowText(m_strRPM);
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
		m_dRPM = _ttof(m_strRPM);
		m_dAngAcc = _ttof(m_strAngAcc);
		m_dAngDec = _ttof(m_strAngDec);
	}

	// Start 啟動後，關閉輸入框
	CloseAllInputEdit();

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

	// 確認中心圓軸是否高過畫圖區
	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	CRect rectPaintRegion;
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iWidthPaintRegion = rectPaintRegion.Width();
	int iHeightPaintRegion = rectPaintRegion.Height();
	double dBearingTopState = iHeightPaintRegion - (m_dBearingPosY + m_dBearingRadius);

	// 確認中心圓軸是否左右超\超出繪圖區
	double dBearingLeftStateW = m_dBearingPosX - (dLeftClientMaxLenX + 0.5 * m_dLeftRectW) + iWidthPaintRegion * 0.5;
	double dBearingRightStateW = iWidthPaintRegion * 0.5 - (m_dBearingPosX + (dRightClientMaxLenX + 0.5 * m_dRightRectW));

	// 判斷是否為按下 Stop 後，並且在 RPM 還未為 0時 ，重啟 Start
	if ((g_bStopState == TRUE) && (m_dNowRPM != 0))
	{
		// 計算加速度總面積
		m_dAcceTotalAng = 0.5 * (pow(RpmToAngVelocity(m_dRPM) - RpmToAngVelocity(m_dNowRPM), 2) / RpmToAngVelocity(m_dAngAcc));
		
		// 計算加速度區歷時時間長
		m_dAcceTotalTime = (abs(RpmToAngVelocity(m_dRPM)) - abs(RpmToAngVelocity(m_dNowRPM))) / RpmToAngVelocity(m_dAngAcc);
	}
	else
	{
		// 計算加速度區總面積
		m_dAcceTotalAng = 0.5 * (pow(RpmToAngVelocity(m_dRPM), 2) / RpmToAngVelocity(m_dAngAcc));
		
		// 計算加速度區歷時時間長
		m_dAcceTotalTime = (2 * m_dAcceTotalAng) / abs(RpmToAngVelocity(m_dRPM));
	}

	// 初始化前一秒時間
	m_dTimeBefore = 0;

	// 假設一個時間間隔，這裡設定為 50 毫秒 (0.05 s.) 等於 20 fps
	// 當圖片更新率呈現 12 fps 以上時，人眼就會視其為動畫，我這裡假設為 20 fps
	UINT nInterval = 50;
	
	// 判斷是否為第一次按下 Start
	if (g_bFirstStart == TRUE)
	{
		// 記錄初速
		m_dStartNowRPM = 0.0;

		// 記錄按下 START 開始的時間
		g_dwStartTime = timeGetTime();
		
		// 使用 SetTimer 函數時，就會產生一個計時器
		// 第一個參數 1         : 計時器的名稱
		// 第二個參數 nInterval : 時間間隔 (毫秒)
		// 第三個參數 NULL      : 使用系統默認的回調函數 (OnTime) 
		SetTimer(1, nInterval, NULL);
	}
	else
	{
		if (m_dNowRPM != 0)
		{
			// 記錄初速
			m_dStartNowRPM = abs(m_dNowRPM);

			// 記錄按下 Start 的絕對時間
			g_dwStartTime = timeGetTime();
			g_bStopState = FALSE;
		}
		else
		{
			// 記錄初速
			m_dStartNowRPM = 0.0;

			// 記錄按下 Start 的絕對時間
			g_dwStartTime = timeGetTime();
			SetTimer(1, nInterval, NULL);
		}
	}

	g_bFirstStart = FALSE;

	////////////////////////////////////////////////////////////////////////////////////////
	// 桿長限制
	if ((dLeftClientMaxLenX >= dLeftMaxLenX) || (dRightClientMaxLenX >= dRightMaxLenX))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}

	if ((dLeftClientMinLeverLen <= 0) || (dRightClientMinLeverLen <= 0))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}

	if ((m_dLeftRectLeverLen <= 0) || (m_dRightRectLeverLen <= 0))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////
	// 方塊個別資訊限制 (高、長、寬)
	if ((m_dLeftRectH < 0) || (m_dRightRectH < 0))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}

	if ((m_dLeftRectLen <= 0) || (m_dRightRectLen <= 0))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}

	if ((m_dLeftRectW <= 0) || (m_dRightRectW <= 0))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////
	// 中心圓軸高度限制
	if ((dBearingTopState <= 0) || (m_dBearingPosY < m_dBearingRadius))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}
	// 中心圓軸
	if ((dBearingLeftStateW <= 0) || (dBearingRightStateW <= 0))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}
	// 中心圓軸與左右側半徑限制
	if ((m_dBearingRadius < m_dLeftLeverRadius) || (m_dBearingRadius < m_dRightLeverRadius))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}
	// 中心圓軸半徑
	if (m_dBearingRadius <= 0)
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////
	// 加減速度限制
	if ((m_dAngAcc < 0) || (m_dAngDec < 0))
	{
		KillTimer(1);
		OpenAllInputEdit();
		g_bFirstStart = TRUE;
	}
	////////////////////////////////////////////////////////////////////////////////////////

	g_bStartState = TRUE;
	g_bStopState = FALSE;
}


//按鈕 STOP
void CMFClinkagetestDlg::OnBnClickedButtonStop()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	g_bStopState = TRUE;

	// 判斷是否在還未加速到等速運動時，按下 Stop
	if (m_dTimeAfter >= m_dAcceTotalTime)
	{
		m_dStopNowRPM = abs(m_dNowRPM);
	}
	else
	{
		m_dStopNowRPM = m_dAngAcc * m_dTimeAfter;
	}

	// 初始化前一秒時間
	m_dTimeBefore = 0;

	// 記錄按下 Stop 的時間
	m_dwStopTimeRecord = timeGetTime();

	// 關閉輸入框
	CloseAllInputEdit();

	// 計算減速度區歷時時間長
	m_dDecTotalTime = m_dStopNowRPM / m_dAngDec;

	// 計算減速度區總面積
	m_dDecTotalAng = 0.5 * m_dStopNowRPM * m_dDecTotalTime;

}


// 每等間隔時間做的計算、變數更新
void CMFClinkagetestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	DWORD dwCurrentTime = timeGetTime();

	// 判斷是否為按下 Stop 後
	if (g_bStopState == FALSE)
	{
		// 在 OnTimer 函數中計算經過的時間
		DWORD dwElapsedTime = dwCurrentTime - g_dwStartTime;

		// 將毫秒轉為秒
		double seconds = static_cast<double>(dwElapsedTime) / 1000.0;
		m_dTimeAfter = seconds;

		// 判斷是否還在加速度運動
		if (m_dTimeAfter <= m_dAcceTotalTime)
		{
			// 計算增加的旋轉角度
			m_dAddAng = 0.5 * RpmToAngVelocity(m_dAngAcc) * (pow(m_dTimeAfter, 2) - pow(m_dTimeBefore, 2))
				+ RpmToAngVelocity(m_dStartNowRPM) * (m_dTimeAfter - m_dTimeBefore);

			// 計算速度
			m_dNowRPM = m_dAngAcc * m_dTimeAfter + m_dStartNowRPM;

			// 判斷順逆時針旋轉 (m_dRPM < 0 : 順時針，m_dRPM > 0 : 逆時針)
			if (m_dRPM < 0)
			{
				m_strNowRPM.Format(_T(" % .7f"), -m_dNowRPM);
			}
			else
			{
				m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);
			}

			// 將原本下一秒時間更新為前一秒
			m_dTimeBefore = m_dTimeAfter;
		}
		else if ((m_dTimeBefore < m_dAcceTotalTime) && (m_dTimeAfter > m_dAcceTotalTime))
		{	// 當下一秒加速超過最大等速度時角度的計算
			// 計算增加的旋轉角度
			m_dAddAng = 0.5 * RpmToAngVelocity(m_dAngAcc) * (pow(m_dAcceTotalTime, 2) - pow(m_dTimeBefore, 2))
				+ abs(RpmToAngVelocity(m_dRPM)) * (m_dTimeAfter - m_dAcceTotalTime);

			// 當下速度為最大等速度值
			m_dNowRPM = m_dRPM;
			m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);

			// 將原本下一秒時間更新為前一秒
			m_dTimeBefore = m_dTimeAfter;
		}
		else
		{	// 在等速度運動時的角度計算
			// 計算增加的旋轉角度
			m_dAddAng = abs(RpmToAngVelocity(m_dRPM)) * (m_dTimeAfter - m_dTimeBefore);

			// 當下速度為最大等速度值
			m_dNowRPM = m_dRPM;
			m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);

			// 將原本下一秒時間更新為前一秒
			m_dTimeBefore = m_dTimeAfter;
		}

		// 根據最大等速度值 (m_dRPM) 判斷增加的角度為順或逆時針增加
		if (m_dRPM < 0)
		{
			m_dLeftAng += RadToAng(m_dAddAng);
			m_dRightAng += RadToAng(m_dAddAng);
			m_dLeftAng = LimitTo360(m_dLeftAng);
			m_dRightAng = LimitTo360(m_dRightAng);
		}
		else
		{
			m_dLeftAng -= RadToAng(m_dAddAng);
			m_dRightAng -= RadToAng(m_dAddAng);
			m_dLeftAng = LimitTo360(m_dLeftAng);
			m_dRightAng = LimitTo360(m_dRightAng);
		}
	}
	else
	{

		DWORD dwStopElapsedTime = dwCurrentTime - m_dwStopTimeRecord;

		// 將毫秒轉為秒
		double seconds = static_cast<double>(dwStopElapsedTime) / 1000.0;
		m_dTimeAfter = seconds;

		// 判斷是否還在減速度運動
		if (m_dTimeAfter <= m_dDecTotalTime)
		{
			// 計算減少的旋轉角度
			m_dReduceAng = RpmToAngVelocity(m_dStopNowRPM) * (m_dTimeAfter - m_dTimeBefore)
				- (0.5 * RpmToAngVelocity(m_dAngDec) * (pow(m_dTimeAfter, 2) - pow(m_dTimeBefore, 2)));
			
			// 計算速度
			m_dNowRPM = m_dStopNowRPM - m_dAngDec * m_dTimeAfter;

			// 判斷順逆時針旋轉 (m_dRPM < 0 : 順時針，m_dRPM > 0 : 逆時針)
			if (m_dRPM < 0)
			{
				m_strNowRPM.Format(_T(" % .7f"), -m_dNowRPM);
			}
			else
			{
				m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);
			}
			
			// 將原本下一秒時間更新為前一秒
			m_dTimeBefore = m_dTimeAfter;
		}
		else if ((m_dTimeBefore <= m_dDecTotalTime) && (m_dTimeAfter > m_dDecTotalTime))
		{	// 當下一秒減速低過速度0時角度的計算
			// 計算減少的旋轉角度
			m_dReduceAng = pow((m_dDecTotalTime - m_dTimeBefore), 2) * RpmToAngVelocity(m_dAngDec) * 0.5;
			
			// 當下速度為 0.0
			m_dNowRPM = 0.0;
			m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);

			// 將原本下一秒時間更新為前一秒
			m_dTimeBefore = m_dTimeAfter;

			// 將第一次按下 Start 條件設為 FALSE
			g_bFirstStart = FALSE;
		}
		else
		{	// 速度為 0.0 
			m_dNowRPM = 0.0;
			m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);

			// 將原本下一秒時間更新為前一秒
			m_dTimeBefore = m_dTimeAfter;

			// 將第一次按下 Start 條件設為 FALSE
			g_bFirstStart = FALSE;

		}

		// 根據最大等速度值 (m_dRPM) 判斷減少的角度為順或逆時針減少
		if (m_dRPM < 0)
		{
			m_dLeftAng += RadToAng(m_dReduceAng);
			m_dRightAng += RadToAng(m_dReduceAng);

			m_dLeftAng = LimitTo360(m_dLeftAng);
			m_dRightAng = LimitTo360(m_dRightAng);
		}
		else
		{
			m_dLeftAng -= RadToAng(m_dReduceAng);
			m_dRightAng -= RadToAng(m_dReduceAng);

			m_dLeftAng = LimitTo360(m_dLeftAng);
			m_dRightAng = LimitTo360(m_dRightAng);
		}
	}
	
	m_staticNowRPM.SetWindowText(m_strNowRPM);

	// 當速度為零時初始化前一秒記錄的時間並且重新計時
	if (m_dNowRPM == 0)
	{
		OpenAllInputEdit();
		m_dTimeBefore = 0;
		KillTimer(1);
	}

	// 更新繪圖區
	CRect rectWindow;
	GetDlgItem(IDC_STATIC_PAINT)->GetWindowRect(&rectWindow);
	GetDlgItem(IDC_STATIC_PAINT)->GetParent()->ScreenToClient(rectWindow);
	InvalidateRect(&rectWindow, TRUE);
	UpdateWindow();

	CDialogEx::OnTimer(nIDEvent);
}


