#pragma once

//�Զ�����Ϣ����Ϣӳ��λ��demoCtrl.cpp
#define WM_BUTTONCLICK1 WM_USER+1


// CMyClass �Ի���

class CMyClass : public CDialogEx
{
	DECLARE_DYNAMIC(CMyClass)

public:
	CMyClass(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyClass();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void setText();
};
