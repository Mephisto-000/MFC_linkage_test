
// MFC_linkage_testDlg.h: 標頭檔
//

#define _USE_MATH_DEFINES
#include <cmath>
#include <mmsystem.h>                                   // 包含 timeGetTime 函數的標頭

#pragma once

// 加入 mmysystem.h 中的 timeGetTime 時需加入以下連接庫
#pragma comment(lib, "winmm.lib ")                     // 參看 : https://blog.csdn.net/dragoo1/article/details/123557730


// CMFClinkagetestDlg 對話方塊
class CMFClinkagetestDlg : public CDialogEx
{
// 建構
public:
	CMFClinkagetestDlg(CWnd* pParent = nullptr);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_LINKAGE_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	COLORREF m_PaintRegionBackgroundColor;              // 上方繪圖區背景顏色設定

	
	// 用 timeGetTime 方法
	// 代替 OnTimer, SetTimer, KillTimer



public:
	afx_msg void OnStnClickedStaticPaint();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();


	//////////////////////////////////// 輸入的資料變數 ////////////////////////////////////
	//左側滑塊區
	CString m_strLeftRectLeverLen = _T("");             // 左側連桿長度
	CString m_strLeftRectH = _T("");                    // 左側滑塊高度
	CString m_strLeftRectLen = _T("");                  // 左側滑塊長度 (縱軸方向)
	CString m_strLeftRectW = _T("");                    // 左側滑塊寬度 (橫軸方向)

	//右側滑塊區
	CString m_strRightRectLeverLen = _T("");            // 右側連桿長度
	CString m_strRightRectH = _T("");                   // 右側滑塊高度
	CString m_strRightRectLen = _T("");                 // 右側滑塊長度 (縱軸方向)
	CString m_strRightRectW = _T("");                   // 右側滑塊寬度 (橫軸方向)
	
	// 中心圓軸區
	CString m_strBearingRadius = _T("");                // 中心圓軸半徑
	CString m_strBearingPosX = _T("");                  // 中心圓軸 X 位置
	CString m_strBearingPosY = _T("");                  // 中心圓軸 Y 位置
	CString m_strRightLeverRadius = _T("");             // 右側軸半徑 (中心圓軸圓心到右側連桿連接點的距離)
	CString m_strRightAng = _T("");                     // 右側軸角度 (右側軸與中心圓軸的水平半徑之間的夾角)
	CString m_strLeftLeverRadius = _T("");              // 左側軸半徑 (中心圓軸圓心到左側連桿連接點的距離)
	CString m_strLeftAng = _T("");                      // 左側軸角度 (左側軸與中心圓軸的水平半徑之間的夾角)
	CString m_strRPM = _T("");                          // 每秒圈數
	CString m_strAngAcc = _T("");                       // 角加速度
	CString m_strAngDec = _T("");                       // 角減速度

	// 左側滑塊區
	double m_dLeftRectLeverLen = 0.0;                   // 左側連桿長度
	double m_dLeftRectH = 0.0;							// 左側滑塊高度
	double m_dLeftRectLen = 0.0;						// 左側滑塊長度 (縱軸方向)
	double m_dLeftRectW = 0.0;							// 左側滑塊寬度 (橫軸方向)

	// 右側滑塊區
	double m_dRightRectLeverLen = 0.0;                  // 右側連桿長度
	double m_dRightRectH = 0.0;							// 右側滑塊高度
	double m_dRightRectLen = 0.0;						// 右側滑塊長度 (縱軸方向)
	double m_dRightRectW = 0.0;							// 右側滑塊寬度 (橫軸方向)

	// 中心圓軸區
	double m_dBearingRadius = 0.0;                      // 中心圓軸半徑
	double m_dBearingPosX = 0.0;						// 中心圓軸 X 位置 (X 軸為繪圖區中線)
	double m_dBearingPosY = 0.0;						// 中心圓軸 Y 位置 (Y 軸為繪圖區底邊)
	double m_dRightLeverRadius = 0.0;					// 右側軸半徑 (中心圓軸圓心到右側連桿連接點的距離)
	double m_dRightAng = 0.0;							// 右側軸角度 (右側軸與中心圓軸的水平半徑之間的夾角)
	double m_dLeftLeverRadius = 0.0;					// 左側軸半徑 (中心圓軸圓心到左側連桿連接點的距離)
	double m_dLeftAng = 0.0;							// 左側軸角度 (左側軸與中心圓軸的水平半徑之間的夾角)
	double m_dRPM = 0.0;								// 每秒圈數
	double m_dAngAcc = 0.0;								// 角加速度
	double m_dAngDec = 0.0;								// 角減速度

	/////////////////////////////////////// 其他定義變數 ///////////////////////////////////


	double m_dLowerRectW = 0.0;                         // 左右下方方塊寬度 (橫軸方向)

	int m_iLowerRectBoarderW = 1;                       // 左右底部方塊邊寬
	int m_iUpperRectBoarderW = 1;						// 左右上方滑塊邊寬
	int m_iBearingBoarderW = 1;							// 中心圓軸邊寬

	CPoint m_ptLeftUpperCenterPos = (0, 0);		        // 左上方滑塊中心點座標
	CPoint m_ptRightUpperCenterPos = (0, 0);			// 右上方滑塊中心點座標
	CPoint m_ptBearingCenterPos = (0, 0);				//  中心圓軸中心點座標

	double m_dAcceTotalAng = 0.0;                       // 加速度區總面積
	double m_dAcceTotalTime = 0.0;                      // 加速度區塊歷時時間
	double m_dTimeAfter = 0.0;							// 記錄下一秒累積時間長
	double m_dTimeBefore = 0.0;                         // 記錄前一秒累積時間長
	double m_dAddAng = 0.0;								// 記錄下一秒要增加的角度
	double m_dMaxAddAng = 0.0;                          // 記錄最大增加角度                        
	double m_dStopNowRPM = 0.0;							// 記錄按下 STOP 當下速度
	double m_dStartNowVelocity = 0.0;                   // 記錄按下 START 當下速度

	double m_dDecTotalAng = 0.0;                        // 減速度總面積
	double m_dDecTotalTime = 0.0;						// 減速度區塊歷時時間
	double m_dReduceAng = 0.0;                          // 記錄下一秒要減少的角度
	DWORD m_dwStopTimeRecord = 0;                       // 記錄按下 STOP 的時間點

	double m_dNowRPM = 0.0;                             // 記錄當下轉速
	CString m_strNowRPM = _T("");                       // 記錄當下轉速

	////////////////////////////////////////////////////////////////////////////////////////
	// 個數值設定控制項:	
	CEdit m_editLeftRectLever;							// 左側連桿長度
	CEdit m_editLeftRectH;								// 左側滑塊高度
	CEdit m_editLeftRectLen;							// 左側滑塊長度 (縱軸方向)
	CEdit m_editLeftRectW;								// 左側滑塊寬度 (橫軸方向)
	CEdit m_editRightRectLever;							// 右側連桿長度
	CEdit m_editRightRectH;								// 右側滑塊高度
	CEdit m_editRightRectLen;							// 右側滑塊長度 (縱軸方向)
	CEdit m_editRightRectW;								// 右側滑塊寬度 (橫軸方向)
	CEdit m_editBearingRadius;							// 中心圓軸半徑
	CEdit m_editBearingPosX;							// 中心圓軸 X 位置 (X 軸為繪圖區中線)
	CEdit m_editBearingPosY;							// 中心圓軸 Y 位置 (Y 軸為繪圖區底邊)
	CEdit m_editRightLeverRadius;						// 右側軸半徑 (中心圓軸圓心到右側連桿連接點的距離)
	CEdit m_editRightAng;								// 右側軸角度 (右側軸與中心圓軸的水平半徑之間的夾角
	CEdit m_editLeftLeverRadius;						// 左側軸半徑 (中心圓軸圓心到左側連桿連接點的距離)
	CEdit m_editLeftAng;								// 左側軸角度 (左側軸與中心圓軸的水平半徑之間的夾角
	CEdit m_editRPM;									// 每秒圈數
	CEdit m_editAngAcc;									// 角加速度
	CEdit m_editAngDec;									// 角減速度
	afx_msg void OnTimer(UINT_PTR nIDEvent);			// 計時函數
	afx_msg void DrawToBuffer(CDC* pDC);				// 雙緩衝更新區域函數


	CStatic m_staticNowRPM;                             // 顯示當下轉速
};
