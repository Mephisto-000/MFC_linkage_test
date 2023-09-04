
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


BOOL g_bStartState = FALSE;            // 判斷是否按下 START
BOOL g_bFirstStart = TRUE;             // 判斷是否為第一次按下 START
BOOL g_bStopState = FALSE;             // 判斷是否按下 Stop
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
	, m_strLeftRectLeverLen(_T("400.0"))
	, m_strLeftRectH(_T("100.0"))
	, m_strLeftRectLen(_T("60.0"))
	, m_strLeftRectW(_T("200.0"))
	, m_strRightRectLeverLen(_T("500.0"))
	, m_strRightRectH(_T("150.0"))
	, m_strRightRectLen(_T("60.0"))
	, m_strRightRectW(_T("200.0"))
	, m_strBearingRadius(_T("100.0"))
	, m_strBearingPosX(_T("0.0"))
	, m_strBearingPosY(_T("300.0"))
	, m_strRightLeverRadius(_T("80.0"))
	, m_strRightAng(_T("270.0"))
	, m_strLeftLeverRadius(_T("80.0"))
	, m_strLeftAng(_T("90.0"))
	, m_strRPM(_T("100.0"))
	, m_strAngAcc(_T("10.0"))
	, m_strAngDec(_T("10.0"))
	, m_dLeftRectLeverLen(400.0)                     
	, m_dLeftRectH(100.0)
	, m_dLeftRectLen(60.0)      						
	, m_dLeftRectW(200.0)
	, m_dRightRectLeverLen(500.0)                        
	, m_dRightRectH(150.0)    							
	, m_dRightRectLen(60.0) 
	, m_dRightRectW(200.0)
	, m_dBearingRadius(100.0)
	, m_dBearingPosX(0.0)      						
	, m_dBearingPosY(300.0)      						
	, m_dRightLeverRadius(80.0)     					
	, m_dRightAng(270.0)     							
	, m_dLeftLeverRadius(80.0)      					
	, m_dLeftAng(90.0)      							
	, m_dRPM(100.0)      								
	, m_dAngAcc(10.0)     							
	, m_dAngDec(10.0)   
	, m_dLowerRectW(0.0)                        
	, m_iLowerRectBoarderW(1)                    
	, m_iUpperRectBoarderW(1)					
	, m_iBearingBoarderW(1)						
	, m_ptLeftUpperCenterPos((0, 0))		       
	, m_ptRightUpperCenterPos((0, 0))			
	, m_ptBearingCenterPos((0, 0))				
	, m_dAcceTotalAng(0.0)                      
	, m_dAcceTotalTime(0.0)                     
	, m_dTimeCurrentSpan(0.0)							
	, m_dTimePreviousSpan(0.0)                         
	, m_dAddAng(0.0)								
	, m_dMaxAddAng(0.0)                                                
	, m_dStopNowRPM(0.0)						
	, m_dStartNowRPM(0.0)                        
	, m_dDecTotalAng(0.0)                        
	, m_dDecTotalTime(0.0)						
	, m_dReduceAng(0.0)                          
	, m_dwStopTimeRecord(0)                      
	, m_dNowRPM(0.0)                            
	, m_strNowRPM(_T(""))

	, m_strOldLeftRectLeverLen(_T("400"))
	, m_strOldLeftRectH(_T("100"))
	, m_strOldLeftRectLen(_T("60"))
	, m_strOldLeftRectW(_T("200"))
	, m_strOldRightRectLeverLen(_T("500"))
	, m_strOldRightRectH(_T("150"))
	, m_strOldRightRectLen(_T("60"))
	, m_strOldRightRectW(_T("200"))
	, m_strOldBearingRadius(_T("100"))
	, m_strOldBearingPosX(_T("0"))
	, m_strOldBearingPosY(_T("300"))
	, m_strOldRightLeverRadius(_T("70"))
	, m_strOldRightAng(_T("-90"))
	, m_strOldLeftLeverRadius(_T("70"))
	, m_strOldLeftAng(_T("90"))
	, m_strOldRPM(_T("100"))
	, m_strOldAngAcc(_T("10"))
	, m_strOldAngDec(_T("10"))
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
	DDX_Control(pDX, IDC_EDIT_LEFT_REC_LEVER, m_editLeftRectLeverLen);
	DDX_Control(pDX, IDC_EDIT_LEFT_REC_HEIGHT, m_editLeftRectH);
	DDX_Control(pDX, IDC_EDIT_LEFT_REC_LENGTH, m_editLeftRectLen);
	DDX_Control(pDX, IDC_EDIT_LEFT_REC_WIDTH, m_editLeftRectW);
	DDX_Control(pDX, IDC_EDIT_RIGHT_REC_LEVER, m_editRightRectLeverLen);
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
	ON_EN_KILLFOCUS(IDC_EDIT_ANGULAR_ACCELERATION, &CMFClinkagetestDlg::OnEnKillfocusEditAngularAcceleration)
	ON_EN_KILLFOCUS(IDC_EDIT_ANGULAR_DECELERATION, &CMFClinkagetestDlg::OnEnKillfocusEditAngularDeceleration)
	ON_EN_KILLFOCUS(IDC_EDIT_RPM, &CMFClinkagetestDlg::OnEnKillfocusEditRpm)
	ON_EN_KILLFOCUS(IDC_EDIT_LEFT_REC_LEVER, &CMFClinkagetestDlg::OnEnKillfocusEditLeftRecLever)
	ON_EN_KILLFOCUS(IDC_EDIT_LEFT_REC_HEIGHT, &CMFClinkagetestDlg::OnEnKillfocusEditLeftRecHeight)
	ON_EN_KILLFOCUS(IDC_EDIT_LEFT_REC_LENGTH, &CMFClinkagetestDlg::OnEnKillfocusEditLeftRecLength)
	ON_EN_KILLFOCUS(IDC_EDIT_LEFT_REC_WIDTH, &CMFClinkagetestDlg::OnEnKillfocusEditLeftRecWidth)
	ON_EN_KILLFOCUS(IDC_EDIT_RIGHT_REC_LEVER, &CMFClinkagetestDlg::OnEnKillfocusEditRightRecLever)
	ON_EN_KILLFOCUS(IDC_EDIT_RIGHT_REC_HEIGHT, &CMFClinkagetestDlg::OnEnKillfocusEditRightRecHeight)
	ON_EN_KILLFOCUS(IDC_EDIT_RIGHT_REC_LENGTH, &CMFClinkagetestDlg::OnEnKillfocusEditRightRecLength)
	ON_EN_KILLFOCUS(IDC_EDIT_RIGHT_REC_WIDTH, &CMFClinkagetestDlg::OnEnKillfocusEditRightRecWidth)
	ON_EN_KILLFOCUS(IDC_EDIT_SHAFT_RADIUS, &CMFClinkagetestDlg::OnEnKillfocusEditShaftRadius)
	ON_EN_KILLFOCUS(IDC_EDIT_SHAFT_X_POS, &CMFClinkagetestDlg::OnEnKillfocusEditShaftXPos)
	ON_EN_KILLFOCUS(IDC_EDIT_SHAFT_Y_POS, &CMFClinkagetestDlg::OnEnKillfocusEditShaftYPos)
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
int RoundDoubleToInt(double dValue)
{
	return static_cast<int>(dValue + 0.5);
}

// 給矩形中心點，傳回矩形 x1,y1,x2,y2
CRect CenterPtToRectPts (CPoint ptRectCenterPoint, double dRectLen, double dRectW)
{
	double dX1 = ptRectCenterPoint.x - dRectW * 0.5;
	double dY1 = ptRectCenterPoint.y - dRectLen * 0.5;
	double dX2 = ptRectCenterPoint.x + dRectW * 0.5;
	double dY2 = ptRectCenterPoint.y + dRectLen * 0.5;
	CRect rect(CPoint(RoundDoubleToInt(dX1), RoundDoubleToInt(dY1)), CPoint(RoundDoubleToInt(dX2), RoundDoubleToInt(dY2)));

	return rect;
}

// 從輸入的寬、高條件，定義左下角方塊
CRect LowerLeftRect (CRect rectCenter, double dLeftW, double iPaintH)
{
	double dLowerRectH = rectCenter.bottom;
	CRect rectLower(CPoint(0, RoundDoubleToInt(dLowerRectH)), CPoint(RoundDoubleToInt(dLeftW), RoundDoubleToInt(iPaintH)));

	return rectLower;
}

// 從輸入的寬、高條件，定義右下角方塊
CRect LowerRightRect (CRect rectCenter, double dRightW, double iPaintH)
{
	double dLowerRectH = rectCenter.bottom;
	CRect rectLower(CPoint(RoundDoubleToInt(dRightW), RoundDoubleToInt(dLowerRectH)), CPoint(RoundDoubleToInt(dRightW) * 2, RoundDoubleToInt(iPaintH)));

	return rectLower;
}

// 傳回畫布中心圓軸的內切矩形
CRect BearingPos (double dRadius, double dBearingX, double dBearingY, int iPaintW, int iPaintH)
{
	CPoint ptX1Y1(RoundDoubleToInt((iPaintW * 0.5 + dBearingX) - dRadius), RoundDoubleToInt((iPaintH - dBearingY) - dRadius));
	CPoint ptX2Y2(RoundDoubleToInt((iPaintW * 0.5 + dBearingX) + dRadius), RoundDoubleToInt((iPaintH - dBearingY) + dRadius));
	CRect rectBearingPos(ptX1Y1, ptX2Y2);

	return rectBearingPos;
}

// 傳回左右側轉軸內切矩形
CRect LeftRightBearingPos(CPoint ptLeftRightBearingCenter)
{
	CPoint ptX1Y1(RoundDoubleToInt(ptLeftRightBearingCenter.x - 20), RoundDoubleToInt(ptLeftRightBearingCenter.y - 20));
	CPoint ptX2Y2(RoundDoubleToInt(ptLeftRightBearingCenter.x + 20), RoundDoubleToInt(ptLeftRightBearingCenter.y + 20));
	CRect rectLeftRightBearingPos(ptX1Y1, ptX2Y2);

	return rectLeftRightBearingPos;
}

// 傳回左右側滑塊內轉軸內切矩形
CRect LeftRightCenterBearingPos(CPoint ptLeftRightUpperCenter, double dLeftRightRectW, double dLeftRightRectLen)
{
	if (dLeftRightRectW > dLeftRightRectLen)
	{
		CPoint ptX1Y1(RoundDoubleToInt(ptLeftRightUpperCenter.x - 0.25 * dLeftRightRectLen), RoundDoubleToInt(ptLeftRightUpperCenter.y - 0.25 * dLeftRightRectLen));
		CPoint ptX2Y2(RoundDoubleToInt(ptLeftRightUpperCenter.x + 0.25 * dLeftRightRectLen), RoundDoubleToInt(ptLeftRightUpperCenter.y + 0.25 * dLeftRightRectLen));
		CRect rectLeftRightCenterBearingPos(ptX1Y1, ptX2Y2);

		return rectLeftRightCenterBearingPos;
	}
	else
	{
		CPoint ptX1Y1(RoundDoubleToInt(ptLeftRightUpperCenter.x - 0.25 * dLeftRightRectW), RoundDoubleToInt(ptLeftRightUpperCenter.y - 0.25 * dLeftRightRectW));
		CPoint ptX2Y2(RoundDoubleToInt(ptLeftRightUpperCenter.x + 0.25 * dLeftRightRectW), RoundDoubleToInt(ptLeftRightUpperCenter.y + 0.25 * dLeftRightRectW));
		CRect rectLeftRightCenterBearingPos(ptX1Y1, ptX2Y2);

		return rectLeftRightCenterBearingPos;
	}
}

// 傳回圓軸圓心座標
CPoint BearingCenter (CRect rectBearing)
{
	int iCenterX = RoundDoubleToInt((rectBearing.left + rectBearing.right) * 0.5);
	int iCenterY = RoundDoubleToInt((rectBearing.top + rectBearing.bottom) * 0.5);
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
CPoint LeftBearingCenter(double dLeftLeverRadius, double dLeftAng, CPoint ptBearingCenter)
{
	double dLeftRad = AngToRad(dLeftAng);
	double dPosX = (dLeftLeverRadius * cos(-dLeftRad) + ptBearingCenter.x);
	double dPosY = (dLeftLeverRadius * sin(-dLeftRad) + ptBearingCenter.y);
	CPoint ptLeftBearing(RoundDoubleToInt(dPosX), RoundDoubleToInt(dPosY));

	return ptLeftBearing;
}


// 傳回右側軸連接點座標
CPoint RightBearingCenter(double dRightLeverRadius, double dRightAng, CPoint ptBearingCenter)
{
	double dRightRad = AngToRad(dRightAng);
	double dPosX = (dRightLeverRadius * cos(-dRightRad) + ptBearingCenter.x);
	double dPosY = (dRightLeverRadius * sin(-dRightRad) + ptBearingCenter.y);
	CPoint ptRightBearing(RoundDoubleToInt(dPosX), RoundDoubleToInt(dPosY));

	return ptRightBearing;
}


// 傳回左側滑塊中心座標
CPoint LeftRectCenter (double dLeftLeverLen, double dLeftRectH, double dLeftRectLen, CPoint ptLeftBearingCenter, CPoint ptBearingCenter, int iPaintH)
{
	double dLeftRectCenterH = iPaintH - (dLeftRectH + dLeftRectLen);
	double dLeftRectCenterPosX = (ptLeftBearingCenter.x - sqrt(pow(dLeftLeverLen, 2) - pow((dLeftRectCenterH - ptLeftBearingCenter.y), 2)));
	CPoint ptLeftRectCenterPos(RoundDoubleToInt(dLeftRectCenterPosX), RoundDoubleToInt(dLeftRectCenterH));

	return ptLeftRectCenterPos;
}


// 傳回右側滑塊中心座標
CPoint RightRectCenter (double dRightLeverLen, double dRightRectH, double dRightRectLen, CPoint ptRightBearingCenter, CPoint ptBearingCenter, int iPaintH)
{
	double dRightRectCenterH = iPaintH - (dRightRectH + dRightRectLen);
	double dRightRectCenterPosX = (ptRightBearingCenter.x + sqrt(pow(dRightLeverLen, 2) - pow((dRightRectCenterH - ptRightBearingCenter.y), 2))); 
	CPoint ptRightRectCenterPos(RoundDoubleToInt(dRightRectCenterPosX), RoundDoubleToInt(dRightRectCenterH));

	return ptRightRectCenterPos;
}

// 開關樞紐輸入框
void CMFClinkagetestDlg::OpenOrCloseAllInputEdit(BOOL bTurnOn)
{
	m_editLeftRectLeverLen.EnableWindow(bTurnOn);
	m_editLeftRectH.EnableWindow(bTurnOn);
	m_editLeftRectLen.EnableWindow(bTurnOn);
	m_editLeftRectW.EnableWindow(bTurnOn);
	m_editRightRectLeverLen.EnableWindow(bTurnOn);
	m_editRightRectH.EnableWindow(bTurnOn);
	m_editRightRectLen.EnableWindow(bTurnOn);
	m_editRightRectW.EnableWindow(bTurnOn);
	m_editBearingRadius.EnableWindow(bTurnOn);
	m_editBearingPosX.EnableWindow(bTurnOn);
	m_editBearingPosY.EnableWindow(bTurnOn);
	m_editRightLeverRadius.EnableWindow(bTurnOn);
	m_editRightAng.EnableWindow(bTurnOn);
	m_editLeftLeverRadius.EnableWindow(bTurnOn);
	m_editLeftAng.EnableWindow(bTurnOn);
	m_editRPM.EnableWindow(bTurnOn);
	m_editAngAcc.EnableWindow(bTurnOn);
	m_editAngDec.EnableWindow(bTurnOn);
}

// 確認是否更改輸入的資料，有更改就更新資料
double CMFClinkagetestDlg::UpdateDoubleVariableIfChanged(CString strOld, CString strNew, double dMemberVariable)
{
	if (strOld != strNew)
	{
		dMemberVariable = _ttof(strNew);
		return dMemberVariable;
	}
	else
	{
		return dMemberVariable;
	}
}

CString CMFClinkagetestDlg::UpdateStringVariableIfChanged(CString strOld, CString strNew)
{
	if (strOld != strNew)
	{
		return strNew;
	}
	else
	{
		return strOld;
	}
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
		CDialogEx::OnPaint();

		// 取得畫布的長寬高
		CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
		CRect rectPaintRegion;

		pPaintRegion->GetClientRect(&rectPaintRegion);
		int iWidthPaintRegion = rectPaintRegion.Width();
		int iHeightPaintRegion = rectPaintRegion.Height();

		// 雙緩衝內存畫布設置
		CPaintDC dcO(pPaintRegion);
		CDC memDC;
		CBitmap memBitmap;

		memDC.CreateCompatibleDC(&dcO);
		memBitmap.CreateCompatibleBitmap(&dcO, rectPaintRegion.Width(), rectPaintRegion.Height());
		memDC.SelectObject(&memBitmap);

		// 在雙緩衝 DC 上進行繪圖
		DrawToBuffer(&memDC);

		// 將雙緩衝 DC 的內容複製到畫布上
		dcO.BitBlt(0, 0, rectPaintRegion.Width(), rectPaintRegion.Height(), &memDC, 0, 0, SRCCOPY);

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
	CBrush brushPaintRegion;
	CBrush* pOldBrushPaintRegion = pDC->SelectObject(&brushPaintRegion);

	brushPaintRegion.CreateSolidBrush(m_PaintRegionBackgroundColor);
	pDC->Rectangle(rectPaintRegion);
	pDC->FillRect(&rectPaintRegion, &brushPaintRegion);
	pDC->SelectObject(pOldBrushPaintRegion);

	// 定義邊界顏色並繪製
	CPen penLowerRectBoarder(PS_SOLID, m_iLowerRectBoarderW * 4, RGB(0, 0, 0));
	CPen penUpperRectBoarder(PS_SOLID, m_iUpperRectBoarderW * 2, RGB(0, 0, 0));
	CPen penBearingBoarder(PS_SOLID, m_iBearingBoarderW * 2, RGB(0, 0, 0));

	// 定義兩桿線段
	CPen penLever(PS_SOLID, 8, RGB(0, 0, 0));

	// 下方矩形顏色
	CBrush brushLowerRect;
	brushLowerRect.CreateSolidBrush(RGB(139, 69, 19));

	// 上方矩形顏色
	CBrush brushUpperRect;
	brushUpperRect.CreateSolidBrush(RGB(255, 255, 255));

	// 中心主轉軸顏色
	CBrush brushMainBearing;
	brushMainBearing.CreateSolidBrush(RGB(255, 0, 0));

	// 左右轉軸樞紐顏色
	CBrush brushLeftRightBearing;
	brushLeftRightBearing.CreateSolidBrush(RGB(0, 0, 255));

	// 將黑色邊界 UpperRectBoarderPen 選入 dc
	CPen* pOldPenUpperRectBoarder = pDC->SelectObject(&penUpperRectBoarder);

	// 將白色內部  UpperRectBrush 選入 dc
	CBrush* pOldBrushUpperRect = pDC->SelectObject(&brushUpperRect);

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
	CRect rectLeftUpper = CenterPtToRectPts(ptLeftUpperCenter, m_dLeftRectLen, m_dLeftRectW);

	pDC->Rectangle(rectLeftUpper);
	pDC->FillRect(&rectLeftUpper, &brushUpperRect);

	CRect rectRightUpper = CenterPtToRectPts(ptRightUpperCenter, m_dRightRectLen, m_dRightRectW);

	pDC->Rectangle(rectRightUpper);
	pDC->FillRect(&rectRightUpper, &brushUpperRect);
	pDC->SelectObject(pOldPenUpperRectBoarder);
	pDC->SelectObject(pOldBrushUpperRect);

	// 將黑色邊界  LowerRectBoarderPen 選入 dc
	CPen* pOldPenLowerRectBoarder = pDC->SelectObject(&penLowerRectBoarder);

	// 將棕色內部  LowerRectBrush 選入 dc
	CBrush* pOldBrushLowerRect = pDC->SelectObject(&brushLowerRect);

	// 定義左右下方方塊
	CRect rectLeftLower = LowerLeftRect(rectLeftUpper, m_dLowerRectW, iHeightPaintRegion);

	pDC->Rectangle(rectLeftLower);
	pDC->FillRect(&rectLeftLower, &brushLowerRect);

	CRect rectRightLower = LowerRightRect(rectRightUpper, m_dLowerRectW, iHeightPaintRegion);

	pDC->Rectangle(rectRightLower);
	pDC->FillRect(&rectRightLower, &brushLowerRect);
	pDC->SelectObject(pOldPenLowerRectBoarder);
	pDC->SelectObject(pOldBrushLowerRect);

	// 中心圓軸繪圖
	CPen* pOldPenBearingBoarder = pDC->SelectObject(&penBearingBoarder);
	CBrush* pOldBrushMainBearing =pDC->SelectObject(&brushMainBearing);

	pDC->Ellipse(rectBearingRect);
	pDC->SelectObject(pOldPenBearingBoarder);
	pDC->SelectObject(pOldBrushMainBearing);

	// 左右轉軸樞紐繪圖
	CBrush* pOldBrushLeftRightBearing = pDC->SelectObject(&brushLeftRightBearing);
	CRect rectLeftBearingRect = LeftRightBearingPos(ptLeftBearingCenter);
	CRect rectRightBearingRect = LeftRightBearingPos(ptRightBearingCenter);

	pDC->Ellipse(rectLeftBearingRect);
	pDC->Ellipse(rectRightBearingRect);
	pDC->SelectObject(pOldBrushLeftRightBearing);

	// 左右滑塊中心轉軸紐繪圖
	CBrush* pOldBrushLeftRightUpperCenterBearing = pDC->SelectObject(&brushLeftRightBearing);
	CRect rectLeftUpperCenterRect = LeftRightCenterBearingPos(ptLeftUpperCenter, m_dLeftRectW, m_dLeftRectLen);
	CRect rectRightUpperCenterRect = LeftRightCenterBearingPos(ptRightUpperCenter, m_dRightRectW, m_dRightRectLen);

	pDC->Ellipse(rectLeftUpperCenterRect);
	pDC->Ellipse(rectRightUpperCenterRect);
	pDC->SelectObject(pOldBrushLeftRightUpperCenterBearing);

	// 連桿繪圖
	CPen* pOldPenLever = pDC->SelectObject(&penLever);

	pDC->SetPixel(ptLeftBearingCenter, RGB(0, 0, 0));
	pDC->MoveTo(ptLeftBearingCenter);
	pDC->LineTo(ptLeftUpperCenter);
	pDC->SetPixel(ptRightBearingCenter, RGB(0, 0, 0));
	pDC->MoveTo(ptRightBearingCenter);
	pDC->LineTo(ptRightUpperCenter);
	pDC->SelectObject(pOldPenLever);

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
	UpdateData(TRUE);

	m_dLeftRectLeverLen = UpdateDoubleVariableIfChanged(m_strOldLeftRectLeverLen, m_strLeftRectLeverLen, m_dLeftRectLeverLen);
	m_dLeftRectH = UpdateDoubleVariableIfChanged(m_strOldLeftRectH, m_strLeftRectH, m_dLeftRectH);
	m_dLeftRectLen = UpdateDoubleVariableIfChanged(m_strOldLeftRectLen, m_strLeftRectLen, m_dLeftRectLen);
	m_dLeftRectW = UpdateDoubleVariableIfChanged(m_strOldLeftRectW, m_strLeftRectW, m_dLeftRectW);
	m_dRightRectLeverLen = UpdateDoubleVariableIfChanged(m_strOldRightRectLeverLen, m_strRightRectLeverLen, m_dRightRectLeverLen);
	m_dRightRectH = UpdateDoubleVariableIfChanged(m_strOldRightRectH, m_strRightRectH, m_dRightRectH);
	m_dRightRectLen = UpdateDoubleVariableIfChanged(m_strOldRightRectLen, m_strRightRectLen, m_dRightRectLen);
	m_dRightRectW = UpdateDoubleVariableIfChanged(m_strOldRightRectW, m_strRightRectW, m_dRightRectW);
	m_dBearingRadius = UpdateDoubleVariableIfChanged(m_strOldBearingRadius, m_strBearingRadius, m_dBearingRadius);
	m_dBearingPosX = UpdateDoubleVariableIfChanged(m_strOldBearingPosX, m_strBearingPosX, m_dBearingPosX);
	m_dBearingPosY = UpdateDoubleVariableIfChanged(m_strOldBearingPosY, m_strBearingPosY, m_dBearingPosY);
	m_dRightLeverRadius = UpdateDoubleVariableIfChanged(m_strOldRightLeverRadius, m_strRightLeverRadius, m_dRightLeverRadius);
	m_dRightAng = UpdateDoubleVariableIfChanged(m_strOldRightAng, m_strRightAng, m_dRightAng);
	m_dLeftLeverRadius = UpdateDoubleVariableIfChanged(m_strOldLeftLeverRadius, m_strLeftLeverRadius, m_dLeftLeverRadius);
	m_dLeftAng = UpdateDoubleVariableIfChanged(m_strOldLeftAng, m_strLeftAng, m_dLeftAng);
	m_dRPM = UpdateDoubleVariableIfChanged(m_strOldRPM, m_strRPM, m_dRPM);
	m_dAngAcc = UpdateDoubleVariableIfChanged(m_strOldAngAcc, m_strAngAcc, m_dAngAcc);
	m_dAngDec = UpdateDoubleVariableIfChanged(m_strOldAngDec, m_strAngDec, m_dAngDec);

	m_strOldLeftRectLeverLen = UpdateStringVariableIfChanged(m_strOldLeftRectLeverLen, m_strLeftRectLeverLen);
	m_strOldLeftRectH = UpdateStringVariableIfChanged(m_strOldLeftRectH, m_strLeftRectH);
	m_strOldLeftRectLen = UpdateStringVariableIfChanged(m_strOldLeftRectLen, m_strLeftRectLen);
	m_strOldLeftRectW = UpdateStringVariableIfChanged(m_strOldLeftRectW, m_strLeftRectW);
	m_strOldRightRectLeverLen = UpdateStringVariableIfChanged(m_strOldRightRectLeverLen, m_strRightRectLeverLen);
	m_strOldRightRectH = UpdateStringVariableIfChanged(m_strOldRightRectH, m_strRightRectH);
	m_strOldRightRectLen = UpdateStringVariableIfChanged(m_strOldRightRectLen, m_strRightRectLen);
	m_strOldRightRectW = UpdateStringVariableIfChanged(m_strOldRightRectW, m_strRightRectW);
	m_strOldBearingRadius = UpdateStringVariableIfChanged(m_strOldBearingRadius, m_strBearingRadius);
	m_strOldBearingPosX = UpdateStringVariableIfChanged(m_strOldBearingPosX, m_strBearingPosX);
	m_strOldBearingPosY = UpdateStringVariableIfChanged(m_strOldBearingPosY, m_strBearingPosY);
	m_strOldRightLeverRadius = UpdateStringVariableIfChanged(m_strOldRightLeverRadius, m_strRightLeverRadius);
	m_strOldRightAng = UpdateStringVariableIfChanged(m_strOldRightAng, m_strRightAng);
	m_strOldLeftLeverRadius = UpdateStringVariableIfChanged(m_strOldLeftLeverRadius, m_strLeftLeverRadius);
	m_strOldLeftAng = UpdateStringVariableIfChanged(m_strOldLeftAng, m_strLeftAng);
	m_strOldRPM = UpdateStringVariableIfChanged(m_strOldRPM, m_strRPM);
	m_strOldAngAcc = UpdateStringVariableIfChanged(m_strOldAngAcc, m_strAngAcc);
	m_strOldAngDec = UpdateStringVariableIfChanged(m_strOldAngDec, m_strAngDec);



	// Start 啟動後，關閉輸入框
	OpenOrCloseAllInputEdit(FALSE);

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
	//double dLeftRectSmallSide = sqrt(pow((m_dLeftRectLen * 0.5 + m_dLeftRectH), 2) + pow((m_dLeftRectLen + m_dLeftRectH), 2));
	//double dLeftClientMinLeverLen = m_dLeftRectLeverLen - m_dLeftLeverRadius - dLeftRectSmallSide;

	double dLeftRectSmallSide = sqrt(pow((0.5 * m_dLeftRectLen), 2) + pow((0.5 * m_dLeftRectW), 2));
	double dLeftClientMinLeverLen = m_dLeftRectLeverLen - m_dLeftLeverRadius - m_dBearingRadius - dLeftRectSmallSide;

	double dRightRectSmallSide = sqrt(pow((m_dRightRectLen * 0.5 + m_dRightRectH), 2) + pow((m_dRightRectLen + m_dRightRectH), 2));
	double dRightClientMinLeverLen = m_dRightRectLeverLen - m_dRightLeverRadius - dRightRectSmallSide;

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
	m_dTimePreviousSpan = 0;

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
	////////////////////////////////////////////////////////////////////////////////////////
	// 方塊個別資訊限制 (高、長、寬)
	//if ((m_dLeftRectH < 0) || (m_dRightRectH < 0))
	//{
	//	KillTimer(1);
	//	OpenOrCloseAllInputEdit(TRUE);
	//	g_bFirstStart = TRUE;
	//}

	//if ((m_dLeftRectLen <= 0) || (m_dRightRectLen <= 0))
	//{
	//	KillTimer(1);
	//	OpenOrCloseAllInputEdit(TRUE);
	//	g_bFirstStart = TRUE;
	//}

	//if ((m_dLeftRectW <= 0) || (m_dRightRectW <= 0))
	//{
	//	KillTimer(1);
	//	OpenOrCloseAllInputEdit(TRUE);
	//	g_bFirstStart = TRUE;
	//}
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////
	// 中心圓軸高度限制
	//if ((dBearingTopState <= 0) || (m_dBearingPosY < m_dBearingRadius) || (m_dBearingPosY > iHeightPaintRegion))
	//{
	//	KillTimer(1);
	//	OpenOrCloseAllInputEdit(TRUE);
	//	g_bFirstStart = TRUE;
	//}
	//// 中心圓軸
	//if ((dBearingLeftStateW <= 0) || (dBearingRightStateW <= 0))
	//{
	//	KillTimer(1);
	//	OpenOrCloseAllInputEdit(TRUE);
	//	g_bFirstStart = TRUE;
	//}
	//// 中心圓軸與左右側半徑限制
	//if ((m_dBearingRadius < m_dLeftLeverRadius + 20) || (m_dBearingRadius < m_dRightLeverRadius + 20))
	//{
	//	KillTimer(1);
	//	OpenOrCloseAllInputEdit(TRUE);
	//	g_bFirstStart = TRUE;
	//}
	//// 中心圓軸半徑
	//if (m_dBearingRadius <= 0)
	//{
	//	KillTimer(1);
	//	OpenOrCloseAllInputEdit(TRUE);
	//	g_bFirstStart = TRUE;
	//}
	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////

	g_bStartState = TRUE;
	g_bStopState = FALSE;
}


//按鈕 STOP
void CMFClinkagetestDlg::OnBnClickedButtonStop()
{
	// TODO: 在此加入控制項告知處理常式程式碼


	// 記錄停下的時間
	m_dStopNowRPM = abs(m_dNowRPM);

	// 初始化前一秒時間
	m_dTimePreviousSpan = 0;

	// 記錄按下 Stop 的時間
	m_dwStopTimeRecord = timeGetTime();

	// 關閉輸入框
	if ((g_bStopState == TRUE))
	{
		OpenOrCloseAllInputEdit(TRUE);
	}

	// 計算減速度區歷時時間長
	m_dDecTotalTime = m_dStopNowRPM / m_dAngDec;

	// 計算減速度區總面積
	m_dDecTotalAng = 0.5 * m_dStopNowRPM * m_dDecTotalTime;

	g_bStopState = TRUE;
	g_bStartState = FALSE;

}


// 每等間隔時間做的計算、變數更新
void CMFClinkagetestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	if (nIDEvent == 1)
	{
		DWORD dwCurrentTime = timeGetTime();

		// 判斷是否為按下 Stop 後
		if (g_bStopState == FALSE)
		{
			// 加速、等速區在此
			
			// 在 OnTimer 函數中計算經過的時間
			DWORD dwElapsedTime = dwCurrentTime - g_dwStartTime;

			// 將毫秒轉為秒
			double seconds = static_cast<double>(dwElapsedTime) / 1000.0;
			m_dTimeCurrentSpan = seconds;

			// 判斷是否還在加速度運動
			if (m_dTimeCurrentSpan <= m_dAcceTotalTime)
			{
				// 計算增加的旋轉角度
				m_dAddAng = 0.5 * RpmToAngVelocity(m_dAngAcc) * (pow(m_dTimeCurrentSpan, 2) - pow(m_dTimePreviousSpan, 2))
					+ RpmToAngVelocity(m_dStartNowRPM) * (m_dTimeCurrentSpan - m_dTimePreviousSpan);

				// 計算速度
				m_dNowRPM = m_dAngAcc * m_dTimeCurrentSpan + m_dStartNowRPM;

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
				m_dTimePreviousSpan = m_dTimeCurrentSpan;
			}
			else if ((m_dTimePreviousSpan < m_dAcceTotalTime) && (m_dTimeCurrentSpan > m_dAcceTotalTime))
			{	// 當下一秒加速超過最大等速度時角度的計算
				// 計算增加的旋轉角度
				m_dAddAng = 0.5 * RpmToAngVelocity(m_dAngAcc) * (pow(m_dAcceTotalTime, 2) - pow(m_dTimePreviousSpan, 2))
					+ abs(RpmToAngVelocity(m_dRPM)) * (m_dTimeCurrentSpan - m_dAcceTotalTime);

				// 當下速度為最大等速度值
				m_dNowRPM = m_dRPM;
				m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);

				// 將原本下一秒時間更新為前一秒
				m_dTimePreviousSpan = m_dTimeCurrentSpan;
			}
			else
			{	// 在等速度運動時的角度計算
				// 計算增加的旋轉角度
				m_dAddAng = abs(RpmToAngVelocity(m_dRPM)) * (m_dTimeCurrentSpan - m_dTimePreviousSpan);

				// 當下速度為最大等速度值
				m_dNowRPM = m_dRPM;
				m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);

				// 將原本下一秒時間更新為前一秒
				m_dTimePreviousSpan = m_dTimeCurrentSpan;
			}

			// 根據最大等速度值 (m_dRPM) 判斷增加的角度為順或逆時針增加
			if (m_dRPM < 0)
			{
				m_dLeftAng -= RadToAng(m_dAddAng);
				m_dRightAng -= RadToAng(m_dAddAng);
				m_dLeftAng = LimitTo360(m_dLeftAng);
				m_dRightAng = LimitTo360(m_dRightAng);
			}
			else
			{
				m_dLeftAng += RadToAng(m_dAddAng);
				m_dRightAng += RadToAng(m_dAddAng);
				m_dLeftAng = LimitTo360(m_dLeftAng);
				m_dRightAng = LimitTo360(m_dRightAng);
			}


		}
		else
		{
			// 減速區
			DWORD dwStopElapsedTime = dwCurrentTime - m_dwStopTimeRecord;

			// 將毫秒轉為秒
			double seconds = static_cast<double>(dwStopElapsedTime) / 1000.0;
			m_dTimeCurrentSpan = seconds;

			// 判斷是否還在減速度運動
			if (m_dTimeCurrentSpan <= m_dDecTotalTime)
			{
				// 計算減少的旋轉角度
				m_dReduceAng = RpmToAngVelocity(m_dStopNowRPM) * (m_dTimeCurrentSpan - m_dTimePreviousSpan)
					- (0.5 * RpmToAngVelocity(m_dAngDec) * (pow(m_dTimeCurrentSpan, 2) - pow(m_dTimePreviousSpan, 2)));

				// 計算速度
				m_dNowRPM = m_dStopNowRPM - m_dAngDec * m_dTimeCurrentSpan;

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
				m_dTimePreviousSpan = m_dTimeCurrentSpan;
			}
			else if ((m_dTimePreviousSpan <= m_dDecTotalTime) && (m_dTimeCurrentSpan > m_dDecTotalTime))
			{	// 當下一秒減速低過速度0時角度的計算
				// 計算減少的旋轉角度
				m_dReduceAng = pow((m_dDecTotalTime - m_dTimePreviousSpan), 2) * RpmToAngVelocity(m_dAngDec) * 0.5;

				// 當下速度為 0.0
				m_dNowRPM = 0.0;
				m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);

				// 將原本下一秒時間更新為前一秒
				m_dTimePreviousSpan = m_dTimeCurrentSpan;

				// 將第一次按下 Start 條件設為 FALSE
				g_bFirstStart = FALSE;
			}
			else
			{	// 速度為 0.0 
				m_dNowRPM = 0.0;
				m_strNowRPM.Format(_T(" % .7f"), m_dNowRPM);

				// 將原本下一秒時間更新為前一秒
				m_dTimePreviousSpan = m_dTimeCurrentSpan;

				// 將第一次按下 Start 條件設為 FALSE
				g_bFirstStart = FALSE;

			}

			// 根據最大等速度值 (m_dRPM) 判斷減少的角度為順或逆時針減少
			if (m_dRPM < 0)
			{
				m_dLeftAng -= RadToAng(m_dReduceAng);
				m_dRightAng -= RadToAng(m_dReduceAng);

				m_dLeftAng = LimitTo360(m_dLeftAng);
				m_dRightAng = LimitTo360(m_dRightAng);
			}
			else
			{
				m_dLeftAng += RadToAng(m_dReduceAng);
				m_dRightAng += RadToAng(m_dReduceAng);

				m_dLeftAng = LimitTo360(m_dLeftAng);
				m_dRightAng = LimitTo360(m_dRightAng);
			}

		}

		m_staticNowRPM.SetWindowText(m_strNowRPM);

		// 當速度為零時初始化前一秒記錄的時間並且重新計時
		if (m_dNowRPM == 0)
		{
			OpenOrCloseAllInputEdit(TRUE);
			m_dTimePreviousSpan = 0;
			KillTimer(1);
		}

		// 更新繪圖區
		CRect rectWindow;
		GetDlgItem(IDC_STATIC_PAINT)->GetWindowRect(&rectWindow);
		GetDlgItem(IDC_STATIC_PAINT)->GetParent()->ScreenToClient(rectWindow);
		InvalidateRect(&rectWindow, TRUE);
		UpdateWindow();
	}

	CDialogEx::OnTimer(1);
}



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
// 輸入資料限制警告設定區塊 : 


// 加速度限制條件
void CMFClinkagetestDlg::OnEnKillfocusEditAngularAcceleration()
{
	double dOldAngAcc = m_dAngAcc;
	CString strOrigin;

	UpdateData(TRUE);
	m_editAngAcc.GetWindowText(m_strAngAcc);
	m_dAngAcc = _ttof(m_strAngAcc);

	if (m_dAngAcc <= 0)
	{
		AfxMessageBox(_T("角加速度 > 0"));
		
		m_dAngAcc = dOldAngAcc;
		strOrigin.Format(_T("%.1f"), m_dAngAcc);

		GetDlgItem(IDC_EDIT_ANGULAR_ACCELERATION)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_ANGULAR_ACCELERATION)->SetFocus();
	}
}

// 減速度限制條件
void CMFClinkagetestDlg::OnEnKillfocusEditAngularDeceleration()
{
	double dOldAngDec = m_dAngDec;
	CString strOrigin;

	UpdateData(TRUE);
	m_editAngDec.GetWindowText(m_strAngDec);
	m_dAngDec = _ttof(m_strAngDec);

	if (m_dAngDec <= 0)
	{
		AfxMessageBox(_T("角減速度 > 0"));

		m_dAngDec = dOldAngDec;
		strOrigin.Format(_T("%.1f"), m_dAngDec);

		GetDlgItem(IDC_EDIT_ANGULAR_DECELERATION)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_ANGULAR_DECELERATION)->SetFocus();
	}
}


// 等速度限制條件
void CMFClinkagetestDlg::OnEnKillfocusEditRpm()
{
	double dOldRPM = m_dRPM;
	CString strOrigin;

	UpdateData(TRUE);
	m_editRPM.GetWindowText(m_strRPM);
	m_dRPM = _ttof(m_strRPM);

	if (m_dRPM == 0)
	{
		AfxMessageBox(_T(" RPM > 0 或 RPM < 0"));

		m_dRPM = dOldRPM;
		strOrigin.Format(_T("%.1f"), m_dRPM);

		GetDlgItem(IDC_EDIT_RPM)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_RPM)->SetFocus();
	}
}


// 左側滑塊限制條件
// 桿長
void CMFClinkagetestDlg::OnEnKillfocusEditLeftRecLever()
{
	double dOldLeftRectLeverLen = m_dLeftRectLeverLen;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;

	UpdateData(TRUE);
	m_editLeftRectLeverLen.SetWindowText(m_strLeftRectLeverLen);
	m_editLeftRectLen.SetWindowText(m_strLeftRectLen);
	m_editLeftRectH.SetWindowText(m_strLeftRectH);
	m_editLeftRectW.SetWindowText(m_strLeftRectW);
	m_editLeftLeverRadius.SetWindowText(m_strLeftLeverRadius);
	m_editBearingPosY.SetWindowText(m_strBearingPosY);
	m_editBearingRadius.SetWindowText(m_strBearingRadius);

	m_dLeftRectLeverLen = _ttof(m_strLeftRectLeverLen);
	m_dLeftRectLen = _ttof(m_strLeftRectLen);
	m_dLeftRectH = _ttof(m_strLeftRectH);
	m_dLeftRectW = _ttof(m_strLeftRectW);
	m_dLeftLeverRadius = _ttof(m_strLeftLeverRadius);
	m_dBearingPosY = _ttof(m_strBearingPosY);
	m_dBearingRadius = _ttof(m_strBearingRadius);

	double dLeftMaxLenY = m_dBearingPosY - (m_dLeftRectLen * 0.5 + m_dLeftRectH); // k
	double dLeftMaxLenX = m_dLowerRectW - 0.5 * m_dLeftRectW;
	double dLeftClientMaxLeverLen = sqrt(pow(dLeftMaxLenX, 2) + pow(dLeftMaxLenY, 2)) - m_dBearingRadius;
	strMaxConstraint.Format(_T("%.1f"), dLeftClientMaxLeverLen);

	double dLeftRectSmallSideY = m_dBearingPosY - (m_dLeftRectH + 0.5 * m_dLeftRectLen);
	double dLeftClientMinLeverLen = sqrt(pow((0.5 * m_dLeftRectW), 2) + pow(dLeftRectSmallSideY, 2)) + m_dLeftLeverRadius;
	strMinConstraint.Format(_T("%.1f"), dLeftClientMinLeverLen);

	if ((m_dLeftRectLeverLen >= dLeftClientMaxLeverLen) || (m_dLeftRectLeverLen <= dLeftClientMinLeverLen))
	{
		AfxMessageBox(_T("桿長 <= ") + strMaxConstraint + _T(" 或是 桿長 >= ") + strMinConstraint);

		m_dLeftRectLeverLen = dOldLeftRectLeverLen;
		strOrigin.Format(_T("%.1f"), m_dLeftRectLeverLen);

		GetDlgItem(IDC_EDIT_LEFT_REC_LEVER)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_LEFT_REC_LEVER)->SetFocus();
	}
}


// 滑塊高
void CMFClinkagetestDlg::OnEnKillfocusEditLeftRecHeight()
{
	double dOldLeftRectH = m_dLeftRectH;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editLeftRectH.GetWindowText(m_strLeftRectH);
	m_editLeftRectLen.GetWindowText(m_strLeftRectLen);

	m_dLeftRectH = _ttof(m_strLeftRectH);
	m_dLeftRectLen = _ttof(m_strLeftRectLen);

	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iHeightPaintRegion = rectPaintRegion.Height();

	double dMaxRectH = iHeightPaintRegion - m_dLeftRectLen;
	strMaxConstraint.Format(_T("%.1f"), dMaxRectH);

	double dMinRectH = 0.0;
	strMinConstraint.Format(_T("%.1f"), dMinRectH);

	if ((m_dLeftRectH > dMaxRectH) || (m_dLeftRectH < dMinRectH))
	{
		AfxMessageBox(_T("高度 <= ") + strMaxConstraint + _T(" 或是 高度 >= ") + strMinConstraint);

		m_dLeftRectH = dOldLeftRectH;
		strOrigin.Format(_T("%.1f"), m_dLeftRectH);

		GetDlgItem(IDC_EDIT_LEFT_REC_HEIGHT)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_LEFT_REC_HEIGHT)->SetFocus();
	}
}
 
// 滑塊長
void CMFClinkagetestDlg::OnEnKillfocusEditLeftRecLength()
{
	double dOldLeftRectLen = m_dLeftRectLen;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editLeftRectLen.GetWindowText(m_strLeftRectLen);
	m_editLeftRectH.GetWindowText(m_strLeftRectH);

	m_dLeftRectLen = _ttof(m_strLeftRectLen);
	m_dLeftRectH = _ttof(m_strLeftRectH);

	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iHeightPaintRegion = rectPaintRegion.Height();

	double dMaxRectLen = iHeightPaintRegion - m_dLeftRectH;
	strMaxConstraint.Format(_T("%.1f"), dMaxRectLen);

	double dMinRectLen = 0.0;
	strMinConstraint.Format(_T("%.1f"), dMinRectLen);

	if ((m_dLeftRectLen > dMaxRectLen) || (m_dLeftRectLen <= dMinRectLen))
	{
		AfxMessageBox(_T("長度 <= ") + strMaxConstraint + _T(" 或是 長度 > ") + strMinConstraint);

		m_dLeftRectLen = dOldLeftRectLen;
		strOrigin.Format(_T("%.1f"), m_dLeftRectLen);

		GetDlgItem(IDC_EDIT_LEFT_REC_LENGTH)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_LEFT_REC_LENGTH)->SetFocus();
	}
}


// 滑塊寬
void CMFClinkagetestDlg::OnEnKillfocusEditLeftRecWidth()
{
	double dOldLeftRectW = m_dLeftRectW;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editLeftRectW.GetWindowText(m_strLeftRectW);

	m_dLeftRectW = _ttof(m_strLeftRectW);

	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iWidthPaintRegion = rectPaintRegion.Width();

	double dMaxRectW = iWidthPaintRegion * 0.5;
	strMaxConstraint.Format(_T("%.1f"), dMaxRectW);

	double dMinRectW = 0.0;
	strMinConstraint.Format(_T("%.1f"), dMinRectW);

	if ((m_dLeftRectW >= dMaxRectW) || (m_dLeftRectW <= dMinRectW))
	{
		AfxMessageBox(_T("寬度 < ") + strMaxConstraint + _T(" 或是 寬度 > ") + strMinConstraint);

		m_dLeftRectW = dOldLeftRectW;
		strOrigin.Format(_T("%.1f"), m_dLeftRectW);

		GetDlgItem(IDC_EDIT_LEFT_REC_WIDTH)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_LEFT_REC_WIDTH)->SetFocus();
	}
}


// 左側滑塊限制條件
// 桿長
void CMFClinkagetestDlg::OnEnKillfocusEditRightRecLever()
{
	double dOldRightRectLeverLen = m_dRightRectLeverLen;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;

	UpdateData(TRUE);
	m_editRightRectLeverLen.SetWindowText(m_strRightRectLeverLen);
	m_editRightRectLen.SetWindowText(m_strRightRectLen);
	m_editRightRectH.SetWindowText(m_strRightRectH);
	m_editRightRectW.SetWindowText(m_strRightRectW);
	m_editRightLeverRadius.SetWindowText(m_strRightLeverRadius);
	m_editBearingPosY.SetWindowText(m_strBearingPosY);
	m_editBearingRadius.SetWindowText(m_strBearingRadius);

	m_dRightRectLeverLen = _ttof(m_strRightRectLeverLen);
	m_dRightRectLen = _ttof(m_strRightRectLen);
	m_dRightRectH = _ttof(m_strRightRectH);
	m_dRightRectW = _ttof(m_strRightRectW);
	m_dRightLeverRadius = _ttof(m_strRightLeverRadius);
	m_dBearingPosY = _ttof(m_strBearingPosY);
	m_dBearingRadius = _ttof(m_strBearingRadius);

	double dRightMaxLenY = m_dBearingPosY - (m_dRightRectLen * 0.5 + m_dRightRectH); // k
	double dRightMaxLenX = m_dLowerRectW - 0.5 * m_dLeftRectW;
	double dRightClientMaxLeverLen = sqrt(pow(dRightMaxLenX, 2) + pow(dRightMaxLenY, 2)) - m_dBearingRadius;
	strMaxConstraint.Format(_T("%.1f"), dRightClientMaxLeverLen);

	double dRightRectSmallSideY = m_dBearingPosY - (m_dRightRectH + 0.5 * m_dRightRectLen);
	double dRightClientMinLeverLen = sqrt(pow((0.5 * m_dRightRectW), 2) + pow(dRightRectSmallSideY, 2)) + m_dRightLeverRadius;
	strMinConstraint.Format(_T("%.1f"), dRightClientMinLeverLen);

	if ((m_dRightRectLeverLen >= dRightClientMaxLeverLen) || (m_dRightRectLeverLen <= dRightClientMinLeverLen))
	{
		AfxMessageBox(_T("桿長 <= ") + strMaxConstraint + _T(" 或是 桿長 >= ") + strMinConstraint);

		m_dRightRectLeverLen = dOldRightRectLeverLen;
		strOrigin.Format(_T("%.1f"), m_dRightRectLeverLen);

		GetDlgItem(IDC_EDIT_RIGHT_REC_LEVER)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_RIGHT_REC_LEVER)->SetFocus();
	}
}


// 滑塊高
void CMFClinkagetestDlg::OnEnKillfocusEditRightRecHeight()
{
	double dOldRightRectH = m_dRightRectH;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editRightRectH.GetWindowText(m_strRightRectH);
	m_editRightRectLen.GetWindowText(m_strRightRectLen);

	m_dRightRectH = _ttof(m_strRightRectH);
	m_dRightRectLen = _ttof(m_strRightRectLen);

	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iHeightPaintRegion = rectPaintRegion.Height();

	double dMaxRectH = iHeightPaintRegion - m_dRightRectLen;
	strMaxConstraint.Format(_T("%.1f"), dMaxRectH);

	double dMinRectH = 0.0;
	strMinConstraint.Format(_T("%.1f"), dMinRectH);

	if ((m_dRightRectH > dMaxRectH) || (m_dRightRectH < dMinRectH))
	{
		AfxMessageBox(_T("高度 <= ") + strMaxConstraint + _T(" 或是 高度 >= ") + strMinConstraint);

		m_dRightRectH = dOldRightRectH;
		strOrigin.Format(_T("%.1f"), m_dRightRectH);

		GetDlgItem(IDC_EDIT_RIGHT_REC_HEIGHT)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_RIGHT_REC_HEIGHT)->SetFocus();
	}
}


// 滑塊長
void CMFClinkagetestDlg::OnEnKillfocusEditRightRecLength()
{
	double dOldRightRectLen = m_dRightRectLen;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editRightRectLen.GetWindowText(m_strRightRectLen);
	m_editRightRectH.GetWindowText(m_strRightRectH);

	m_dRightRectLen = _ttof(m_strRightRectLen);
	m_dRightRectH = _ttof(m_strRightRectH);

	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iHeightPaintRegion = rectPaintRegion.Height();

	double dMaxRectLen = iHeightPaintRegion - m_dRightRectH;
	strMaxConstraint.Format(_T("%.1f"), dMaxRectLen);

	double dMinRectLen = 0.0;
	strMinConstraint.Format(_T("%.1f"), dMinRectLen);

	if ((m_dRightRectLen > dMaxRectLen) || (m_dRightRectLen <= dMinRectLen))
	{
		AfxMessageBox(_T("長度 <= ") + strMaxConstraint + _T(" 或是 長度 > ") + strMinConstraint);

		m_dRightRectLen = dOldRightRectLen;
		strOrigin.Format(_T("%.1f"), m_dRightRectLen);

		GetDlgItem(IDC_EDIT_RIGHT_REC_LENGTH)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_RIGHT_REC_LENGTH)->SetFocus();
	}
}


// 滑塊寬
void CMFClinkagetestDlg::OnEnKillfocusEditRightRecWidth()
{
	double dOldRightRectW = m_dRightRectW;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editRightRectW.GetWindowText(m_strRightRectW);

	m_dRightRectW = _ttof(m_strRightRectW);

	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iWidthPaintRegion = rectPaintRegion.Width();

	double dMaxRectW = iWidthPaintRegion * 0.5;
	strMaxConstraint.Format(_T("%.1f"), dMaxRectW);

	double dMinRectW = 0.0;
	strMinConstraint.Format(_T("%.1f"), dMinRectW);

	if ((m_dRightRectW >= dMaxRectW) || (m_dRightRectW <= dMinRectW))
	{
		AfxMessageBox(_T("寬度 < ") + strMaxConstraint + _T(" 或是 寬度 > ") + strMinConstraint);

		m_dRightRectW = dOldRightRectW;
		strOrigin.Format(_T("%.1f"), m_dRightRectW);

		GetDlgItem(IDC_EDIT_RIGHT_REC_WIDTH)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_RIGHT_REC_WIDTH)->SetFocus();
	}
}


// 中心圓軸半徑
void CMFClinkagetestDlg::OnEnKillfocusEditShaftRadius()
{
	double dOldBearingRadius = m_dBearingRadius;
	CString strOrigin;
	CString strMinLeftConstraint;
	CString strMinRightConstraint;
	CString strMaxConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editBearingRadius.GetWindowText(m_strBearingRadius);
	m_editLeftLeverRadius.GetWindowText(m_strLeftLeverRadius);
	m_editRightLeverRadius.GetWindowText(m_strRightLeverRadius);

	m_dBearingRadius = _ttof(m_strBearingRadius);
	m_dLeftLeverRadius = _ttof(m_strLeftLeverRadius);
	m_dRightLeverRadius = _ttof(m_strRightLeverRadius);

	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iHeightPaintRegion = rectPaintRegion.Height();

	double dMaxBearingRadius = 0.5 * iHeightPaintRegion;
	strMaxConstraint.Format(_T("%.1f"), dMaxBearingRadius);

	double dMinLeftBearingRadius = m_dLeftLeverRadius + 20;
	double dMinRightBearingRadius = m_dRightLeverRadius + 20;
	strMinLeftConstraint.Format(_T("%.1f"), dMinLeftBearingRadius);
	strMinRightConstraint.Format(_T("%.1f"), dMinRightBearingRadius);


	if ((m_dBearingRadius >= dMaxBearingRadius) || (m_dBearingRadius < dMinLeftBearingRadius))
	{
		AfxMessageBox(_T("半徑 < ") + strMaxConstraint + _T(" 或是 半徑 >= ") + strMinLeftConstraint);

		m_dBearingRadius = dOldBearingRadius;
		strOrigin.Format(_T("%.1f"), m_dBearingRadius);

		GetDlgItem(IDC_EDIT_SHAFT_RADIUS)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_SHAFT_RADIUS)->SetFocus();
	}
	
	if ((m_dBearingRadius >= dMaxBearingRadius) || (m_dBearingRadius < dMinRightBearingRadius))
	{
		AfxMessageBox(_T("半徑 < ") + strMaxConstraint + _T(" 或是 半徑 >= ") + strMinRightConstraint);

		m_dBearingRadius = dOldBearingRadius;
		strOrigin.Format(_T("%.1f"), m_dBearingRadius);

		GetDlgItem(IDC_EDIT_SHAFT_RADIUS)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_SHAFT_RADIUS)->SetFocus();
	}
}


// 中心圓軸 X 位置
void CMFClinkagetestDlg::OnEnKillfocusEditShaftXPos()
{
	double dOldBearingPosX = m_dBearingPosX;
	CString strOrigin;
	CString strMinConstraint;
	CString strMaxConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editBearingPosX.GetWindowText(m_strBearingPosX);
	m_editBearingRadius.GetWindowText(m_strBearingRadius);

	m_dBearingPosX = _ttof(m_strBearingPosX);
	m_dBearingRadius = _ttof(m_strBearingRadius);

	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iWidthPaintRegion = rectPaintRegion.Width();

	double dMaxBearingPosX = 0.5 * iWidthPaintRegion - m_dBearingRadius;
	strMaxConstraint.Format(_T("%.1f"), dMaxBearingPosX);

	double dMinBearingPosX = -0.5 * iWidthPaintRegion + m_dBearingRadius;
	strMinConstraint.Format(_T("%.1f"), dMinBearingPosX);

	if ((m_dBearingPosX > dMaxBearingPosX) || (m_dBearingPosX < dMinBearingPosX))
	{
		AfxMessageBox(_T("位置 X <= ") + strMaxConstraint + _T(" 或是 位置 X >= ") + strMinConstraint);

		m_dBearingPosX = dOldBearingPosX;
		strOrigin.Format(_T("%.1f"), m_dBearingPosX);

		GetDlgItem(IDC_EDIT_SHAFT_X_POS)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_SHAFT_X_POS)->SetFocus();
	}
}


// 中心圓軸 Y 位置
void CMFClinkagetestDlg::OnEnKillfocusEditShaftYPos()
{
	double dOldBearingPosY = m_dBearingPosY;
	CString strOrigin;
	CString strMinLeftConstraint;
	CString strMinRightConstraint;
	CString strMaxLeftConstraint;
	CString strMaxRightConstraint;
	CRect rectPaintRegion;

	UpdateData(TRUE);
	m_editBearingPosY.GetWindowText(m_strBearingPosY);
	m_editBearingRadius.GetWindowText(m_strBearingRadius);
	m_editLeftRectLeverLen.GetWindowText(m_strLeftRectLeverLen);
	m_editLeftLeverRadius.GetWindowText(m_strLeftLeverRadius);
	m_editRightLeverRadius.GetWindowText(m_strRightLeverRadius);
	m_editRightRectLeverLen.GetWindowText(m_strRightRectLeverLen);
	m_editLeftRectW.GetWindowText(m_strLeftRectW);
	m_editRightRectW.GetWindowText(m_strRightRectW);
	m_editLeftRectLen.GetWindowText(m_strLeftRectLen);
	m_editRightRectLen.GetWindowText(m_strRightRectLen);
	m_editLeftRectH.GetWindowText(m_strLeftRectH);
	m_editRightRectH.GetWindowText(m_strRightRectH);

	m_dBearingPosY = _ttof(m_strBearingPosY);
	m_dBearingRadius = _ttof(m_strBearingRadius);
	m_dLeftRectLeverLen = _ttof(m_strLeftRectLeverLen);
	m_dRightRectLeverLen = _ttof(m_strRightRectLeverLen);
	m_dLeftLeverRadius = _ttof(m_strLeftLeverRadius);
	m_dRightLeverRadius = _ttof(m_strRightLeverRadius);
	m_dLeftRectW = _ttof(m_strLeftRectW);
	m_dRightRectW = _ttof(m_strRightRectW);
	m_dLeftRectLen = _ttof(m_strLeftRectLen);
	m_dRightRectLen = _ttof(m_strRightRectLen);
	m_dLeftRectH = _ttof(m_strLeftRectH);
	m_dRightRectH = _ttof(m_strRightRectH);


	CWnd* pPaintRegion = GetDlgItem(IDC_STATIC_PAINT);
	pPaintRegion->GetClientRect(&rectPaintRegion);
	int iHeightPaintRegion = rectPaintRegion.Height();

	double dMaxBearingLeftPosY = sqrt(pow((m_dLeftRectLeverLen - m_dLeftLeverRadius), 2) - pow((0.5 * m_dLeftRectW), 2)) + 0.5 * m_dLeftRectLen + m_dLeftRectH;
	strMaxLeftConstraint.Format(_T("%.1f"), dMaxBearingLeftPosY);
	double dMaxBearingRightPosY = sqrt(pow((m_dRightRectLeverLen - m_dRightLeverRadius), 2) - pow((0.5 * m_dRightRectW), 2)) + 0.5 * m_dRightRectLen + m_dRightRectH;
	strMaxRightConstraint.Format(_T("%.1f"), dMaxBearingRightPosY);
	double dMinBearingLeftPosY = (m_dLeftRectLen + m_dLeftRectH) - sqrt(pow((m_dLeftRectLeverLen - m_dLeftLeverRadius), 2) - pow((0.5 * m_dLeftRectW), 2));
	strMinLeftConstraint.Format(_T("%.1f"), dMinBearingLeftPosY);
	double dMinBearingRightPosY = (m_dRightRectLen + m_dRightRectH) - sqrt(pow((m_dRightRectLeverLen - m_dRightLeverRadius), 2) - pow((0.5 * m_dRightRectW), 2));
	strMinRightConstraint.Format(_T("%.1f"), dMinBearingRightPosY);

	if ((m_dBearingPosY > dMaxBearingLeftPosY) || (m_dBearingPosY < dMinBearingLeftPosY))
	{
		AfxMessageBox(_T("位置 Y < ") + strMaxLeftConstraint + _T(" 或是 位置 Y > ") + strMinLeftConstraint);

		m_dBearingPosY = dOldBearingPosY;
		strOrigin.Format(_T("%.1f"), m_dBearingPosY);

		GetDlgItem(IDC_EDIT_SHAFT_Y_POS)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_SHAFT_Y_POS)->SetFocus();
	}
	else if ((m_dBearingPosY > dMaxBearingRightPosY) || (m_dBearingPosY < dMinBearingRightPosY))
	{
		AfxMessageBox(_T("位置 Y < ") + strMaxRightConstraint + _T(" 或是 位置 Y > ") + strMinRightConstraint);

		m_dBearingPosY = dOldBearingPosY;
		strOrigin.Format(_T("%.1f"), m_dBearingPosY);

		GetDlgItem(IDC_EDIT_SHAFT_Y_POS)->SetWindowText(strOrigin);
		GetDlgItem(IDC_EDIT_SHAFT_Y_POS)->SetFocus();
	}
}
