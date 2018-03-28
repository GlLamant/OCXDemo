// MyClass.cpp : 实现文件
//

#include "stdafx.h"
#include "demo.h"
#include "MyClass.h"
#include "afxdialogex.h"


// CMyClass 对话框

IMPLEMENT_DYNAMIC(CMyClass, CDialogEx)

CMyClass::CMyClass(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAIN, pParent)
{

}

CMyClass::~CMyClass()
{
}

void CMyClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CMyClass::setText()
{
	SetDlgItemText(IDC_EDIT1, _T("just test"));
}


BEGIN_MESSAGE_MAP(CMyClass, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyClass::OnBnClickedButton1)
//	ON_MESSAGE(BUTTONCLICK, &CMyClass::OnButtonclick)
END_MESSAGE_MAP()


// CMyClass 消息处理程序


void CMyClass::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	::SendMessage(this->GetParent()->m_hWnd, WM_BUTTONCLICK1, 0, 0);		//此处是button的点击响应函数，设置发送 WM_BUTTONCLICK1 消息到 demoCtrl.cpp
}
