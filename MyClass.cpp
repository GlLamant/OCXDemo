// MyClass.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demo.h"
#include "MyClass.h"
#include "afxdialogex.h"


// CMyClass �Ի���

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


// CMyClass ��Ϣ�������


void CMyClass::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	::SendMessage(this->GetParent()->m_hWnd, WM_BUTTONCLICK1, 0, 0);		//�˴���button�ĵ����Ӧ���������÷��� WM_BUTTONCLICK1 ��Ϣ�� demoCtrl.cpp
}
