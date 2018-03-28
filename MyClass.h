#pragma once

//自定义消息，消息映射位于demoCtrl.cpp
#define WM_BUTTONCLICK1 WM_USER+1


// CMyClass 对话框

class CMyClass : public CDialogEx
{
	DECLARE_DYNAMIC(CMyClass)

public:
	CMyClass(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyClass();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void setText();
};
