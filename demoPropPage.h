#pragma once

// demoPropPage.h : CdemoPropPage ����ҳ���������


// CdemoPropPage : �й�ʵ�ֵ���Ϣ������� demoPropPage.cpp��

class CdemoPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CdemoPropPage)
	DECLARE_OLECREATE_EX(CdemoPropPage)

// ���캯��
public:
	CdemoPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_DEMO };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

