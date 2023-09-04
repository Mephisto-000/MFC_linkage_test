
// MFC_linkage_testDlg.h: 標頭檔
//

#define _USE_MATH_DEFINES
#include <cmath>
#include <mmsystem.h>                                   // 包含 timeGetTime 函數的標頭

#pragma once

// 加入 mmysystem.h 中的 timeGetTime 時需加入以下連接庫
// "winmm.lib" 是 Windows Multimedia API
#pragma comment(lib, "winmm.lib ")


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

	COLORREF m_PaintRegionBackgroundColor = RGB(0, 0, 0);;              // 上方繪圖區背景顏色設定

public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();

	void OpenOrCloseAllInputEdit(BOOL bTurnOn);
	double UpdateDoubleVariableIfChanged(CString strOld, CString strNew, double dMemberVariable);
	CString UpdateStringVariableIfChanged(CString strOld, CString strNew);

	//////////////////////////////////// 輸入的資料變數 ////////////////////////////////////
	//左側滑塊區
	CString m_strLeftRectLeverLen;                      // 左側連桿長度
	CString m_strLeftRectH;                             // 左側滑塊高度
	CString m_strLeftRectLen;                           // 左側滑塊長度 (縱軸方向)
	CString m_strLeftRectW;                             // 左側滑塊寬度 (橫軸方向)

	//右側滑塊區
	CString m_strRightRectLeverLen;                     // 右側連桿長度
	CString m_strRightRectH;                            // 右側滑塊高度
	CString m_strRightRectLen;                          // 右側滑塊長度 (縱軸方向)
	CString m_strRightRectW;                            // 右側滑塊寬度 (橫軸方向)
	
	// 中心圓軸區
	CString m_strBearingRadius;                         // 中心圓軸半徑
	CString m_strBearingPosX;                           // 中心圓軸 X 位置
	CString m_strBearingPosY;                           // 中心圓軸 Y 位置
	CString m_strRightLeverRadius;                      // 右側軸半徑 (中心圓軸圓心到右側連桿連接點的距離)
	CString m_strRightAng;                              // 右側軸角度 (右側軸與中心圓軸的水平半徑之間的夾角)
	CString m_strLeftLeverRadius;                       // 左側軸半徑 (中心圓軸圓心到左側連桿連接點的距離)
	CString m_strLeftAng;                               // 左側軸角度 (左側軸與中心圓軸的水平半徑之間的夾角)
	CString m_strRPM;                                   // 每秒圈數
	CString m_strAngAcc;                                // 角加速度
	CString m_strAngDec;                                // 角減速度

	CString m_strOldLeftRectLeverLen;
	CString m_strOldLeftRectH;
	CString m_strOldLeftRectLen;
	CString m_strOldLeftRectW;
	CString m_strOldRightRectLeverLen;
	CString m_strOldRightRectH;
	CString m_strOldRightRectLen;
	CString m_strOldRightRectW;
	CString m_strOldBearingRadius;
	CString m_strOldBearingPosX;
	CString m_strOldBearingPosY;
	CString m_strOldRightLeverRadius;
	CString m_strOldRightAng;
	CString m_strOldLeftLeverRadius;
	CString m_strOldLeftAng;
	CString m_strOldRPM;
	CString m_strOldAngAcc;
	CString m_strOldAngDec;

	// 左側滑塊區
	double m_dLeftRectLeverLen;								// 左側連桿長度
	double m_dLeftRectH;      								// 左側滑塊高度
	double m_dLeftRectLen;      							// 左側滑塊長度 (縱軸方向)
	double m_dLeftRectW;    								// 左側滑塊寬度 (橫軸方向)

	// 右側滑塊區
	double m_dRightRectLeverLen;							// 右側連桿長度
	double m_dRightRectH;    								// 右側滑塊高度
	double m_dRightRectLen;     							// 右側滑塊長度 (縱軸方向)
	double m_dRightRectW;    								// 右側滑塊寬度 (橫軸方向)

	// 中心圓軸區
	double m_dBearingRadius;								// 中心圓軸半徑
	double m_dBearingPosX;      							// 中心圓軸 X 位置 (X 軸為繪圖區中線)
	double m_dBearingPosY;      							// 中心圓軸 Y 位置 (Y 軸為繪圖區底邊)
	double m_dRightLeverRadius;     						// 右側軸半徑 (中心圓軸圓心到右側連桿連接點的距離)
	double m_dRightAng;     								// 右側軸角度 (右側軸與中心圓軸的水平半徑之間的夾角)
	double m_dLeftLeverRadius;      						// 左側軸半徑 (中心圓軸圓心到左側連桿連接點的距離)
	double m_dLeftAng;      								// 左側軸角度 (左側軸與中心圓軸的水平半徑之間的夾角)
	double m_dRPM;      									// 每秒圈數
	double m_dAngAcc;     									// 角加速度
	double m_dAngDec;   									// 角減速度

	/////////////////////////////////////// 其他定義變數 ///////////////////////////////////


	double m_dLowerRectW;									// 左右下方方塊寬度 (橫軸方向)

	int m_iLowerRectBoarderW;								// 左右底部方塊邊寬
	int m_iUpperRectBoarderW;   							// 左右上方滑塊邊寬
	int m_iBearingBoarderW; 								// 中心圓軸邊寬

	CPoint m_ptLeftUpperCenterPos;      					// 左上方滑塊中心點座標
	CPoint m_ptRightUpperCenterPos;         				// 右上方滑塊中心點座標
	CPoint m_ptBearingCenterPos;         					//  中心圓軸中心點座標

	double m_dAcceTotalAng;									// 加速度區總面積
	double m_dAcceTotalTime;								// 加速度區塊歷時時間
	double m_dTimeCurrentSpan;      						// 記錄下一秒累積時間長
	double m_dTimePreviousSpan;								// 記錄前一秒累積時間長
	double m_dAddAng;    									// 記錄下一秒要增加的角度
	double m_dMaxAddAng;									// 記錄最大增加角度                        
	double m_dStopNowRPM;   								// 記錄按下 STOP 當下速度
	double m_dStartNowRPM;									// 記錄按下 START 當下速度

	double m_dDecTotalAng;									// 減速度總面積
	double m_dDecTotalTime;      							// 減速度區塊歷時時間
	double m_dReduceAng;									// 記錄下一秒要減少的角度
	DWORD m_dwStopTimeRecord;								// 記錄按下 STOP 的時間點

	double m_dNowRPM;										// 記錄當下轉速
	CString m_strNowRPM;									// 記錄當下轉速

	////////////////////////////////////////////////////////////////////////////////////////
	// 個數值設定控制項:	
	CEdit m_editLeftRectLeverLen;							// 左側連桿長度
	CEdit m_editLeftRectH;									// 左側滑塊高度
	CEdit m_editLeftRectLen;								// 左側滑塊長度 (縱軸方向)
	CEdit m_editLeftRectW;									// 左側滑塊寬度 (橫軸方向)
	CEdit m_editRightRectLeverLen;							// 右側連桿長度
	CEdit m_editRightRectH;									// 右側滑塊高度
	CEdit m_editRightRectLen;								// 右側滑塊長度 (縱軸方向)
	CEdit m_editRightRectW;									// 右側滑塊寬度 (橫軸方向)
	CEdit m_editBearingRadius;								// 中心圓軸半徑
	CEdit m_editBearingPosX;								// 中心圓軸 X 位置 (X 軸為繪圖區中線)
	CEdit m_editBearingPosY;								// 中心圓軸 Y 位置 (Y 軸為繪圖區底邊)
	CEdit m_editRightLeverRadius;							// 右側軸半徑 (中心圓軸圓心到右側連桿連接點的距離)
	CEdit m_editRightAng;									// 右側軸角度 (右側軸與中心圓軸的水平半徑之間的夾角
	CEdit m_editLeftLeverRadius;							// 左側軸半徑 (中心圓軸圓心到左側連桿連接點的距離)
	CEdit m_editLeftAng;									// 左側軸角度 (左側軸與中心圓軸的水平半徑之間的夾角
	CEdit m_editRPM;										// 每秒圈數
	CEdit m_editAngAcc;										// 角加速度
	CEdit m_editAngDec;										// 角減速度
	afx_msg void OnTimer(UINT_PTR nIDEvent);				// 計時函數
	afx_msg void DrawToBuffer(CDC* pDC);					// 雙緩衝更新區域函數


	CStatic m_staticNowRPM;									// 顯示當下轉速

	////////////////////////////////////////////////////////////////////////////////////////
	// 輸入資料限制警告設定區塊:
	afx_msg void OnEnKillfocusEditAngularAcceleration();    // 加速度限制警告
	afx_msg void OnEnKillfocusEditAngularDeceleration();    // 減速度限制警告
	afx_msg void OnEnKillfocusEditRpm();                    // 等速度限制警告
	afx_msg void OnEnKillfocusEditLeftRecLever();           // 左滑塊長度限制警告
	afx_msg void OnEnKillfocusEditLeftRecHeight();          // 左邊滑塊高度限制警告
	afx_msg void OnEnKillfocusEditLeftRecLength();          // 左邊滑塊長限制警告
};
